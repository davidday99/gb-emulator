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


typedef struct Video {
    uint8_t *screen;
    uint8_t *interrupt_flag_register;
    uint8_t *control; 
    uint8_t *status;
    uint8_t *scy;
    uint8_t scx;
    uint8_t *ly;
    uint8_t *lyc;
    uint8_t *dma_start;
    uint8_t *bgp;
    uint8_t *obpo;
    uint8_t *obp1;
    uint8_t *wy;
    uint8_t *wx;   
} Video;

init_video(Video *video, CPU *cpu) {
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

    video->screen = (*video->control & BG_WINDOW_TILE_DATA_SELECT_MASK) != 0 ?
                    &cpu->RAM[VRAM_START_0] :
                    &cpu->RAM[VRAM_START_1];
    
}

void write_line(Video *video, uint8_t row) {

}