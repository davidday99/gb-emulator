#include <stdint.h>
#include <string.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"
#include "../include/video.h"

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

uint8_t* get_tile_address(Video *video, int16_t tile_num) {
    return video->vram + tile_num;
}

uint8_t get_pixel_color(Video *video, uint8_t *tile_addr, uint8_t row, uint8_t pixel) {
    uint8_t pixel_mask = 1 << (7 - pixel);
    uint8_t color;
    row %= 8;
    tile_addr += row;

    color |= (*tile_addr & pixel_mask) >> (7 - pixel); // get LSB
    color |= (*(tile_addr + 1) & pixel_mask) >> (8 - pixel); // get MSB

    return color;
}

void generate_v_blank(Video *video) {
    *video->interrupt_flag_register |= V_BLANK_MASK;
}

void step_video(Video *video) {
    if ((video->CYCLE_COUNT % VIDEO_FREQ) == 0) {
        generate_v_blank(video);
    }
}
