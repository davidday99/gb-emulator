#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_f(CPU *cpu) {
    printf("Testing CB opcodes row F.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_cb_ops_row_f.gb", "rb");

    load_program(f, cpu);

    cpu->current_state.A = 0;
    cpu->next_state.A = 0;
    cpu->current_state.B = 0;
    cpu->next_state.B = 0;
    cpu->current_state.C = 0;
    cpu->next_state.C = 0;
    cpu->current_state.D = 0;
    cpu->next_state.D = 0;
    cpu->current_state.E = 0;
    cpu->next_state.E = 0;
    cpu->current_state.H = 0;
    cpu->next_state.H = 0;
    cpu->current_state.L = 0;
    cpu->next_state.L = 0;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 6,B
    assert(cpu->current_state.B == 64);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 6,C
    assert(cpu->current_state.C == 64);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 6,D
    assert(cpu->current_state.D == 64);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 6,E
    assert(cpu->current_state.E == 64);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 6,H
    assert(cpu->current_state.H == 64);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 6,L
    assert(cpu->current_state.L == 64);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 6,(HL)
    assert(cpu->RAM[cpu->current_state.HL] == 64);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 6,A
    assert(cpu->current_state.A == 64);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 0;
    cpu->next_state.A = 0;
    cpu->current_state.B = 0;
    cpu->next_state.B = 0;
    cpu->current_state.C = 0;
    cpu->next_state.C = 0;
    cpu->current_state.D = 0;
    cpu->next_state.D = 0;
    cpu->current_state.E = 0;
    cpu->next_state.E = 0;
    cpu->current_state.H = 0;
    cpu->next_state.H = 0;
    cpu->current_state.L = 0;
    cpu->next_state.L = 0;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 7,B
    assert(cpu->current_state.B == 128);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 7,C
    assert(cpu->current_state.C == 128);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 7,D
    assert(cpu->current_state.D == 128);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 7,E
    assert(cpu->current_state.E == 128);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 7,H
    assert(cpu->current_state.H == 128);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 7,L
    assert(cpu->current_state.L == 128);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 7,(HL)
    assert(cpu->RAM[cpu->current_state.HL] == 128);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // RES 7,A
    assert(cpu->current_state.A == 128);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    return 0;
}