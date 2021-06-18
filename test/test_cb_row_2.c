#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_2(CPU *cpu) {
    printf("Testing CB opcodes row 2.\n");

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


    FILE *f = fopen("games/test/test_cb_ops_row_2.gb", "rb");

    load_program(f, cpu);

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SLA B
    assert(cpu->current_state.B == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SLA C
    assert(cpu->current_state.C == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SLA D
    assert(cpu->current_state.D == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SLA E
    assert(cpu->current_state.E == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SLA H
    assert(cpu->current_state.H == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SLA L
    assert(cpu->current_state.L == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0x80;
    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SLA (HL)
    assert(cpu->RAM[cpu->current_state.HL] == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SLA A
    assert(cpu->current_state.A == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
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
    step(cpu); // Enter CB Mode
    step(cpu); // SRA B
    assert(cpu->current_state.B == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA C
    assert(cpu->current_state.C == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA D
    assert(cpu->current_state.D == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA E
    assert(cpu->current_state.E == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA H
    assert(cpu->current_state.H == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA L
    assert(cpu->current_state.L == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0x01;
    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA (HL)
    assert(cpu->RAM[cpu->current_state.HL] == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA A
    assert(cpu->current_state.A == 0);
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    /* Test sign-extension for arithmetic shift */

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
    step(cpu); // Enter CB Mode
    step(cpu); // SRA B
    assert(cpu->current_state.B == 0xC0);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA C
    assert(cpu->current_state.C == 0xC0);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA D
    assert(cpu->current_state.D == 0xC0);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA E
    assert(cpu->current_state.E == 0xC0);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA H
    assert(cpu->current_state.H == 0xC0);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA L
    assert(cpu->current_state.L == 0xC0);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0x81;
    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA (HL)
    assert(cpu->RAM[cpu->current_state.HL] == 0xC0);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // SRA A
    assert(cpu->current_state.A == 0xC0);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    
    return 0;
}