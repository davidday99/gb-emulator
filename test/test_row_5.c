#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_5(CPU *cpu) {
    printf("Testing opcodes row 5.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.A = 1;
    cpu->next_state.A = 1;
    cpu->current_state.B = 2;
    cpu->next_state.B = 2;
    cpu->current_state.C = 3;
    cpu->next_state.C = 3;
    cpu->current_state.D = 0;
    cpu->next_state.D = 0;
    cpu->current_state.E = 5;
    cpu->next_state.E = 5;
    cpu->current_state.H = 6;
    cpu->next_state.H = 6;
    cpu->current_state.L = 7;
    cpu->next_state.L = 7;

    FILE *f = fopen("games/test/test_ops_row_5.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // LD D,B
    assert(cpu->current_state.D == cpu->current_state.B);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // LD D,C
    assert(cpu->current_state.D == cpu->current_state.C);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD D,D
    assert(cpu->current_state.D == 3);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD D,E
    assert(cpu->current_state.D == cpu->current_state.E);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD D,H
    assert(cpu->current_state.D == cpu->current_state.H);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD D,L
    assert(cpu->current_state.D == cpu->current_state.L);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.HL] = 0xFF;
    
    step_cpu(cpu); // LD D,(HL)
    assert(cpu->current_state.D == cpu->RAM[cpu->current_state.HL]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD D,A
    assert(cpu->current_state.D == cpu->current_state.A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    cpu->current_state.D = 4;
    cpu->next_state.D = 4;
    cpu->current_state.E = 0;
    cpu->next_state.E = 0;

    step_cpu(cpu); // LD E,B
    assert(cpu->next_state.E == cpu->current_state.B);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // LD E,C
    assert(cpu->next_state.E == cpu->current_state.C);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD E,D
    assert(cpu->next_state.E == cpu->current_state.D);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD E,E
    assert(cpu->next_state.E == 4);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD E,H
    assert(cpu->next_state.E == cpu->current_state.H);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD E,L
    assert(cpu->next_state.E == cpu->current_state.L);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD E,(HL)
    assert(cpu->next_state.E == cpu->RAM[cpu->current_state.HL]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD E,A
    assert(cpu->next_state.E == cpu->current_state.A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    return 0;
}