#ifndef SM83_H
#define SM83_H

#include <stdint.h>

#define RAM_SIZE 0x10000

typedef struct Core {
    uint8_t A;
    uint8_t F;

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

void step_n(uint32_t n, CPU *cpu);
void run(CPU *cpu);
void dump_registers(CPU *cpu);
void load_program(FILE *fp, CPU *cpu);


#define FLAG_Z_MASK 0x80
#define FLAG_N_MASK 0x40
#define FLAG_H_MASK 0x20
#define FLAG_C_MASK 0x10

/* OPCODES */

#define NOP 0
#define LD_BC_D16 0x01
#define LD_BC_A 0x02
#define INC_BC 0x03
#define INC_B 0x04
#define DEC_B 0x05

#define JP_NN 0xC3

#define CB 1
#define NO_CB 0

/* All instructions are at least 1 byte, plus some number of bytes for args, 
   plus one extra byte if CB-prefixed instruction */
#define INSTRUCTION_SIZE(args_bytes, CB) 1 + args_bytes + CB

typedef struct Instruction {
    char mnemonic[15];
    uint8_t opcode;
    uint8_t immediate_size;
    uint16_t immediate;
    uint8_t cycles;
} Instruction;

#endif /* SM83_H */