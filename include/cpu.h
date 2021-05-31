#ifndef CPU_H
#define CPU_H

#include <stdint.h>

#define RAM_SIZE 0x10000

typedef struct Core {
    union {
        struct {
            uint8_t F;
            uint8_t A;
        };
        uint16_t AF;
    };

    union {
        struct {
            uint8_t C;
            uint8_t B;
        };
        uint16_t BC;
    };

    union {
        struct {
            uint8_t E;
            uint8_t D;
        };
        uint16_t DE;
    };

    
    union {
        struct {
            uint8_t L;
            uint8_t H;
        };
        uint16_t HL;
    };

    uint16_t SP;
    uint16_t PC;
    uint64_t CYCLE_COUNT;
} Core;

typedef struct CPU {
    Core current_state;
    Core next_state;
    uint8_t RAM[RAM_SIZE];
} CPU;

uint8_t step(CPU *cpu);
void step_n(uint32_t n, CPU *cpu);
void run(CPU *cpu);
void dump_registers(CPU *cpu);
void load_program(FILE *fp, CPU *cpu);

#endif /* CPU_H */