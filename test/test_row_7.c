#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_7(CPU *cpu) {
    printf("Testing opcodes row 7.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.A = 1;
    cpu->next_state.A = 1;
    cpu->current_state.B = 2;
    cpu->next_state.B = 2;
    cpu->current_state.C = 3;
    cpu->next_state.C = 3;
    cpu->current_state.D = 4;
    cpu->next_state.D = 4;
    cpu->current_state.E = 5;
    cpu->next_state.E = 5;
    cpu->current_state.H = 0;
    cpu->next_state.H = 0;
    cpu->current_state.L = 0;
    cpu->next_state.L = 0;

    FILE *f = fopen("games/test/test_ops_row_7.gb", "rb");

    load_program(f, cpu);

    step(cpu); // LD (HL),B
    assert(cpu->RAM[cpu->current_state.HL] == cpu->current_state.B);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step(cpu); // LD (HL),C
    assert(cpu->RAM[cpu->current_state.HL] == cpu->current_state.C);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD (HL),D
    assert(cpu->RAM[cpu->current_state.HL] == cpu->current_state.D);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD (HL),E
    assert(cpu->RAM[cpu->current_state.HL] == cpu->current_state.E);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD (HL),H
    assert(cpu->RAM[cpu->current_state.HL] == cpu->current_state.H);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD (HL),L
    assert(cpu->RAM[cpu->current_state.HL] == cpu->current_state.L);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD (HL),A
    assert(cpu->RAM[cpu->current_state.HL] == cpu->current_state.A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    cpu->current_state.A = 0;
    cpu->next_state.A = 0;
    cpu->current_state.H = 6;
    cpu->next_state.H = 6;
    cpu->current_state.L = 7;
    cpu->next_state.L = 7;

    step(cpu); // LD A,B
    assert(cpu->next_state.A == cpu->current_state.B);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step(cpu); // LD A,C
    assert(cpu->next_state.A == cpu->current_state.C);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD A,D
    assert(cpu->next_state.A == cpu->current_state.D);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD A,E
    assert(cpu->next_state.A == cpu->current_state.E);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD A,H
    assert(cpu->next_state.A == cpu->current_state.H);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD A,L
    assert(cpu->next_state.A == cpu->current_state.L);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    cpu->RAM[cpu->current_state.HL] = 0xFF;
    step(cpu); // LD A,(HL)
    assert(cpu->next_state.A == cpu->RAM[cpu->current_state.HL]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD A,A
    assert(cpu->next_state.A == 0xFF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint16_t prev_PC = cpu->current_state.PC;
    step(cpu); // HALT
    assert(cpu->current_state.PC == prev_PC);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);

    return 0;
}