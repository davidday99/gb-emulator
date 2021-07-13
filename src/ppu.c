#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"
#include "../include/ppu.h"

#define NUM_PIXELS_V 144
#define NUM_PIXELS_H 160

#define PRIORITY_MASK 0x80
#define Y_FLIP_MASK 0x40
#define X_FLIP_MASK 0x20
#define PALETTE_NUM_MASK 0x10
#define OAM_ENTRIES 40

void init_ppu(PPU *ppu, CPU *cpu) {
    ppu->interrupt_flag_register = &cpu->RAM[IF_REGISTER];
    ppu->control = &cpu->RAM[LCDC_REGISTER];
    ppu->status = &cpu->RAM[STAT_REGISTER];
    ppu->scy = &cpu->RAM[SCY_REGISTER];
    ppu->scx = &cpu->RAM[SCX_REGISTER];
    ppu->ly = &cpu->RAM[LY_REGISTER];
    ppu->lyc = &cpu->RAM[LYC_REGISTER];
    ppu->dma_start = &cpu->RAM[DMA_REGISTER];
    ppu->bgp = &cpu->RAM[BGP_REGISTER];
    ppu->obp0 = &cpu->RAM[OBP0_REGISTER];
    ppu->obp1 = &cpu->RAM[OBP1_REGISTER];
    ppu->wy = &cpu->RAM[WY_REGISTER];
    ppu->wx = &cpu->RAM[WX_REGISTER];
    ppu->vram = cpu->RAM;
    ppu->oam = &cpu->RAM[OAM_ADDRESS];
    ppu->CYCLE_COUNT = 0;

    ppu->buffer = (uint8_t**) calloc(sizeof(uint8_t*), NUM_PIXELS_V);
    for (uint16_t i; i < NUM_PIXELS_H; i++) {
        ppu->buffer[i] = (uint8_t*) calloc(sizeof(uint8_t), NUM_PIXELS_H);
    }
}

int16_t get_tile_number(PPU *ppu, uint8_t *tile_disp_select_addr, uint8_t row, uint8_t tile) {
    uint16_t offset = (row * 32) + tile;
    uint8_t tile_num = *(tile_disp_select_addr + offset);

    /* interpret as signed if LCDC[4] == 1 */
    if (*ppu->control & BG_WINDOW_TILE_DATA_SELECT_MASK) {
        tile_num = (int8_t) tile_num;
    }
    return (int16_t) tile_num;
}

uint8_t* get_tile_address(PPU *ppu, int16_t tile_num) {
    return ppu->vram + tile_num;
}

uint8_t get_pixel_color(uint8_t *tile_addr, uint8_t row, uint8_t pixel) {
    uint8_t pixel_mask = 1 << (7 - pixel);
    uint8_t color;
    row %= 8;
    tile_addr += row;

    color |= (*tile_addr & pixel_mask) >> (7 - pixel); // get LSB
    color |= (*(tile_addr + 1) & pixel_mask) >> (8 - pixel); // get MSB

    return color;
}

uint8_t get_bgp_color(PPU *ppu, uint8_t color) {
    uint8_t new_color = 0;
    switch (color) {
        case 0:
            new_color = *ppu->bgp & 3;
            break;
        case 1:
            new_color = (*ppu->bgp & 12) >> 2;
            break;
        case 2:
            new_color = (*ppu->bgp & 48) >> 4;
            break;
        case 3:
            new_color = (*ppu->bgp & 192) >> 6;
            break;
        default:
            break;
    }
    return new_color;
}

