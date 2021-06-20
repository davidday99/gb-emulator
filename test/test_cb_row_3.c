#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_3(CPU *cpu) {
    printf("Testing CB opcodes row 3.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.A = 0x0F;
    cpu->next_state.A = 0x0F;
    cpu->current_state.B = 0x0F;
    cpu->next_state.B = 0x0F;
    cpu->current_state.C = 0x0F;
    cpu->next_state.C = 0x0F;
    cpu->current_state.D = 0x0F;
    cpu->next_state.D = 0x0F;
    cpu->current_state.E = 0x0F;
    cpu->next_state.E = 0x0F;
    cpu->current_state.H = 0x0F;
    cpu->next_state.H = 0x0F;
    cpu->current_state.L = 0x0F;
    cpu->next_state.L = 0x0F;


    FILE *f = fopen("games/test/test_cb_ops_row_3.gb", "rb");

    load_program(f, cpu);

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP B
    assert(cpu->current_state.B == 0xF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP C
    assert(cpu->current_state.C == 0xF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP D
    assert(cpu->current_state.D == 0xF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP E
    assert(cpu->current_state.E == 0xF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP H
    assert(cpu->current_state.H == 0xF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP L
    assert(cpu->current_state.L == 0xF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0x0F;
    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP (HL)
    assert(cpu->RAM[cpu->current_state.HL] == 0xF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SWAP A
    assert(cpu->current_state.A == 0xF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    /* Test that sign isn't extended for logical shift */

    cpu->current_state.A = 0x81;
    cpu->next_state.A = 0x81;
    cpu->current_state.B = 0x81;
    cpu->next_state.B = 0x81;
    cpu->current_state.C = 0x81;
    cpu->next_state.C = 0x81;
    cpu->current_state.D = 0x81;
    cpu->next_state.D = 0x81;
    cpu->current_state.E = 0x81;
    cpu->next_state.E = 0x81;
    cpu->current_state.H = 0x81;
    cpu->next_state.H = 0x81;
    cpu->current_state.L = 0x81;
    cpu->next_state.L = 0x81;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL B
    assert(cpu->current_state.B == 0x40);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL C
    assert(cpu->current_state.C == 0x40);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL D
    assert(cpu->current_state.D == 0x40);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL E
    assert(cpu->current_state.E == 0x40);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL H
    assert(cpu->current_state.H == 0x40);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL L
    assert(cpu->current_state.L == 0x40);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0x81;
    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL (HL)
    assert(cpu->RAM[cpu->current_state.HL] == 0x40);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRL A
    assert(cpu->current_state.A == 0x40);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    return 0;
}