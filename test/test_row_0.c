#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_0(CPU *cpu) {
    printf("Testing opcodes row 0.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 0xFF;
    cpu->registers.BC = 0;
    cpu->registers.DE = 0;
    cpu->registers.HL = 0;

    FILE *f = fopen("games/test/test_ops_row_0.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // NOP
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD BC,0xBEEF
    assert(cpu->registers.BC == 0xBEEF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD (BC),A
    assert(cpu->RAM[cpu->registers.BC] == cpu->registers.A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // INC BC
    assert(cpu->registers.BC == 0xBEF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // INC B
    assert(cpu->registers.BC = 0xBFF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // DEC B
    assert(cpu->registers.BC = 0xBEF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD B,0
    assert(cpu->registers.B == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.A = 0x80;
    cpu->registers.F = 0;
    step_cpu(cpu); // RLCA
    assert(cpu->registers.A == 1);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.SP = 1;
    step_cpu(cpu); // LD (0xBEEF),SP
    assert(cpu->RAM[0xBEEF] == cpu->registers.SP);
    assert(cpu->CYCLE_COUNT - prev_cycles == 20);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // ADD HL,BC
    assert(cpu->registers.HL == cpu->registers.BC);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.BC] = 0xCC;
    step_cpu(cpu); // LD A,(BC)
    assert(cpu->registers.A == cpu->RAM[cpu->registers.BC]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    uint16_t prev_BC = cpu->registers.BC;
    step_cpu(cpu); // DEC BC
    assert(cpu->registers.BC == prev_BC - 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    uint8_t prev_C = cpu->registers.C;
    step_cpu(cpu); // INC C
    assert(cpu->registers.C == prev_C + 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // DEC C
    assert(cpu->registers.C == prev_C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD C,0xFF
    assert(cpu->registers.C == 0xFF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // RRCA
    assert(cpu->registers.A == 0x66);
    assert(cpu->registers.F == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);

    return 0;
}