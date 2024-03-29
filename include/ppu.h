#ifndef PPU_H
#define PPU_H

#include <stdint.h>
#include "../include/cpu.h"

#define PIXEL_NUM 32 * 32 * 16

#define LCDC_CONTROL_OPERATION_MASK 128
#define WINDOW_TILE_MAP_DISP_SELECT_MASK 64
#define WINDOW_DISPLAY_MASK 32
#define BG_WINDOW_TILE_DATA_SELECT_MASK 16
#define BG_TILE_MAP_DISP_SELECT_MASK 8
#define OBJ_SIZE_MASK 4
#define OBJ_DISP_MASK 2
#define BG_WINDOW_DISPLAY_MASK 1

#define VIDEO_FREQ 60

typedef struct Video {
    uint8_t *vram;
    uint8_t *bg_tile_map;
    uint8_t *oam;
    uint8_t *interrupt_flag_register;
    uint8_t *control; 
    uint8_t *status;
    uint8_t *scy;
    uint8_t *scx;
    uint8_t *ly;
    uint8_t *lyc;
    uint8_t *dma_start;
    uint8_t *bgp;
    uint8_t *obp0;
    uint8_t *obp1;
    uint8_t *wy;
    uint8_t *wx;
    uint64_t CYCLE_COUNT;
    uint8_t **buffer;
} Video;

void init_video(Video *video, CPU *cpu);
void step_video(Video *video, uint64_t cycles);
void print_buffer(Video *video);

#endif /* PPU_H */