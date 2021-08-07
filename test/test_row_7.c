#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_7(CPU *cpu) {
    printf("Testing opcodes row 7.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 1;
    cpu->registers.B = 2;
    cpu->registers.C = 3;
    cpu->registers.D = 4;
    cpu->registers.E = 5;
    cpu->registers.H = 0;
    cpu->registers.L = 0;

    FILE *f = fopen("games/test/test_ops_row_7.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // LD (HL),B
    assert(cpu->RAM[cpu->registers.HL] == cpu->registers.B);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD (HL),C
    assert(cpu->RAM[cpu->registers.HL] == cpu->registers.C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD (HL),D
    assert(cpu->RAM[cpu->registers.HL] == cpu->registers.D);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD (HL),E
    assert(cpu->RAM[cpu->registers.HL] == cpu->registers.E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD (HL),H
    assert(cpu->RAM[cpu->registers.HL] == cpu->registers.H);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD (HL),L
    assert(cpu->RAM[cpu->registers.HL] == cpu->registers.L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD (HL),A
    assert(cpu->RAM[cpu->registers.HL] == cpu->registers.A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    cpu->registers.A = 0;
    cpu->registers.H = 6;
    cpu->registers.L = 7;

    step_cpu(cpu); // LD A,B
    assert(cpu->registers.A == cpu->registers.B);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD A,C
    assert(cpu->registers.A == cpu->registers.C);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD A,D
    assert(cpu->registers.A == cpu->registers.D);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD A,E
    assert(cpu->registers.A == cpu->registers.E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD A,H
    assert(cpu->registers.A == cpu->registers.H);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD A,L
    assert(cpu->registers.A == cpu->registers.L);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;
    
    cpu->RAM[cpu->registers.HL] = 0xFF;
    step_cpu(cpu); // LD A,(HL)
    assert(cpu->registers.A == cpu->RAM[cpu->registers.HL]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;
    
    step_cpu(cpu); // LD A,A
    assert(cpu->registers.A == 0xFF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // HALT
    assert(cpu->low_power_mode == 1);
    uint16_t prev_PC = cpu->registers.PC;
    step_cpu(cpu);
    assert(cpu->registers.PC == prev_PC);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);

    return 0;
}