void draw_background(PPU *ppu) {
    uint16_t tile_disp_select = (*ppu->control & BG_TILE_MAP_DISP_SELECT_MASK ) == 0 ? 0x9800 : 0x9C00;
    uint8_t scx_offset = *ppu->scx / 8;
    uint8_t scy_offset = *ppu->scy * 32;
    uint8_t pixel_offset = *ppu->scx % 8;

    for (uint8_t tile = 0; tile < 20; tile++) {
        uint16_t tile_num = ppu->vram[tile_disp_select + ((*ppu->ly / 8) * 32) + tile];

        tile_num += scx_offset;
        tile_num += scy_offset;

        tile_num *= 16;

        uint16_t tile_addr = (*ppu->control & BG_WINDOW_TILE_DATA_SELECT_MASK) == 0 ? 0x8800 : 0x8000;

        if (tile_addr == 0x8800) {
            tile_addr += (int8_t) tile_num;
        } else {
            tile_addr += tile_num;
        }

        tile_addr += (*ppu->ly % 8) * 2;

        uint8_t low = ppu->vram[tile_addr];
        uint8_t high = ppu->vram[tile_addr + 1];
        uint8_t pixel;

        if (tile == 0 && pixel_offset != 0)
            pixel = pixel_offset;
        else
            pixel = 0;

        for (; pixel < 8; pixel++) {
            uint8_t mask = 1 << (7 - pixel);
            uint8_t color;
            if (pixel == 7) {
                color = (low & mask) | ((high & mask) << 1);
            } else {
                color = ((low & mask) >> (7 - pixel)) | ((high & mask) >> (7 - (pixel + 1)));
            }
            ppu->buffer[*ppu->ly][(tile * 8) + pixel - pixel_offset] = get_bgp_color(ppu, color);
        }
    }

    // if SCROLLX % 8 != 0, we need to fetch extra pixels from one extra tile
    if (pixel_offset != 0) {
        uint16_t tile_num = ppu->vram[tile_disp_select + ((*ppu->ly / 8) * 32) + 20];
        tile_num += scx_offset;

        tile_num *= 16;

        uint16_t tile_addr = (*ppu->control & BG_WINDOW_TILE_DATA_SELECT_MASK) == 0 ? 0x8800 : 0x8000;

        if (tile_addr == 0x8800) {
            tile_addr += (int8_t) tile_num;
        } else {
            tile_addr += tile_num;
        }

        tile_addr += (*ppu->ly % 8) * 2;

        uint8_t low = ppu->vram[tile_addr];
        uint8_t high = ppu->vram[tile_addr + 1];
        uint8_t pixel_condition = 8 - pixel_offset;

        for (uint8_t pixel = 0; pixel < pixel_condition; pixel++) {
            uint8_t mask = 1 << (7 - pixel);
            uint8_t color;

            color = ((low & mask) >> (7 - pixel)) | ((high & mask) >> (7 - (pixel + 1)));
            ppu->buffer[*ppu->ly][(19 * 8) + pixel] = color;
        }

    }
}

uint16_t search_oam(PPU *ppu, uint8_t saveidx) {
    uint8_t y_bound = (*ppu->control & OBJ_SIZE_MASK) ? 0 : 8;
    for (uint8_t i = saveidx; i < 160; i += 4) {
        int16_t y_pos = ppu->vram[OAM_ADDRESS + i];
        if (*ppu->ly >= y_pos - 16 && *ppu->ly < y_pos - y_bound)
            return OAM_ADDRESS + i;
    }
    return UINT8_MAX;
}

uint8_t get_obp0_color(PPU *ppu, uint8_t color) {
    uint8_t new_color = 0;
    switch (color) {
        case 0:
            new_color = *ppu->obp0 & 3;
            break;
        case 1:
            new_color = (*ppu->obp0 & 12) >> 2;
            break;
        case 2:
            new_color = (*ppu->obp0 & 48) >> 4;
            break;
        case 3:
            new_color = (*ppu->obp0 & 192) >> 6;
            break;
        default:
            break;
    }
    return new_color;
}

void draw_sprite_line(PPU *ppu, uint16_t line, uint8_t start) {
    uint8_t low = line & 0xFF;
    uint8_t high = (line & 0xFF00) >> 8;
    for (uint8_t pixel = 0; pixel < 8 && start - 8 >= 0; pixel++) {
        uint8_t mask = 1 << (7 - pixel);
        uint8_t color;
        if (pixel == 7) {
            color = (low & mask) | ((high & mask) << 1);
        } else {
            color = ((low & mask) >> (7 - pixel)) | ((high & mask) >> (7 - (pixel + 1)));
        }
        ppu->buffer[*ppu->ly][start - (7 - pixel)] = get_obp0_color(ppu, color);
    }
}

