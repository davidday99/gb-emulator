#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_0(CPU *cpu) {
    printf("Testing opcodes row 0.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.A = 0xFF;
    cpu->current_state.BC = 0;
    cpu->next_state.BC = 0;
    cpu->current_state.DE = 0;
    cpu->next_state.DE = 0;
    cpu->current_state.HL = 0;
    cpu->next_state.HL = 0;

    FILE *f = fopen("games/test/test_ops_row_0.gb", "rb");

    load_program(f, cpu);

    step_cpu(cpu); // NOP
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step_cpu(cpu); // LD BC,0xBEEF
    assert(cpu->current_state.BC == 0xBEEF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // LD (BC),A
    assert(cpu->RAM[cpu->current_state.BC] == cpu->current_state.A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // INC BC
    assert(cpu->current_state.BC == 0xBEF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // INC B
    assert(cpu->current_state.BC = 0xBFF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // DEC B
    assert(cpu->current_state.BC = 0xBEF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // LD B,0
    assert(cpu->current_state.B == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 0x80;
    cpu->next_state.A = 0x80;
    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // RLCA
    assert(cpu->current_state.A == 1);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.SP = 1;
    cpu->next_state.SP = 1;
    step_cpu(cpu); // LD (0xBEEF),SP
    assert(cpu->RAM[0xBEEF] == cpu->current_state.SP);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 20);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // ADD HL,BC
    assert(cpu->current_state.HL == cpu->current_state.BC);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.BC] = 0xCC;
    step_cpu(cpu); // LD A,(BC)
    assert(cpu->current_state.A == cpu->RAM[cpu->current_state.BC]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint16_t prev_BC = cpu->current_state.BC;
    step_cpu(cpu); // DEC BC
    assert(cpu->current_state.BC == prev_BC - 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint8_t prev_C = cpu->current_state.C;
    step_cpu(cpu); // INC C
    assert(cpu->current_state.C == prev_C + 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // DEC C
    assert(cpu->current_state.C == prev_C);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // LD C,0xFF
    assert(cpu->current_state.C == 0xFF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // RRCA
    assert(cpu->current_state.A == 0x66);
    assert(cpu->current_state.F == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);

    return 0;
}