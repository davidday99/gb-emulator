#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_e(CPU *cpu) {
    printf("Testing CB opcodes row E.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_cb_ops_row_e.gb", "rb");

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
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 4,B
    assert(cpu->current_state.B == 16);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 4,C
    assert(cpu->current_state.C == 16);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 4,D
    assert(cpu->current_state.D == 16);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 4,E
    assert(cpu->current_state.E == 16);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 4,H
    assert(cpu->current_state.H == 16);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 4,L
    assert(cpu->current_state.L == 16);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 4,(HL)
    assert(cpu->RAM[cpu->current_state.HL] == 16);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 4,A
    assert(cpu->current_state.A == 16);
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
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 5,B
    assert(cpu->current_state.B == 32);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 5,C
    assert(cpu->current_state.C == 32);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 5,D
    assert(cpu->current_state.D == 32);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 5,E
    assert(cpu->current_state.E == 32);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 5,H
    assert(cpu->current_state.H == 32);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 5,L
    assert(cpu->current_state.L == 32);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 5,(HL)
    assert(cpu->RAM[cpu->current_state.HL] == 32);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SET 5,A
    assert(cpu->current_state.A == 32);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    return 0;
}