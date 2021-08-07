#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_9(CPU *cpu) {
    printf("Testing opcodes row 9.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 0;
    cpu->registers.B = 1;
    cpu->registers.C = 2;
    cpu->registers.D = 3;
    cpu->registers.E = 4;
    cpu->registers.H = 5;
    cpu->registers.L = 6;

    FILE *f = fopen("games/test/test_ops_row_9.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // SUB B
    assert(cpu->registers.A == (uint8_t) -cpu->registers.B);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // SUB C
    assert(cpu->registers.A == (uint8_t) -cpu->registers.C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // SUB D
    assert(cpu->registers.A == (uint8_t) -cpu->registers.D);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // SUB E
    assert(cpu->registers.A == (uint8_t) -cpu->registers.E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // SUB H
    assert(cpu->registers.A == (uint8_t) -cpu->registers.H);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // SUB L
    assert(cpu->registers.A == (uint8_t) -cpu->registers.L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->RAM[cpu->registers.HL] = 1;

    step_cpu(cpu); // SUB (HL)
    assert(cpu->registers.A == (uint8_t) -cpu->RAM[cpu->registers.HL]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    step_cpu(cpu); // SUB A
    assert(cpu->registers.A == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // SBC B
    assert(cpu->registers.A == (uint8_t) (-cpu->registers.B - 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // SBC C
    assert(cpu->registers.A == (uint8_t) (-cpu->registers.C - 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // SBC D
    assert(cpu->registers.A == (uint8_t) (-cpu->registers.D - 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // SBC E
    assert(cpu->registers.A == (uint8_t) (-cpu->registers.E - 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // SBC H
    assert(cpu->registers.A == (uint8_t) (-cpu->registers.H - 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // SBC L
    assert(cpu->registers.A == (uint8_t) (-cpu->registers.L - 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // SBC (HL)
    assert(cpu->registers.A == (uint8_t) (-cpu->RAM[cpu->registers.HL] - 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // SBC A
    assert(cpu->registers.A == (uint8_t) -1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->registers.A = 0;

    return 0;
}