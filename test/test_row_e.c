#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_e(CPU *cpu) {
    printf("Testing opcodes row E.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.SP = 0xFFFD;
    cpu->next_state.SP = 0xFFFD;

    FILE *f = fopen("games/test/test_ops_row_e.gb", "rb");

    load_program(f, cpu);

    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;
    step_cpu(cpu); // LDH (0x01),A
    assert(cpu->RAM[0xFF01] == cpu->current_state.A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;


    cpu->RAM[0xFFFE] = 0xBE;
    cpu->RAM[0xFFFD] = 0xEF;

    uint16_t prev_SP = cpu->current_state.SP;
    step_cpu(cpu); // POP HL
    assert(cpu->current_state.HL == 0xBEEF);
    assert(cpu->current_state.SP == (uint16_t) (prev_SP + 2));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.C = 2;
    cpu->next_state.C = 2;
    step_cpu(cpu); // LD (C),A
    assert(cpu->RAM[0xFF02] == cpu->current_state.A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_SP = cpu->current_state.SP;
    cpu->current_state.HL = 0xFEED;
    cpu->next_state.HL = 0xFEED;
    step_cpu(cpu); // PUSH HL
    assert(cpu->current_state.SP == (uint16_t) (prev_SP - 2));
    uint16_t *ptr = (uint16_t*) &cpu->RAM[cpu->current_state.SP];
    assert(*ptr == 0xFEED);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint8_t prev_A = cpu->current_state.A;
    step_cpu(cpu); // AND 0x55
    assert(cpu->current_state.A == (uint8_t) (prev_A & 0x55));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_SP = cpu->current_state.SP;
    step_cpu(cpu); // ADD SP,1
    assert(cpu->current_state.SP == (uint16_t) (prev_SP + 1));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;
    step_cpu(cpu); // LD (0xFF03),A
    assert(cpu->RAM[0xFF03] == cpu->current_state.A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_A = cpu->current_state.A;
    step_cpu(cpu); // XOR A,0xFF
    assert(cpu->current_state.A == (uint8_t) (prev_A ^ 0xFF));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);

    return 0;
}