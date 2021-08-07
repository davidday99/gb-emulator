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

    cpu->registers.A = 64;
    cpu->registers.B = 64;
    cpu->registers.C = 64;
    cpu->registers.D = 64;
    cpu->registers.E = 64;
    cpu->registers.H = 64;
    cpu->registers.L = 64;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,B
    assert(cpu->registers.B == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,C
    assert(cpu->registers.C == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,D
    assert(cpu->registers.D == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,E
    assert(cpu->registers.E == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,H
    assert(cpu->registers.H == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,L
    assert(cpu->registers.L == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = 64;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,(HL)
    assert(cpu->RAM[cpu->registers.HL] == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 6,A
    assert(cpu->registers.A == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.A = 128;
    cpu->registers.B = 128;
    cpu->registers.C = 128;
    cpu->registers.D = 128;
    cpu->registers.E = 128;
    cpu->registers.H = 128;
    cpu->registers.L = 128;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,B
    assert(cpu->registers.B == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,C
    assert(cpu->registers.C == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,D
    assert(cpu->registers.D == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,E
    assert(cpu->registers.E == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,H
    assert(cpu->registers.H == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,L
    assert(cpu->registers.L == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = 128;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,(HL)
    assert(cpu->RAM[cpu->registers.HL] == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RES 7,A
    assert(cpu->registers.A == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    return 0;
}