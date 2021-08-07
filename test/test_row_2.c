#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_2(CPU *cpu) {
    printf("Testing opcodes row 2.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 0xFF;
    cpu->registers.BC = 0;
    cpu->registers.DE = 0;
    cpu->registers.HL = 0;

    FILE *f = fopen("games/test/test_ops_row_2.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // JR NZ,0
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD HL,0xBEEF
    assert(cpu->registers.HL == 0xBEEF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    uint16_t prev_HL = cpu->registers.HL;
    step_cpu(cpu); // LDI (HL),A
    assert(cpu->RAM[prev_HL] == cpu->registers.A);
    assert(cpu->registers.HL == prev_HL + 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.HL = prev_HL; // reset HL

    step_cpu(cpu); // INC HL
    assert(cpu->registers.HL == 0xBEF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // INC H
    assert(cpu->registers.HL = 0xBFF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // DEC HL
    assert(cpu->registers.HL = 0xBEF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD H,0
    assert(cpu->registers.H == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.A = 0x5C;
    cpu->registers.F = 0;
    step_cpu(cpu); // DAA
    assert(cpu->registers.A == 0x62);
    assert(cpu->registers.F == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    uint16_t prev_PC = cpu->registers.PC;
    step_cpu(cpu); // JR Z,0
    assert(cpu->registers.PC == prev_PC + 2);
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_HL = cpu->registers.HL;
    step_cpu(cpu); // ADD HL,HL
    assert(cpu->registers.HL == (prev_HL * 2));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_HL = cpu->registers.HL;
    cpu->RAM[cpu->registers.HL] = 0xCC;
    step_cpu(cpu); // LDI A,(HL)
    assert(cpu->registers.HL == prev_HL + 1);
    assert(cpu->registers.A == cpu->RAM[prev_HL]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_HL = cpu->registers.HL;
    step_cpu(cpu); // DEC HL
    assert(cpu->registers.HL == prev_HL - 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    uint8_t prev_L = cpu->registers.L;
    step_cpu(cpu); // INC L
    assert(cpu->registers.L == prev_L + 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // DEC L
    assert(cpu->registers.L == prev_L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD L,0xFF
    assert(cpu->registers.L == 0xFF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    uint8_t prev_A = cpu->registers.A;
    cpu->registers.F = 0;
    step_cpu(cpu); // CPL
    assert(cpu->registers.A == (uint8_t) ~prev_A);
    assert(cpu->registers.F == (FLAG_N_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);

    return 0;
}