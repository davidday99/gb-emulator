#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_b(CPU *cpu) {
    printf("Testing opcodes row B.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 0;
    cpu->registers.B = 1;
    cpu->registers.C = 2;
    cpu->registers.D = 3;
    cpu->registers.E = 4;
    cpu->registers.H = 5;
    cpu->registers.L = 8;

    FILE *f = fopen("games/test/test_ops_row_b.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // OR B
    assert(cpu->registers.A == cpu->registers.B);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // OR C
    assert(cpu->registers.A == cpu->registers.C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // OR D
    assert(cpu->registers.A == cpu->registers.D);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // OR E
    assert(cpu->registers.A == cpu->registers.E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // OR H
    assert(cpu->registers.A == cpu->registers.H);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // OR L
    assert(cpu->registers.A == cpu->registers.L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->RAM[cpu->registers.HL] = 1;

    step_cpu(cpu); // OR (HL)
    assert(cpu->registers.A == cpu->RAM[cpu->registers.HL]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // OR A
    assert(cpu->registers.A == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    uint8_t prev_A = cpu->registers.A;

    cpu->registers.F = 0;
    step_cpu(cpu); // CP B
    assert(cpu->registers.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->registers.A == prev_A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = 0;
    step_cpu(cpu); // CP C
    assert(cpu->registers.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->registers.A == prev_A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = 0;
    step_cpu(cpu); // CP D
    assert(cpu->registers.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->registers.A == prev_A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = 0;
    step_cpu(cpu); // CP E
    assert(cpu->registers.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->registers.A == prev_A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = 0;
    step_cpu(cpu); // CP H
    assert(cpu->registers.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->registers.A == prev_A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = 0;
    step_cpu(cpu); // CP L
    assert(cpu->registers.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->registers.A == prev_A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = 0;
    step_cpu(cpu); // CP (HL)
    assert(cpu->registers.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->registers.A == prev_A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = 0;
    step_cpu(cpu); // CP A
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_N_MASK));
    assert(cpu->registers.A == prev_A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    return 0;
}