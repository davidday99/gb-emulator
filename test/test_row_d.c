#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_d(CPU *cpu) {
    printf("Testing opcodes row D.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.SP = 0xFFFD;
    cpu->next_state.SP = 0xFFFD;

    FILE *f = fopen("games/test/test_ops_row_d.gb", "rb");

    load_program(f, cpu);

    cpu->RAM[0xFFFE] = 0xBE;
    cpu->RAM[0xFFFD] = 0xEF;

    uint16_t prev_SP = cpu->current_state.SP;
    step_cpu(cpu); // POP DE
    assert(cpu->current_state.DE == 0xBEEF);
    assert(cpu->current_state.SP == prev_SP + 2);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_SP = cpu->current_state.SP;
    cpu->current_state.DE = 0xFEED;
    cpu->next_state.DE = 0xFEED;
    step_cpu(cpu); // PUSH DE
    assert(cpu->current_state.SP == prev_SP - 2);
    uint16_t *ptr = (uint16_t*) &cpu->RAM[cpu->current_state.SP];
    assert(*ptr == 0xFEED);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // SUB A,1
    assert(cpu->current_state.A == 0xFF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // SBC A,0xFF
    assert(cpu->current_state.A == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);

    return 0;
}