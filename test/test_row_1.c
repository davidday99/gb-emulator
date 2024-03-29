#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_1(CPU *cpu) {
    printf("Testing opcodes row 1.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;
    cpu->current_state.BC = 0;
    cpu->next_state.BC = 0;
    cpu->current_state.DE = 0;
    cpu->next_state.DE = 0;
    cpu->current_state.HL = 0;
    cpu->next_state.HL = 0;

    FILE *f = fopen("games/test/test_ops_row_1.gb", "rb");

    load_program(f, cpu);
    
    step_cpu(cpu); // LD DE,0xBEEF
    assert(cpu->current_state.DE == 0xBEEF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // LD (DE),A
    assert(cpu->RAM[cpu->current_state.DE] == cpu->current_state.A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // INC DE
    assert(cpu->current_state.DE == 0xBEF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // INC D
    assert(cpu->current_state.DE = 0xBFF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // DEC D
    assert(cpu->current_state.DE = 0xBEF0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // LD D,0
    assert(cpu->current_state.B == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 0x80;
    cpu->next_state.A = 0x80;
    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // RLA
    assert(cpu->current_state.A == 0);
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint16_t prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR 0
    assert(cpu->current_state.PC == prev_PC + 2);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // ADD HL,DE
    assert(cpu->current_state.HL == cpu->current_state.DE);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[cpu->current_state.DE] = 0xCC;
    step_cpu(cpu); // LD A,(DE)
    assert(cpu->current_state.A == cpu->RAM[cpu->current_state.DE]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint16_t prev_DE = cpu->current_state.DE;
    step_cpu(cpu); // DEC DE
    assert(cpu->current_state.DE == prev_DE - 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint8_t prev_E = cpu->current_state.E;
    step_cpu(cpu); // INC E
    assert(cpu->current_state.E == prev_E + 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // DEC E
    assert(cpu->current_state.E == prev_E);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step_cpu(cpu); // LD E,0xFF
    assert(cpu->current_state.E == 0xFF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step_cpu(cpu); // RRA
    assert(cpu->current_state.A == 0xE6);
    assert(cpu->current_state.F == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // STOP
    assert(cpu->stopped == 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_PC = cpu->current_state.PC;
    step_cpu(cpu);
    assert(cpu->current_state.PC == prev_PC);

    return 0;
}