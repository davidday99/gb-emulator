#include <stdint.h>
#include "../include/gb.h"

void init_gb(GB *gb) {
    init_cpu(&gb->cpu);
    init_ppu(&gb->ppu, &gb->cpu);
    init_screen(&gb->screen, gb->ppu.buffer);
}

void load_gb_game(GB *gb, FILE *rom) {
    load_program(rom, &gb->cpu);
}

void step_gb(GB *gb) {
    uint64_t prev_cycles = gb->cpu.current_state.CYCLE_COUNT;
    step_cpu(&(gb->cpu));
    step_ppu(&(gb->ppu), gb->cpu.current_state.CYCLE_COUNT - prev_cycles);
}