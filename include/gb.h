#ifndef GB_H
#define GB_H

#include <stdio.h>
#include "../include/cpu.h"
#include "../include/ppu.h"
#include "../include/input.h"
#include "../include/screen.h"

typedef struct GB {
    CPU cpu;
    PPU ppu;
    Input input;
    Screen screen;
} GB;

void init_gb(GB *gb);
void step_gb(GB *gb);
void load_gb_game(GB *gb, FILE *rom);

#endif /* GB_H */