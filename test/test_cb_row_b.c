#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_b(CPU *cpu) {
    printf("Testing CB opcodes row B.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_cb_ops_row_b.gb", "rb");

    load_program(f, cpu);

    cpu->current_state.A = 64;
    cpu->next_state.A = 64;
    cpu->current_state.B = 64;
    cpu->next_state.B = 64;
    cpu->current_state.C = 64;
    cpu->next_state.C = 64;
    cpu->current_state.D = 64;
    cpu->next_state.D = 64;
    cpu->current_state.E = 64;
    cpu->next_state.E = 64;
    cpu->current_state.H = 64;
    cpu->next_state.H = 64;
    cpu->current_state.L = 64;
    cpu->next_state.L = 64;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,B
    assert(cpu->current_state.B == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,C
    assert(cpu->current_state.C == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,D
    assert(cpu->current_state.D == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,E
    assert(cpu->current_state.E == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,H
    assert(cpu->current_state.H == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,L
    assert(cpu->current_state.L == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 64;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,(HL)
    assert(cpu->RAM[cpu->current_state.HL] == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,A
    assert(cpu->current_state.A == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 128;
    cpu->next_state.A = 128;
    cpu->current_state.B = 128;
    cpu->next_state.B = 128;
    cpu->current_state.C = 128;
    cpu->next_state.C = 128;
    cpu->current_state.D = 128;
    cpu->next_state.D = 128;
    cpu->current_state.E = 128;
    cpu->next_state.E = 128;
    cpu->current_state.H = 128;
    cpu->next_state.H = 128;
    cpu->current_state.L = 128;
    cpu->next_state.L = 128;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,B
    assert(cpu->current_state.B == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,C
    assert(cpu->current_state.C == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,D
    assert(cpu->current_state.D == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,E
    assert(cpu->current_state.E == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,H
    assert(cpu->current_state.H == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,L
    assert(cpu->current_state.L == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 128;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,(HL)
    assert(cpu->RAM[cpu->current_state.HL] == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,A
    assert(cpu->current_state.A == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    return 0;
}