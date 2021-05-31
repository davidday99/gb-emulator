/* SM83 CPU Core */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cpu.h"
#include "../include/isa-sm83.h"

#define Low16bits(x) ((x) & 0xFFFF)
#define Low8bits(x) ((x) & 0xFF)


/************************************************************/
/*                                                          */
/* Procedure : dump_registers                               */
/*                                                          */
/* Purpose   : dump value of each architectural register    */ 
/*                                                          */
/************************************************************/

void dump_registers(CPU *cpu) {
    printf("REGISTER VALUES:\n");
    printf("********************************\n");
    printf("Cycle Count: %d\n", cpu->current_state.CYCLE_COUNT);
    printf("PC: 0x%04X\n", cpu->current_state.PC);
    printf("SP: 0x%04X\n", cpu->current_state.SP);
    printf("A: 0x%02X\t", cpu->current_state.A);
    printf("F: 0x%02X\n", cpu->current_state.F);
    printf("B: 0x%02X\t", cpu->current_state.B);
    printf("C: 0x%02X\n", cpu->current_state.C);
    printf("D: 0x%02X\t", cpu->current_state.D);
    printf("E: 0x%02X\n", cpu->current_state.E);
    printf("H: 0x%02X\t", cpu->current_state.H);
    printf("L: 0x%02X\n", cpu->current_state.L);
    printf("********************************\n");
}


/************************************************************/
/*                                                          */
/* Procedure : load_program                                 */
/*                                                          */
/* Purpose   : Load a program ROM into memory               */ 
/*                                                          */
/************************************************************/

void load_program(FILE *fp, CPU *cpu) {
    memset(cpu->RAM, 0, sizeof(cpu->RAM));
    uint8_t word;
    uint32_t i = 0;
    
    while (!feof(fp)) {
        fread(&word, sizeof(uint8_t), 1, fp);
        cpu->RAM[i++] = word;
    }

    cpu->current_state.PC = 0x100;
}

/************************************************************/
/*                                                          */
/* Procedure : fetch                                        */
/*                                                          */
/* Purpose   : Fetch a single instruction from memory       */
/*                                                          */
/************************************************************/
uint8_t fetch(CPU *cpu) {
    return cpu->RAM[cpu->current_state.PC];
}

/************************************************************/
/*                                                          */
/* Procedure : decode                                       */
/*                                                          */
/* Purpose   : get potential immediate for instruction      */
/*                                                          */
/************************************************************/
Instruction decode(uint8_t opcode, CPU *cpu) {
    Instruction instruction;
    uint16_t immediate;
    uint8_t is_CB = 0;

    if (opcode == 0xCB) {
        // handle CB-prefixed instruction
        opcode = cpu->RAM[cpu->current_state.PC + 1];
        instruction = CB_INSTRUCTIONS[opcode];
        is_CB = 1;
    } else {
        // handle standard instruction
        instruction = INSTRUCTIONS[opcode];
    }

    switch (instruction.immediate_size) {
        case 0:
            break;
        case 1:
            immediate = (uint8_t) cpu->RAM[cpu->current_state.PC + 1 + is_CB];
            break;
        case 2:
            immediate = (uint16_t) (cpu->RAM[cpu->current_state.PC + 1 + is_CB]) | 
            (cpu->RAM[cpu->current_state.PC + 2 + is_CB] << 8);

        default:
            break;
    }

    instruction.immediate = immediate;

    return instruction;
}

void execute(Instruction *instruction, CPU *cpu) {
    switch (instruction->opcode) {
        case NOP:
            cpu->next_state.PC = cpu->current_state.PC + instruction->byte_len;
            break;

        case LD_BC_D16:
            cpu->next_state.BC = instruction->immediate;
            cpu->next_state.PC = cpu->current_state.PC + instruction->byte_len;
        
        case LD_BC_A:
            cpu->RAM[cpu->current_state.BC] = cpu->current_state.A;
            cpu->next_state.PC = cpu->current_state.PC + instruction->byte_len;

        case JP_A16:
            cpu->next_state.PC = instruction->immediate;
            break;

        default:
            break;
    }
}

void simulate_cycles(uint8_t cycles, CPU *cpu) {
    cpu->next_state.CYCLE_COUNT = cpu->current_state.CYCLE_COUNT + cycles;

    while (cycles > 0) {
        cycles--; // add code to simulate real CPU speed
    }
}

/************************************************************/
/*                                                          */
/* Procedure : step                                         */
/*                                                          */
/* Purpose   : execute a single instruction, return opcode  */
/*                                                          */
/************************************************************/
uint8_t step(CPU *cpu) {
    uint8_t opcode = fetch(cpu);
    Instruction instruction = decode(opcode, cpu);
    execute(&instruction, cpu);
    simulate_cycles(instruction.cycles, cpu);

    cpu->current_state = cpu->next_state;

    return instruction.opcode;
}

/************************************************************/
/*                                                          */
/* Procedure : step_n                                       */
/*                                                          */
/* Purpose   : execute n instructions                       */
/*                                                          */
/************************************************************/
void step_n(uint32_t n, CPU *cpu) {
    while (n > 0) {
        step(cpu);
        n--;
    }
}

/************************************************************/
/*                                                          */
/* Procedure : run                                          */
/*                                                          */
/* Purpose   : run the CPU until completion                 */
/*                                                          */
/************************************************************/
void run(CPU *cpu) {
    do {
        step(cpu);
    } while (cpu->current_state.PC != 0);
}
