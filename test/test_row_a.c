#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_a(CPU *cpu) {
    printf("Testing opcodes row A.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 0xFF;
    cpu->registers.B = 1;
    cpu->registers.C = 2;
    cpu->registers.D = 3;
    cpu->registers.E = 4;
    cpu->registers.H = 5;
    cpu->registers.L = 6;

    FILE *f = fopen("games/test/test_ops_row_a.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // AND B
    assert(cpu->registers.A == cpu->registers.B);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    step_cpu(cpu); // AND C
    assert(cpu->registers.A == cpu->registers.C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    step_cpu(cpu); // AND D
    assert(cpu->registers.A == cpu->registers.D);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    step_cpu(cpu); // AND E
    assert(cpu->registers.A == cpu->registers.E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    step_cpu(cpu); // AND H
    assert(cpu->registers.A == cpu->registers.H);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    step_cpu(cpu); // AND L
    assert(cpu->registers.A == cpu->registers.L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    cpu->RAM[cpu->registers.HL] = 1;

    step_cpu(cpu); // AND (HL)
    assert(cpu->registers.A == cpu->RAM[cpu->registers.HL]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    step_cpu(cpu); // AND A
    assert(cpu->registers.A == 0xFF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // XOR B
    assert(cpu->registers.A == (uint8_t) ~cpu->registers.B);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // XOR C
    assert(cpu->registers.A == (uint8_t) ~cpu->registers.C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;
    cpu->registers.A = 0xFF;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // XOR D
    assert(cpu->registers.A == (uint8_t) ~cpu->registers.D);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // XOR E
    assert(cpu->registers.A == (uint8_t) ~cpu->registers.E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // XOR H
    assert(cpu->registers.A == (uint8_t) ~cpu->registers.H);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // XOR L
    assert(cpu->registers.A == (uint8_t) ~cpu->registers.L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // XOR (HL)
    assert(cpu->registers.A == (uint8_t) ~cpu->RAM[cpu->registers.HL]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // XOR A
    assert(cpu->registers.A == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0xFF;

    return 0;
}