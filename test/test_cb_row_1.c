#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_1(CPU *cpu) {
    printf("Testing CB opcodes row 1.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.A = 0x80;
    cpu->next_state.A = 0x80;
    cpu->current_state.B = 0x80;
    cpu->next_state.B = 0x80;
    cpu->current_state.C = 0x80;
    cpu->next_state.C = 0x80;
    cpu->current_state.D = 0x80;
    cpu->next_state.D = 0x80;
    cpu->current_state.E = 0x80;
    cpu->next_state.E = 0x80;
    cpu->current_state.H = 0x80;
    cpu->next_state.H = 0x80;
    cpu->current_state.L = 0x80;
    cpu->next_state.L = 0x80;


    FILE *f = fopen("games/test/test_cb_ops_row_1.gb", "rb");

    load_program(f, cpu);

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL B
    assert(cpu->current_state.B == 1);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL C
    assert(cpu->current_state.C == 1);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL D
    assert(cpu->current_state.D == 1);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL E
    assert(cpu->current_state.E == 1);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL H
    assert(cpu->current_state.H == 1);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL L
    assert(cpu->current_state.L == 1);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0x80;
    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL (HL)
    assert(cpu->RAM[cpu->current_state.HL] == 1);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL A
    assert(cpu->current_state.A == 1);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 0x01;
    cpu->next_state.A = 0x01;
    cpu->current_state.B = 0x01;
    cpu->next_state.B = 0x01;
    cpu->current_state.C = 0x01;
    cpu->next_state.C = 0x01;
    cpu->current_state.D = 0x01;
    cpu->next_state.D = 0x01;
    cpu->current_state.E = 0x01;
    cpu->next_state.E = 0x01;
    cpu->current_state.H = 0x01;
    cpu->next_state.H = 0x01;
    cpu->current_state.L = 0x01;
    cpu->next_state.L = 0x01;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR B
    assert(cpu->current_state.B == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR C
    assert(cpu->current_state.C == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR D
    assert(cpu->current_state.D == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR E
    assert(cpu->current_state.E == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR H
    assert(cpu->current_state.H == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR L
    assert(cpu->current_state.L == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0x01;
    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR (HL)
    assert(cpu->RAM[cpu->current_state.HL] == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR A
    assert(cpu->current_state.A == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    
    return 0;
}