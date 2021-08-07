#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_3(CPU *cpu) {
    printf("Testing opcodes row 3.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 0xFF;
    cpu->registers.BC = 0;
    cpu->registers.DE = 0;
    cpu->registers.HL = 0;

    FILE *f = fopen("games/test/test_ops_row_3.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // JR NC,0
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD SP,0xBEEF
    assert(cpu->registers.SP == 0xBEEF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    uint16_t prev_HL = cpu->registers.HL;
    step_cpu(cpu); // LDD (HL),A
    assert(cpu->RAM[prev_HL] == cpu->registers.A);
    assert(cpu->registers.HL == (uint16_t) (prev_HL - 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.HL = prev_HL; // reset HL

    uint16_t prev_SP = cpu->registers.SP;
    step_cpu(cpu); // INC SP
    assert(cpu->registers.SP == (uint16_t) (prev_SP + 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    uint8_t prev_ref_HL = cpu->RAM[cpu->registers.HL];
    step_cpu(cpu); // INC (HL)
    assert(cpu->RAM[cpu->registers.HL] == (uint8_t) (prev_ref_HL + 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // DEC (HL)
    assert(cpu->RAM[cpu->registers.HL] == prev_ref_HL);
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD (HL),d8
    assert(cpu->RAM[cpu->registers.HL] == 0xFF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // SCF
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    uint16_t prev_PC = cpu->registers.PC;
    step_cpu(cpu); // JR C,0
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 2));
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_HL = cpu->registers.HL;
    step_cpu(cpu); // ADD HL,SP
    assert(cpu->registers.HL == cpu->registers.SP);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_HL = cpu->registers.HL;
    step_cpu(cpu); // LDD A,(HL)
    assert(cpu->registers.A == cpu->RAM[prev_HL]);
    assert(cpu->registers.HL == (uint16_t) (prev_HL - 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.HL = prev_HL;

    prev_SP = cpu->registers.SP;
    step_cpu(cpu); // DEC SP
    assert(cpu->registers.SP == (uint16_t) (prev_SP - 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    uint8_t prev_A = cpu->registers.A;
    step_cpu(cpu); // INC A
    assert(cpu->registers.A == (uint8_t) (prev_A + 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // DEC A
    assert(cpu->registers.A == prev_A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.A = 0;
    step_cpu(cpu); // LD A,0x01
    assert(cpu->registers.A == 0x01);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // CCF
    assert(cpu->registers.F == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);

    return 0;
}