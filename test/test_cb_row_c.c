#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_c(CPU *cpu) {
    printf("Testing CB opcodes row C.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_cb_ops_row_c.gb", "rb");

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
    step(cpu); // SET 0,B
    assert(cpu->current_state.B == 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 0,C
    assert(cpu->current_state.C == 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 0,D
    assert(cpu->current_state.D == 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 0,E
    assert(cpu->current_state.E == 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 0,H
    assert(cpu->current_state.H == 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 0,L
    assert(cpu->current_state.L == 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 0,(HL)
    assert(cpu->RAM[cpu->current_state.HL] == 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 0,A
    assert(cpu->current_state.A == 1);
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
    step(cpu); // SET 1,B
    assert(cpu->current_state.B == 2);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 1,C
    assert(cpu->current_state.C == 2);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 1,D
    assert(cpu->current_state.D == 2);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 1,E
    assert(cpu->current_state.E == 2);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 1,H
    assert(cpu->current_state.H == 2);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 1,L
    assert(cpu->current_state.L == 2);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 1,(HL)
    assert(cpu->RAM[cpu->current_state.HL] == 2);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SET 1,A
    assert(cpu->current_state.A == 2);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    return 0;
}