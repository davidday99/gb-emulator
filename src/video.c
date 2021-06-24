#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"
#include "../include/video.h"

#define NUM_PIXELS_V 160
#define NUM_PIXELS_H 144

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

    video->buffer = (uint8_t**) malloc(sizeof(uint8_t*) * NUM_PIXELS_V);
    for (uint8_t i; i < NUM_PIXELS_H; i++) {
        *(video->buffer + i) = (uint8_t*) malloc(sizeof(uint8_t) * NUM_PIXELS_H);
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
    uint8_t *ptr;
    uint8_t color;
    if (*video->control & BG_TILE_MAP_DISP_SELECT_MASK) {
        ptr = &video->vram[TILE_DISP_SELECT_1];
    } else {
        ptr = &video->vram[TILE_DISP_SELECT_0];
    }

    for (uint8_t tile; tile < 32; tile++) {
        uint16_t tile_num = get_tile_number(video, ptr, *video->ly, tile);
        ptr += tile_num;
        for (uint8_t pixel; pixel < 8; pixel++) {
            video->buffer[*video->ly][pixel + (tile_num * 8)] = get_pixel_color(ptr, *video->ly, pixel);
        }
    }

}

void draw_line(Video *video) {
    if (*video->ly < 144) {
        if (*video->control & BG_WINDOW_DISPLAY_MASK) {
            draw_background(video);
        }
        // if (*video->control & WINDOW_DISPLAY_MASK) {
        //     draw_window();
        // }
        // if (*video->control & OBJ_DISP_MASK) {
        //     draw_sprites();
        // }
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
    video->CYCLE_COUNT += cycles;
    if (video->CYCLE_COUNT > ((uint32_t) (CPU_FREQ / (VIDEO_FREQ * 144)))) {
        video->CYCLE_COUNT = video->CYCLE_COUNT - ((uint32_t) (CPU_FREQ / (VIDEO_FREQ * 144)));
        if (*video->ly == 144) {
            generate_v_blank(video);
        }
        draw_line(video);
    }
}
