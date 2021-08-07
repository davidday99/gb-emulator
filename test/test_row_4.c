#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_4(CPU *cpu) {
    printf("Testing opcodes row 4.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 1;
    cpu->registers.B = 0;
    cpu->registers.C = 3;
    cpu->registers.D = 4;
    cpu->registers.E = 5;
    cpu->registers.H = 6;
    cpu->registers.L = 7;

    FILE *f = fopen("games/test/test_ops_row_4.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // LD B,B
    assert(cpu->registers.B == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD B,C
    assert(cpu->registers.B == cpu->registers.C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD B,D
    assert(cpu->registers.B == cpu->registers.D);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD B,E
    assert(cpu->registers.B == cpu->registers.E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD B,H
    assert(cpu->registers.B == cpu->registers.H);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD B,L
    assert(cpu->registers.B == cpu->registers.L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.HL] = 0xFF;
    
    step_cpu(cpu); // LD B,(HL)
    assert(cpu->registers.B == cpu->RAM[cpu->registers.HL]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD B,A
    assert(cpu->registers.B == cpu->registers.A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    cpu->registers.B = 2;
    cpu->registers.C = 0;

    step_cpu(cpu); // LD C,B
    assert(cpu->registers.C == cpu->registers.B);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD C,C
    assert(cpu->registers.C == 2);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD C,D
    assert(cpu->registers.C == cpu->registers.D);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD C,E
    assert(cpu->registers.C == cpu->registers.E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD C,H
    assert(cpu->registers.C == cpu->registers.H);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD C,L
    assert(cpu->registers.C == cpu->registers.L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD C,(HL)
    assert(cpu->registers.C == cpu->RAM[cpu->registers.HL]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD C,A
    assert(cpu->registers.C == cpu->registers.A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    return 0;
}