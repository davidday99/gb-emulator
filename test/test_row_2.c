#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_2(CPU *cpu) {
    printf("Testing opcodes row 2.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    FILE *f = fopen("games/test/test_ops_row_2.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // JR NZ,0
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD HL,0xBEEF
    assert(cpu->current_state.HL == 0xBEEF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint16_t prev_HL = cpu->current_state.HL;
    step_cpu(cpu); // LDI (HL),A
    assert(cpu->RAM[prev_HL] == cpu->current_state.A);
    assert(cpu->current_state.HL == prev_HL + 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.HL = prev_HL; // reset HL
    cpu->next_state.HL = prev_HL;


    step_cpu(cpu); // INC HL
    assert(cpu->current_state.HL == 0xBEF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // INC H
    assert(cpu->current_state.HL = 0xBFF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // DEC HL
    assert(cpu->current_state.HL = 0xBEF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // LD H,0
    assert(cpu->current_state.H == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 0x5C;
    cpu->next_state.A = 0x5C;
    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // DAA
    assert(cpu->current_state.A == 0x62);
    assert(cpu->current_state.F == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint16_t prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR Z,0
    assert(cpu->current_state.PC == prev_PC + 2);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_HL = cpu->current_state.HL;
    step_cpu(cpu); // ADD HL,HL
    assert(cpu->current_state.HL == (prev_HL * 2));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_HL = cpu->current_state.HL;
    cpu->RAM[cpu->current_state.HL] = 0xCC;
    step_cpu(cpu); // LDI A,(HL)
    assert(cpu->current_state.HL == prev_HL + 1);
    assert(cpu->current_state.A == cpu->RAM[prev_HL]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_HL = cpu->current_state.HL;
    step_cpu(cpu); // DEC HL
    assert(cpu->current_state.HL == prev_HL - 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint8_t prev_L = cpu->current_state.L;
    step_cpu(cpu); // INC L
    assert(cpu->current_state.L == prev_L + 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // DEC L
    assert(cpu->current_state.L == prev_L);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // LD L,0xFF
    assert(cpu->current_state.L == 0xFF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint8_t prev_A = cpu->current_state.A;
    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // CPL
    assert(cpu->current_state.A == (uint8_t) ~prev_A);
    assert(cpu->current_state.F == (FLAG_N_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);

    return 0;
}