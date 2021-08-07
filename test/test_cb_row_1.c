#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_1(CPU *cpu) {
    printf("Testing CB opcodes row 1.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 0x80;
    cpu->registers.B = 0x80;
    cpu->registers.C = 0x80;
    cpu->registers.D = 0x80;
    cpu->registers.E = 0x80;
    cpu->registers.H = 0x80;
    cpu->registers.L = 0x80;


    FILE *f = fopen("games/test/test_cb_ops_row_1.gb", "rb");

    load_program(f, cpu);

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL B
    assert(cpu->registers.B == 1);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL C
    assert(cpu->registers.C == 1);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL D
    assert(cpu->registers.D == 1);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL E
    assert(cpu->registers.E == 1);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL H
    assert(cpu->registers.H == 1);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL L
    assert(cpu->registers.L == 1);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.HL] = 0x80;
    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL (HL)
    assert(cpu->RAM[cpu->registers.HL] == 1);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RL A
    assert(cpu->registers.A == 1);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.A = 0x01;
    cpu->registers.B = 0x01;
    cpu->registers.C = 0x01;
    cpu->registers.D = 0x01;
    cpu->registers.E = 0x01;
    cpu->registers.H = 0x01;
    cpu->registers.L = 0x01;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR B
    assert(cpu->registers.B == 0x80);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR C
    assert(cpu->registers.C == 0x80);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR D
    assert(cpu->registers.D == 0x80);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR E
    assert(cpu->registers.E == 0x80);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR H
    assert(cpu->registers.H == 0x80);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR L
    assert(cpu->registers.L == 0x80);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.HL] = 0x01;
    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR (HL)
    assert(cpu->RAM[cpu->registers.HL] == 0x80);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RR A
    assert(cpu->registers.A == 0x80);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    return 0;
}