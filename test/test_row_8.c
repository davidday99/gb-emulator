#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_8(CPU *cpu) {
    printf("Testing opcodes row 8.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 0;
    cpu->registers.B = 1;
    cpu->registers.C = 2;
    cpu->registers.D = 3;
    cpu->registers.E = 4;
    cpu->registers.H = 5;
    cpu->registers.L = 6;

    FILE *f = fopen("games/test/test_ops_row_8.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // ADD A,B
    assert(cpu->registers.A == cpu->registers.B);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // ADD A,C
    assert(cpu->registers.A == cpu->registers.C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // ADD A,D
    assert(cpu->registers.A == cpu->registers.D);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // ADD A,E
    assert(cpu->registers.A == cpu->registers.E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // ADD A,H
    assert(cpu->registers.A == cpu->registers.H);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // ADD A,L
    assert(cpu->registers.A == cpu->registers.L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->RAM[cpu->registers.HL] = 1;

    step_cpu(cpu); // ADD A,(HL)
    assert(cpu->registers.A == cpu->RAM[cpu->registers.HL]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // ADD A,A
    assert(cpu->registers.A == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // ADC A,B
    assert(cpu->registers.A == cpu->registers.B + 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // ADC A,C
    assert(cpu->registers.A == cpu->registers.C + 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // ADC A,D
    assert(cpu->registers.A == cpu->registers.D + 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // ADC A,E
    assert(cpu->registers.A == cpu->registers.E + 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // ADC A,H
    assert(cpu->registers.A == cpu->registers.H + 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // ADC A,L
    assert(cpu->registers.A == cpu->registers.L + 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // ADC A,(HL)
    assert(cpu->registers.A == cpu->RAM[cpu->registers.HL] + 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // ADC A,A
    assert(cpu->registers.A == 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    return 0;
}