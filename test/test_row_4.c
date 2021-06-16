#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_4(CPU *cpu) {
    printf("Testing opcodes row 4.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.A = 1;
    cpu->next_state.A = 1;
    cpu->current_state.B = 0;
    cpu->next_state.B = 0;
    cpu->current_state.C = 3;
    cpu->next_state.C = 3;
    cpu->current_state.D = 4;
    cpu->next_state.D = 4;
    cpu->current_state.E = 5;
    cpu->next_state.E = 5;
    cpu->current_state.H = 6;
    cpu->next_state.H = 6;
    cpu->current_state.L = 7;
    cpu->next_state.L = 7;

    FILE *f = fopen("games/test/test_ops_row_4.gb", "rb");

    load_program(f, cpu);

    step(cpu); // LD B,B
    assert(cpu->current_state.B == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step(cpu); // LD B,C
    assert(cpu->current_state.B == cpu->current_state.C);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD B,D
    assert(cpu->current_state.B == cpu->current_state.D);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD B,E
    assert(cpu->current_state.B == cpu->current_state.E);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD B,H
    assert(cpu->current_state.B == cpu->current_state.H);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD B,L
    assert(cpu->current_state.B == cpu->current_state.L);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0xFF;
    
    step(cpu); // LD B,(HL)
    assert(cpu->current_state.B == cpu->RAM[cpu->current_state.HL]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD B,A
    assert(cpu->current_state.B == cpu->current_state.A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    cpu->current_state.B = 2;
    cpu->next_state.B = 2;
    cpu->current_state.C = 0;
    cpu->next_state.C = 0;

    step(cpu); // LD C,B
    assert(cpu->current_state.C == cpu->current_state.B);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step(cpu); // LD C,C
    assert(cpu->current_state.C == 2);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD C,D
    assert(cpu->current_state.C == cpu->current_state.D);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD C,E
    assert(cpu->current_state.C == cpu->current_state.E);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD C,H
    assert(cpu->current_state.C == cpu->current_state.H);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD C,L
    assert(cpu->current_state.C == cpu->current_state.L);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD C,(HL)
    assert(cpu->current_state.C == cpu->RAM[cpu->current_state.HL]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD C,A
    assert(cpu->current_state.C == cpu->current_state.A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    return 0;
}