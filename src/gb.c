#include <stdlib.h>
#include "../include/cpu.h"
#include "../include/video.h"
#include "../include/screen.h"

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
    Video video;
    Screen screen;

    init_cpu(&cpu);
    init_video(&video, &cpu);
    init_screen(&screen, video.buffer);
    load_program(f, &cpu);

    uint64_t prev_cycles;

    //show_screen(&screen);
    while (1) {
        prev_cycles = cpu.current_state.CYCLE_COUNT;
        step_cpu(&cpu);
        step_video(&video, cpu.current_state.CYCLE_COUNT - prev_cycles);
        // if (*video.ly == 144) {
        //     draw_screen(&screen);
        // }
    }
}