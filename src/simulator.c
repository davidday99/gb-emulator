#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include "../include/cpu.h"

#define MAX_INPUT_LEN 20

void simulate(CPU *cpu) {
    char input[MAX_INPUT_LEN];
    uint32_t cycles;
    uint16_t mem_start, mem_stop;

    do {
        printf("> ");

        fgets(input, MAX_INPUT_LEN, stdin);

        char command = input[0];

        char *start = input;
        char *end;

        switch (command)
        { 
        case 'd':
            dump_registers(cpu);
            break;

        case 'r':
            run(cpu);
            break;

        case 'm':
            while (isalpha(*start)) {
                start++;
            }
            sscanf(start, "%X %X", &mem_start, &mem_stop);
            while (mem_start < mem_stop) {
                printf("0x%04X: 0x%02X\n", mem_start, cpu->RAM[mem_start]);
                mem_start++;
            }

        case 's':
            while (isalpha(*start)) {
                start++;
            }
            cycles = strtol(start, &end, 10);
            while (cycles > 0) {
                printf("Opcode: 0x%02X\n", step(cpu));
                cycles--;
            }
            break;

        case 'q':
            printf("Bye!\n");
            exit(0);
            break;
    
        default:
            printf("Uknown command: %c\n", command);
            continue;
        };
        
    } while (cpu->current_state.PC != 0);
}

int main() {
    CPU cpu;

    FILE *f = fopen("games/tetris.gb", "rb");

    if (f == NULL) {
        printf("Error: could not open file.\n");
        exit(-1);
    }

    load_program(f, &cpu);

    simulate(&cpu);

    fclose(f);

    return 0;
}