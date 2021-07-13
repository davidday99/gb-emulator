#include <stdlib.h>
#include "../include/gb.h"

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

    GB gb;

    init_gb(&gb);
    load_gb_game(&gb, f);

    uint8_t flag = 0;
    while (1) {
        step_gb(&gb);
        if (*gb.ppu.ly == 144) {
            if (flag == 0) {
               print_buffer(&gb.ppu);
               flag = 1;
            }
        } else {
            flag = 0;
        }
    }
}