#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_3(CPU *cpu) {
    printf("Testing CB opcodes row 3.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 0x0F;
    cpu->registers.B = 0x0F;
    cpu->registers.C = 0x0F;
    cpu->registers.D = 0x0F;
    cpu->registers.E = 0x0F;
    cpu->registers.H = 0x0F;
    cpu->registers.L = 0x0F;


    FILE *f = fopen("games/test/test_cb_ops_row_3.gb", "rb");

    load_program(f, cpu);

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP B
    assert(cpu->registers.B == 0xF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP C
    assert(cpu->registers.C == 0xF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP D
    assert(cpu->registers.D == 0xF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP E
    assert(cpu->registers.E == 0xF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP H
    assert(cpu->registers.H == 0xF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP L
    assert(cpu->registers.L == 0xF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.HL] = 0x0F;
    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP (HL)
    assert(cpu->RAM[cpu->registers.HL] == 0xF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP A
    assert(cpu->registers.A == 0xF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    /* Test that sign isn't extended for logical shift */

    cpu->registers.A = 0x81;
    cpu->registers.B = 0x81;
    cpu->registers.C = 0x81;
    cpu->registers.D = 0x81;
    cpu->registers.E = 0x81;
    cpu->registers.H = 0x81;
    cpu->registers.L = 0x81;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL B
    assert(cpu->registers.B == 0x40);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL C
    assert(cpu->registers.C == 0x40);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL D
    assert(cpu->registers.D == 0x40);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL E
    assert(cpu->registers.E == 0x40);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL H
    assert(cpu->registers.H == 0x40);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL L
    assert(cpu->registers.L == 0x40);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.HL] = 0x81;
    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL (HL)
    assert(cpu->RAM[cpu->registers.HL] == 0x40);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL A
    assert(cpu->registers.A == 0x40);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    return 0;
}