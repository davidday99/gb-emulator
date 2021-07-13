#include <stdlib.h>
#include "../include/cpu.h"
#include "../include/ppu.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./gb <GB ROM path>\n");
        exit(-1);
    }
    
    FILE *f = fopen(argv[1], "rb");

    if (f == NULL) {
        printf("Error: could not open file.\n");
        exit(-1);
    }

    CPU cpu;
    PPU ppu;

    init_cpu(&cpu);
    init_ppu(&ppu, &cpu);
    load_program(f, &cpu);

    uint64_t prev_cycles;
    uint8_t flag = 0;
    while (1) {
        prev_cycles = cpu.current_state.CYCLE_COUNT;
        step_cpu(&cpu);
        step_ppu(&ppu, cpu.current_state.CYCLE_COUNT - prev_cycles);
        if (*ppu.ly == 144) {
            if (flag == 0) {
               print_buffer(&ppu);
               flag = 1;
            }
        } else {
            flag = 0;
        }
    }
}