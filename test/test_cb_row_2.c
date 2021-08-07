#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_2(CPU *cpu) {
    printf("Testing CB opcodes row 2.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 0x80;
    cpu->registers.B = 0x80;
    cpu->registers.C = 0x80;
    cpu->registers.D = 0x80;
    cpu->registers.E = 0x80;
    cpu->registers.H = 0x80;
    cpu->registers.L = 0x80;


    FILE *f = fopen("games/test/test_cb_ops_row_2.gb", "rb");

    load_program(f, cpu);

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SLA B
    assert(cpu->registers.B == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SLA C
    assert(cpu->registers.C == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SLA D
    assert(cpu->registers.D == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SLA E
    assert(cpu->registers.E == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SLA H
    assert(cpu->registers.H == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SLA L
    assert(cpu->registers.L == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.HL] = 0x80;
    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SLA (HL)
    assert(cpu->RAM[cpu->registers.HL] == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SLA A
    assert(cpu->registers.A == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.A = 0x01;
    cpu->registers.B = 0x01;
    cpu->registers.C = 0x01;
    cpu->registers.D = 0x01;
    cpu->registers.E = 0x01;
    cpu->registers.H = 0x01;
    cpu->registers.L = 0x01;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA B
    assert(cpu->registers.B == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA C
    assert(cpu->registers.C == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA D
    assert(cpu->registers.D == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA E
    assert(cpu->registers.E == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA H
    assert(cpu->registers.H == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA L
    assert(cpu->registers.L == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.HL] = 0x01;
    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA (HL)
    assert(cpu->RAM[cpu->registers.HL] == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA A
    assert(cpu->registers.A == 0);
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    /* Test sign-extension for arithmetic shift */

    cpu->registers.A = 0x81;
    cpu->registers.B = 0x81;
    cpu->registers.C = 0x81;
    cpu->registers.D = 0x81;
    cpu->registers.E = 0x81;
    cpu->registers.H = 0x81;
    cpu->registers.L = 0x81;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA B
    assert(cpu->registers.B == 0xC0);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA C
    assert(cpu->registers.C == 0xC0);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA D
    assert(cpu->registers.D == 0xC0);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA E
    assert(cpu->registers.E == 0xC0);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA H
    assert(cpu->registers.H == 0xC0);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA L
    assert(cpu->registers.L == 0xC0);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.HL] = 0x81;
    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA (HL)
    assert(cpu->RAM[cpu->registers.HL] == 0xC0);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // SRA A
    assert(cpu->registers.A == 0xC0);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    return 0;
}