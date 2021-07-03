#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"
#include "../include/ppu.h"

#define NUM_PIXELS_V 144
#define NUM_PIXELS_H 160

void init_video(Video *video, CPU *cpu) {
    video->interrupt_flag_register = &cpu->RAM[IF_REGISTER];
    video->control = &cpu->RAM[LCDC_REGISTER];
    video->status = &cpu->RAM[STAT_REGISTER];
    video->scy = &cpu->RAM[SCY_REGISTER];
    video->scx = &cpu->RAM[SCX_REGISTER];
    video->ly = &cpu->RAM[LY_REGISTER];
    video->lyc = &cpu->RAM[LYC_REGISTER];
    video->dma_start = &cpu->RAM[DMA_REGISTER];
    video->bgp = &cpu->RAM[BGP_REGISTER];
    video->obpo = &cpu->RAM[OBP0_REGISTER];
    video->obp1 = &cpu->RAM[OBP1_REGISTER];
    video->wy = &cpu->RAM[WY_REGISTER];
    video->wx = &cpu->RAM[WX_REGISTER];
    video->vram = cpu->RAM;
    video->oam = &cpu->RAM[OAM_ADDRESS];
    video->CYCLE_COUNT = 0;

    video->buffer = (uint8_t**) calloc(sizeof(uint8_t*), NUM_PIXELS_V);
    for (uint16_t i; i < NUM_PIXELS_H; i++) {
        video->buffer[i] = (uint8_t*) calloc(sizeof(uint8_t), NUM_PIXELS_H);
    }
}

int16_t get_tile_number(Video *video, uint8_t *tile_disp_select_addr, uint8_t row, uint8_t tile) {
    uint16_t offset = (row * 32) + tile;
    uint8_t tile_num = *(tile_disp_select_addr + offset);

    /* interpret as signed if LCDC[4] == 1 */
    if (*video->control & BG_WINDOW_TILE_DATA_SELECT_MASK) {
        tile_num = (int8_t) tile_num;
    }
    return (int16_t) tile_num;
}

uint8_t* get_tile_address(Video *video, int16_t tile_num) {
    return video->vram + tile_num;
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

void write_screen(Video *video, uint8_t row) {
    
}

void draw_background(Video *video) {
    uint16_t tile_disp_select = (*video->control & BG_TILE_MAP_DISP_SELECT_MASK ) == 0 ? 0x9800 : 0x9C00;
    uint8_t scx_offset = *video->scx / 8;
    uint8_t scy_offset = *video->scy * 32;
    uint8_t pixel_offset = *video->scx % 8;

    for (uint8_t tile = 0; tile < 20; tile++) {
        uint16_t tile_num = video->vram[tile_disp_select + ((*video->ly / 8) * 32) + tile];

        tile_num += scx_offset;
        tile_num += scy_offset;

        tile_num *= 16;

        uint16_t tile_addr = (*video->control & BG_WINDOW_TILE_DATA_SELECT_MASK) == 0 ? 0x8800 : 0x8000;

        if (tile_addr == 0x8800) {
            tile_addr += (int8_t) tile_num;
        } else {
            tile_addr += tile_num;
        }

        tile_addr += (*video->ly % 8) * 2;

        uint8_t low = video->vram[tile_addr];
        uint8_t high = video->vram[tile_addr + 1];
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
            video->buffer[*video->ly][(tile * 8) + pixel - pixel_offset] = color;
        }
    }

    // if SCROLLX % 8 != 0, we need to fetch extra pixels from one extra tile
    if (pixel_offset != 0) {
        uint16_t tile_num = video->vram[tile_disp_select + ((*video->ly / 8) * 32) + 20];
        tile_num += scx_offset;

        tile_num *= 16;

        uint16_t tile_addr = (*video->control & BG_WINDOW_TILE_DATA_SELECT_MASK) == 0 ? 0x8800 : 0x8000;

        if (tile_addr == 0x8800) {
            tile_addr += (int8_t) tile_num;
        } else {
            tile_addr += tile_num;
        }

        tile_addr += (*video->ly % 8) * 2;

        uint8_t low = video->vram[tile_addr];
        uint8_t high = video->vram[tile_addr + 1];
        uint8_t pixel_condition = 8 - pixel_offset;

        for (uint8_t pixel = 0; pixel < pixel_condition; pixel++) {
            uint8_t mask = 1 << (7 - pixel);
            uint8_t color;

            color = ((low & mask) >> (7 - pixel)) | ((high & mask) >> (7 - (pixel + 1)));
            video->buffer[*video->ly][(19 * 8) + pixel] = color;
        }

    }
}

void draw_sprites(Video *video) {
    return;
}

void draw_window(Video *video) {
    return;
}

void draw_line(Video *video) {
    if (*video->ly < 144) {
        if (*video->control & BG_WINDOW_DISPLAY_MASK) {
            draw_background(video);
        }
        if (*video->control & WINDOW_DISPLAY_MASK) {
            draw_sprites(video);
        }
        if (*video->control & OBJ_DISP_MASK) {
            draw_window(video);
        }
    }

    if (*video->ly <= 153) {
        (*video->ly)++;
    } else {
        *video->ly = 0;
    }
}

void generate_v_blank(Video *video) {
    *video->interrupt_flag_register |= V_BLANK_MASK;
}

void step_video(Video *video, uint64_t cycles) {
    if (*video->control & LCDC_CONTROL_OPERATION_MASK) {
        video->CYCLE_COUNT += cycles;
        if (video->CYCLE_COUNT > ((uint32_t) (CPU_FREQ / (VIDEO_FREQ * 144)))) {
            video->CYCLE_COUNT = video->CYCLE_COUNT - ((uint32_t) (CPU_FREQ / (VIDEO_FREQ * 144)));
            if (*video->ly == 144) {
                generate_v_blank(video);
            }
            draw_line(video);
        }
    } else {
        *video->ly = 0;
    }
}

void print_buffer(Video *video) {
  for (int i = 0; i < NUM_PIXELS_V; i++) {
    for (int j = 0; j < NUM_PIXELS_H; j++) {
      printf("%u ", video->buffer[i][j]);
    }
    printf("\n");
  }
}
