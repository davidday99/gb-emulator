#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_5(CPU *cpu) {
    printf("Testing opcodes row 5.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 1;
    cpu->registers.B = 2;
    cpu->registers.C = 3;
    cpu->registers.D = 0;
    cpu->registers.E = 5;
    cpu->registers.H = 6;
    cpu->registers.L = 7;

    FILE *f = fopen("games/test/test_ops_row_5.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // LD D,B
    assert(cpu->registers.D == cpu->registers.B);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD D,C
    assert(cpu->registers.D == cpu->registers.C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD D,D
    assert(cpu->registers.D == 3);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD D,E
    assert(cpu->registers.D == cpu->registers.E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD D,H
    assert(cpu->registers.D == cpu->registers.H);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD D,L
    assert(cpu->registers.D == cpu->registers.L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.HL] = 0xFF;
    
    step_cpu(cpu); // LD D,(HL)
    assert(cpu->registers.D == cpu->RAM[cpu->registers.HL]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD D,A
    assert(cpu->registers.D == cpu->registers.A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    cpu->registers.D = 4;
    cpu->registers.E = 0;

    step_cpu(cpu); // LD E,B
    assert(cpu->registers.E == cpu->registers.B);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD E,C
    assert(cpu->registers.E == cpu->registers.C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD E,D
    assert(cpu->registers.E == cpu->registers.D);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD E,E
    assert(cpu->registers.E == 4);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD E,H
    assert(cpu->registers.E == cpu->registers.H);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD E,L
    assert(cpu->registers.E == cpu->registers.L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD E,(HL)
    assert(cpu->registers.E == cpu->RAM[cpu->registers.HL]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD E,A
    assert(cpu->registers.E == cpu->registers.A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    return 0;
}