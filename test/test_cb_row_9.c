#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_9(CPU *cpu) {
    printf("Testing CB opcodes row 9.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_cb_ops_row_9.gb", "rb");

    load_program(f, cpu);

    cpu->current_state.A = 4;
    cpu->next_state.A = 4;
    cpu->current_state.B = 4;
    cpu->next_state.B = 4;
    cpu->current_state.C = 4;
    cpu->next_state.C = 4;
    cpu->current_state.D = 4;
    cpu->next_state.D = 4;
    cpu->current_state.E = 4;
    cpu->next_state.E = 4;
    cpu->current_state.H = 4;
    cpu->next_state.H = 4;
    cpu->current_state.L = 4;
    cpu->next_state.L = 4;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 2,B
    assert(cpu->current_state.B == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 2,C
    assert(cpu->current_state.C == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 2,D
    assert(cpu->current_state.D == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 2,E
    assert(cpu->current_state.E == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 2,H
    assert(cpu->current_state.H == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 2,L
    assert(cpu->current_state.L == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 4;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 2,(HL)
    assert(cpu->RAM[cpu->current_state.HL] == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 2,A
    assert(cpu->current_state.A == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 8;
    cpu->next_state.A = 8;
    cpu->current_state.B = 8;
    cpu->next_state.B = 8;
    cpu->current_state.C = 8;
    cpu->next_state.C = 8;
    cpu->current_state.D = 8;
    cpu->next_state.D = 8;
    cpu->current_state.E = 8;
    cpu->next_state.E = 8;
    cpu->current_state.H = 8;
    cpu->next_state.H = 8;
    cpu->current_state.L = 8;
    cpu->next_state.L = 8;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 3,B
    assert(cpu->current_state.B == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 3,C
    assert(cpu->current_state.C == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 3,D
    assert(cpu->current_state.D == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 3,E
    assert(cpu->current_state.E == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 3,H
    assert(cpu->current_state.H == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 3,L
    assert(cpu->current_state.L == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 8;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 3,(HL)
    assert(cpu->RAM[cpu->current_state.HL] == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 3,A
    assert(cpu->current_state.A == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    return 0;
}