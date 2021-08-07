#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_6(CPU *cpu) {
    printf("Testing opcodes row 6.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 1;
    cpu->registers.B = 2;
    cpu->registers.C = 3;
    cpu->registers.D = 4;
    cpu->registers.E = 5;
    cpu->registers.H = 0;
    cpu->registers.L = 7;

    FILE *f = fopen("games/test/test_ops_row_6.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // LD H,B
    assert(cpu->registers.H == cpu->registers.B);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD H,C
    assert(cpu->registers.H == cpu->registers.C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD H,D
    assert(cpu->registers.H == cpu->registers.D);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD H,E
    assert(cpu->registers.H == cpu->registers.E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD H,H
    assert(cpu->registers.H == 5);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD H,L
    assert(cpu->registers.H == cpu->registers.L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.HL] = 0xFF;
    
    step_cpu(cpu); // LD H,(HL)
    assert(cpu->registers.H == 0xFF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD H,A
    assert(cpu->registers.H == cpu->registers.A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    cpu->registers.H = 6;
    cpu->registers.L = 0;

    step_cpu(cpu); // LD L,B
    assert(cpu->registers.L == cpu->registers.B);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD L,C
    assert(cpu->registers.L == cpu->registers.C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD L,D
    assert(cpu->registers.L == cpu->registers.D);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD L,E
    assert(cpu->registers.L == cpu->registers.E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD L,H
    assert(cpu->registers.L == cpu->registers.H);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD L,L
    assert(cpu->registers.L == 6);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.HL] = 0xFF;
    
    step_cpu(cpu); // LD L,(HL)
    assert(cpu->registers.L == 0xFF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD L,A
    assert(cpu->registers.L == cpu->registers.A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    return 0;
}