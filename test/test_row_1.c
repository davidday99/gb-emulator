#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_1(CPU *cpu) {
    printf("Testing opcodes row 1.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.A = 0xFF;
    cpu->registers.BC = 0;
    cpu->registers.DE = 0;
    cpu->registers.HL = 0;

    FILE *f = fopen("games/test/test_ops_row_1.gb", "rb");

    load_program(f, cpu);
    
    step_cpu(cpu); // LD DE,0xBEEF
    assert(cpu->registers.DE == 0xBEEF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD (DE),A
    assert(cpu->RAM[cpu->registers.DE] == cpu->registers.A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // INC DE
    assert(cpu->registers.DE == 0xBEF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // INC D
    assert(cpu->registers.DE = 0xBFF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // DEC D
    assert(cpu->registers.DE = 0xBEF0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD D,0
    assert(cpu->registers.B == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.A = 0x80;
    cpu->registers.F = 0;
    step_cpu(cpu); // RLA
    assert(cpu->registers.A == 0);
    assert(cpu->registers.F == FLAG_C_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    uint16_t prev_PC = cpu->registers.PC;
    step_cpu(cpu); // JR 0
    assert(cpu->registers.PC == prev_PC + 2);
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // ADD HL,DE
    assert(cpu->registers.HL == cpu->registers.DE);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[cpu->registers.DE] = 0xCC;
    step_cpu(cpu); // LD A,(DE)
    assert(cpu->registers.A == cpu->RAM[cpu->registers.DE]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    uint16_t prev_DE = cpu->registers.DE;
    step_cpu(cpu); // DEC DE
    assert(cpu->registers.DE == prev_DE - 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    uint8_t prev_E = cpu->registers.E;
    step_cpu(cpu); // INC E
    assert(cpu->registers.E == prev_E + 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // DEC E
    assert(cpu->registers.E == prev_E);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD E,0xFF
    assert(cpu->registers.E == 0xFF);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = FLAG_C_MASK;
    step_cpu(cpu); // RRA
    assert(cpu->registers.A == 0xE6);
    assert(cpu->registers.F == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // STOP
    assert(cpu->stopped == 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_PC = cpu->registers.PC;
    step_cpu(cpu);
    assert(cpu->registers.PC == prev_PC);

    return 0;
}