void draw_sprite_line_x_flipped(PPU *ppu, uint16_t line, uint8_t start) {
    uint8_t low = line & 0xFF;
    uint8_t high = (line & 0xFF00) >> 8;
    for (int8_t pixel = 7; pixel >= 0; pixel--) {
        uint8_t mask = 1 << (7 - pixel);
        uint8_t color;
        if (pixel == 7) {
            color = (low & mask) | ((high & mask) << 1);
        } else {
            color = ((low & mask) >> (7 - pixel)) | ((high & mask) >> (7 - (pixel + 1)));
        }
        ppu->buffer[*ppu->ly][start - pixel] = get_obp0_color(ppu, color);
    }
}

// TODO: handle x-pos. conflicts 
void draw_sprites(PPU *ppu) {
    uint8_t saveidx = 0;
    for (uint8_t sprite_num = 0; sprite_num <= 10; sprite_num++) {
        uint16_t oam_entry = search_oam(ppu, saveidx);

        // no more sprites on this line
        if (oam_entry == UINT8_MAX) {
            return;
        }

        saveidx = oam_entry + 4;

        uint8_t y_pos;
        uint8_t x_pos = ppu->vram[oam_entry + 1];
        uint16_t tile_num = ppu->vram[oam_entry + 2];
        uint8_t attributes = ppu->vram[oam_entry + 3];
        
        uint8_t tile_data_len;
        uint8_t tile_offset;

        if (*ppu->control & OBJ_SIZE_MASK) {
            tile_num &= 0xFE;
            tile_data_len = 30;
            tile_offset = (*ppu->ly % 16) * 2;
        } else {
            tile_data_len = 14;
            tile_offset = (*ppu->ly % 8) * 2;
        }

        tile_num *= 16;
        uint16_t tile_addr = 0x8000;
        tile_addr += tile_num;

        if (attributes & Y_FLIP_MASK) {
            tile_addr += tile_data_len - tile_offset;
        } else {
            tile_addr += tile_offset;
        }

        uint8_t low = ppu->vram[tile_addr];
        uint8_t high = ppu->vram[tile_addr + 1];

        if (attributes & X_FLIP_MASK) {
            draw_sprite_line_x_flipped(ppu, low | (high << 8), x_pos);
        } else {
            draw_sprite_line(ppu, low | (high << 8), x_pos);
        }
    }
}

void draw_window(PPU *ppu) {
    return;
}

void draw_line(PPU *ppu) {
    if (*ppu->ly < 144) {
        if (*ppu->control & BG_WINDOW_DISPLAY_MASK) {
            draw_background(ppu);
        }
        if (*ppu->control & WINDOW_DISPLAY_MASK) {
            draw_window(ppu);
        }
        if (*ppu->control & OBJ_DISP_MASK) {
            draw_sprites(ppu);
        }
    }

    if (*ppu->ly <= 153) {
        (*ppu->ly)++;
    } else {
        *ppu->ly = 0;
    }
}

void generate_v_blank(PPU *ppu) {
    *ppu->interrupt_flag_register |= V_BLANK_MASK;
}

void step_ppu(PPU *ppu, uint64_t cycles) {
    if (*ppu->control & LCDC_CONTROL_OPERATION_MASK) {
        ppu->CYCLE_COUNT += cycles;
        if (ppu->CYCLE_COUNT > ((uint32_t) (CPU_FREQ / (PPU_FREQ * 144)))) {
            ppu->CYCLE_COUNT = ppu->CYCLE_COUNT - ((uint32_t) (CPU_FREQ / (PPU_FREQ * 144)));
            if (*ppu->ly == 144) {
                generate_v_blank(ppu);
            }
            draw_line(ppu);
        }
    } else {
        *ppu->ly = 0;
    }
}

void print_buffer(PPU *ppu) {
  for (int i = 0; i < NUM_PIXELS_V; i++) {
    for (int j = 0; j < NUM_PIXELS_H; j++) {
      printf("%u ", ppu->buffer[i][j]);
    }
    printf("\n");
  }
}
