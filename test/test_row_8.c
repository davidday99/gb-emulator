#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_8(CPU *cpu) {
    printf("Testing opcodes row 8.\n");

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
    cpu->current_state.L = 6;
    cpu->next_state.L = 6;
    cpu->RAM[cpu->current_state.HL] = 1;

    FILE *f = fopen("games/test/test_ops_row_8.gb", "rb");

    load_program(f, cpu);

    step(cpu); // ADD A,B
    assert(cpu->current_state.A == cpu->current_state.B);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step(cpu); // ADD A,C
    assert(cpu->current_state.A == cpu->current_state.C);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step(cpu); // ADD A,D
    assert(cpu->current_state.A == cpu->current_state.D);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step(cpu); // ADD A,E
    assert(cpu->current_state.A == cpu->current_state.E);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step(cpu); // ADD A,H
    assert(cpu->current_state.A == cpu->current_state.H);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step(cpu); // ADD A,L
    assert(cpu->current_state.A == cpu->current_state.L);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step(cpu); // ADD A,(HL)
    assert(cpu->current_state.A == cpu->RAM[cpu->current_state.HL]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    step(cpu); // ADD A,A
    assert(cpu->current_state.A == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;


    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // ADC A,B
    assert(cpu->current_state.A == cpu->current_state.B + 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // ADC A,C
    assert(cpu->current_state.A == cpu->current_state.C + 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // ADC A,D
    assert(cpu->current_state.A == cpu->current_state.D + 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // ADC A,E
    assert(cpu->current_state.A == cpu->current_state.E + 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // ADC A,H
    assert(cpu->current_state.A == cpu->current_state.H + 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // ADC A,L
    assert(cpu->current_state.A == cpu->current_state.L + 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // ADC A,(HL)
    assert(cpu->current_state.A == cpu->RAM[cpu->current_state.HL] + 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // ADC A,A
    assert(cpu->current_state.A == 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;

    return 0;
}