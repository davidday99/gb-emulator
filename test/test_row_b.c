#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_b(CPU *cpu) {
    printf("Testing opcodes row B.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.A = 0;
    cpu->next_state.A = 0;
    cpu->current_state.B = 1;
    cpu->next_state.B = 1;
    cpu->current_state.C = 2;
    cpu->next_state.C = 2;
    cpu->current_state.D = 3;
    cpu->next_state.D = 3;
    cpu->current_state.E = 4;
    cpu->next_state.E = 4;
    cpu->current_state.H = 5;
    cpu->next_state.H = 5;
    cpu->current_state.L = 8;
    cpu->next_state.L = 8;

    FILE *f = fopen("games/test/test_ops_row_b.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // OR B
    assert(cpu->current_state.A == cpu->current_state.B);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step_cpu(cpu); // OR C
    assert(cpu->current_state.A == cpu->current_state.C);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step_cpu(cpu); // OR D
    assert(cpu->current_state.A == cpu->current_state.D);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step_cpu(cpu); // OR E
    assert(cpu->current_state.A == cpu->current_state.E);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step_cpu(cpu); // OR H
    assert(cpu->current_state.A == cpu->current_state.H);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step_cpu(cpu); // OR L
    assert(cpu->current_state.A == cpu->current_state.L);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->RAM[cpu->current_state.HL] = 1;

    step_cpu(cpu); // OR (HL)
    assert(cpu->current_state.A == cpu->RAM[cpu->current_state.HL]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step_cpu(cpu); // OR A
    assert(cpu->current_state.A == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    uint8_t prev_A = cpu->current_state.A;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // CP B
    assert(cpu->current_state.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->current_state.A == prev_A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // CP C
    assert(cpu->current_state.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->current_state.A == prev_A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // CP D
    assert(cpu->current_state.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->current_state.A == prev_A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // CP E
    assert(cpu->current_state.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->current_state.A == prev_A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // CP H
    assert(cpu->current_state.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->current_state.A == prev_A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // CP L
    assert(cpu->current_state.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->current_state.A == prev_A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // CP (HL)
    assert(cpu->current_state.F == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->current_state.A == prev_A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // CP A
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_N_MASK));
    assert(cpu->current_state.A == prev_A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    return 0;
}