#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_0(CPU *cpu) {
    printf("Testing CB opcodes row 0.\n");

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


    FILE *f = fopen("games/test/test_cb_ops_row_0.gb", "rb");

    load_program(f, cpu);

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RLC B
    assert(cpu->current_state.B == 0x01);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RLC C
    assert(cpu->current_state.C == 0x01);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RLC D
    assert(cpu->current_state.D == 0x01);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RLC E
    assert(cpu->current_state.E == 0x01);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RLC H
    assert(cpu->current_state.H == 0x01);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RLC L
    assert(cpu->current_state.L == 0x01);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0x80;
    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RLC (HL)
    assert(cpu->RAM[cpu->current_state.HL] == 0x01);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RLC A
    assert(cpu->current_state.A == 0x01);
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

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RRC B
    assert(cpu->current_state.B == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RRC C
    assert(cpu->current_state.C == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RRC D
    assert(cpu->current_state.D == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RRC E
    assert(cpu->current_state.E == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RRC H
    assert(cpu->current_state.H == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RRC L
    assert(cpu->current_state.L == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0x01;
    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RRC (HL)
    assert(cpu->RAM[cpu->current_state.HL] == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // RRC A
    assert(cpu->current_state.A == 0x80);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    
    return 0;
}