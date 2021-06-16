#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_a(CPU *cpu) {
    printf("Testing opcodes row A.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;
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

    FILE *f = fopen("games/test/test_ops_row_a.gb", "rb");

    load_program(f, cpu);

    step(cpu); // AND B
    assert(cpu->current_state.A == cpu->current_state.B);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    step(cpu); // AND C
    assert(cpu->current_state.A == cpu->current_state.C);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    step(cpu); // AND D
    assert(cpu->current_state.A == cpu->current_state.D);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    step(cpu); // AND E
    assert(cpu->current_state.A == cpu->current_state.E);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    step(cpu); // AND H
    assert(cpu->current_state.A == cpu->current_state.H);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    step(cpu); // AND L
    assert(cpu->current_state.A == cpu->current_state.L);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    cpu->RAM[cpu->current_state.HL] = 1;

    step(cpu); // AND (HL)
    assert(cpu->current_state.A == cpu->RAM[cpu->current_state.HL]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    step(cpu); // AND A
    assert(cpu->current_state.A == 0xFF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;


    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // XOR B
    assert(cpu->current_state.A == (uint8_t) ~cpu->current_state.B);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // XOR C
    assert(cpu->current_state.A == (uint8_t) ~cpu->current_state.C);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // XOR D
    assert(cpu->current_state.A == (uint8_t) ~cpu->current_state.D);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // XOR E
    assert(cpu->current_state.A == (uint8_t) ~cpu->current_state.E);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // XOR H
    assert(cpu->current_state.A == (uint8_t) ~cpu->current_state.H);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // XOR L
    assert(cpu->current_state.A == (uint8_t) ~cpu->current_state.L);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // XOR (HL)
    assert(cpu->current_state.A == (uint8_t) ~cpu->RAM[cpu->current_state.HL]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // XOR A
    assert(cpu->current_state.A == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    return 0;
}