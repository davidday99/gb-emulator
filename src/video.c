#include <stdint.h>
#include <string.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

#define PIXEL_NUM 32 * 32 * 16

#define OPERATION_MASK 127
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
    uint8_t *obpo;
    uint8_t *obp1;
    uint8_t *wy;
    uint8_t *wx;
    uint64_t CYCLE_COUNT;
} Video;

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

    video->vram = (*video->control & BG_WINDOW_TILE_DATA_SELECT_MASK) != 0 ?
                    &cpu->RAM[TILE_DATA_SELECT_1] :
                    &cpu->RAM[TILE_DATA_SELECT_0];

    video->bg_tile_map = (*video->control & BG_TILE_MAP_DISP_SELECT_MASK) != 0 ?
                            &cpu->RAM[TILE_DISP_SELECT_1] :
                            &cpu->RAM[TILE_DISP_SELECT_0];

    video->oam = &cpu->RAM[OAM_ADDRESS];
}

void write_screen(Video *video, uint8_t row) {
    
}

int16_t get_tile_number(Video *video, uint8_t row, uint8_t tile) {
    uint16_t offset = (row * 32) + tile;
    uint8_t tile_num = *(video->bg_tile_map + offset);

    /* interpret as signed if LCDC[4] == 1 */
    if (*video->control & BG_WINDOW_TILE_DATA_SELECT_MASK) {
        tile_num = (int8_t) tile_num;
    }
    return (int16_t) tile_num;
}

uint16_t get_tile_address(Video *video, int16_t tile_num) {
    return (uint16_t) video->vram + tile_num;
}

uint8_t get_pixel_color(Video *video, uint16_t tile_addr, uint8_t row, uint8_t pixel) {
    uint8_t pixel_mask = 1 << (7 - pixel);
    uint8_t color;
    row %= 8;
    tile_addr += row;

    color |= (video->vram[tile_addr] & pixel_mask) >> (7 - pixel); // get LSB
    color |= (video->vram[tile_addr + 1] & pixel_mask) >> (8 - pixel); // get MSB

    return color;
}

void generate_v_blank(Video *video) {
    *video->interrupt_flag_register |= V_BLANK_MASK;
}

void step(Video *video) {
    if ((video->CYCLE_COUNT % VIDEO_FREQ) == 0) {
        generate_v_blank(video);
    }
}
