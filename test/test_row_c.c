#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_c(CPU *cpu) {
    printf("Testing opcodes row C.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.SP = 0xFFFD;

    FILE *f = fopen("games/test/test_ops_row_c.gb", "rb");

    load_program(f, cpu);

    cpu->RAM[0xFFFE] = 0xBE;
    cpu->RAM[0xFFFD] = 0xEF;

    uint16_t prev_SP = cpu->registers.SP;
    step_cpu(cpu); // POP BC
    assert(cpu->registers.BC == 0xBEEF);
    assert(cpu->registers.SP == prev_SP + 2);
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_SP = cpu->registers.SP;
    cpu->registers.BC = 0xFEED;
    step_cpu(cpu); // PUSH BC
    assert(cpu->registers.SP == prev_SP - 2);
    uint16_t *ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == 0xFEED);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // ADD A,0xFF
    assert(cpu->registers.A == 0xFF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // PREFIX CB
    assert(cpu->CB_mode == 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    cpu->CB_mode = 0;

    step_cpu(cpu); // ADC A, 1
    assert(cpu->registers.A == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);

    return 0;
}