#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_6(CPU *cpu) {
    printf("Testing opcodes row 6.\n");

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
    cpu->current_state.L = 7;
    cpu->next_state.L = 7;

    FILE *f = fopen("games/test/test_ops_row_6.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // LD H,B
    assert(cpu->current_state.H == cpu->current_state.B);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // LD H,C
    assert(cpu->current_state.H == cpu->current_state.C);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD H,D
    assert(cpu->current_state.H == cpu->current_state.D);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD H,E
    assert(cpu->current_state.H == cpu->current_state.E);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD H,H
    assert(cpu->current_state.H == 5);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD H,L
    assert(cpu->current_state.H == cpu->current_state.L);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0xFF;
    
    step_cpu(cpu); // LD H,(HL)
    assert(cpu->current_state.H == 0xFF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD H,A
    assert(cpu->current_state.H == cpu->current_state.A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    cpu->current_state.H = 6;
    cpu->next_state.H = 6;
    cpu->current_state.L = 0;
    cpu->next_state.L = 0;

    step_cpu(cpu); // LD L,B
    assert(cpu->next_state.L == cpu->current_state.B);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // LD L,C
    assert(cpu->next_state.L == cpu->current_state.C);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD L,D
    assert(cpu->next_state.L == cpu->current_state.D);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD L,E
    assert(cpu->next_state.L == cpu->current_state.E);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD L,H
    assert(cpu->next_state.L == cpu->current_state.H);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD L,L
    assert(cpu->next_state.L == 6);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0xFF;
    
    step_cpu(cpu); // LD L,(HL)
    assert(cpu->next_state.L == 0xFF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD L,A
    assert(cpu->next_state.L == cpu->current_state.A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    return 0;
}