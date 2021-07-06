#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdio.h>

#define RAM_SIZE 0x10000
#define MEM_CYCLE_DELAY 4
#define JUMP_DELAY 4
#define ALU_DELAY_16_BIT 4
#define DMA_CYCLE_DELAY 160

#define CPU_FREQ 4194304

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
    uint64_t INSTRUCTION_COUNT;
} Core;

typedef struct CPU {
    Core current_state;
    Core next_state;
    uint8_t RAM[RAM_SIZE];
    uint8_t CB_mode;
    uint8_t interrupts_enabled;
    uint8_t stopped;
    uint8_t low_power_mode;
    uint8_t dma_flag;
} CPU;

void init_cpu(CPU *cpu);
void step_cpu(CPU *cpu);
void step_cpu_n(uint32_t n, CPU *cpu);
void run(CPU *cpu);
void dump_registers(CPU *cpu);
void load_program(FILE *fp, CPU *cpu);
void set_flags(CPU *cpu, uint8_t flag_mask, uint8_t z, uint8_t n, uint8_t h, uint8_t c);

#endif /* CPU_H */