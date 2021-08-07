#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_e(CPU *cpu) {
    printf("Testing opcodes row E.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.SP = 0xFFFD;

    FILE *f = fopen("games/test/test_ops_row_e.gb", "rb");

    load_program(f, cpu);

    cpu->registers.A = 0xFF;
    step_cpu(cpu); // LDH (0x01),A
    assert(cpu->RAM[0xFF01] == cpu->registers.A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[0xFFFE] = 0xBE;
    cpu->RAM[0xFFFD] = 0xEF;

    uint16_t prev_SP = cpu->registers.SP;
    step_cpu(cpu); // POP HL
    assert(cpu->registers.HL == 0xBEEF);
    assert(cpu->registers.SP == (uint16_t) (prev_SP + 2));
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.C = 2;
    step_cpu(cpu); // LD (C),A
    assert(cpu->RAM[0xFF02] == cpu->registers.A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_SP = cpu->registers.SP;
    cpu->registers.HL = 0xFEED;
    step_cpu(cpu); // PUSH HL
    assert(cpu->registers.SP == (uint16_t) (prev_SP - 2));
    uint16_t *ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == 0xFEED);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    uint8_t prev_A = cpu->registers.A;
    step_cpu(cpu); // AND 0x55
    assert(cpu->registers.A == (uint8_t) (prev_A & 0x55));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_SP = cpu->registers.SP;
    step_cpu(cpu); // ADD SP,1
    assert(cpu->registers.SP == (uint16_t) (prev_SP + 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.A = 0xFF;
    step_cpu(cpu); // LD (0xFF03),A
    assert(cpu->RAM[0xFF03] == cpu->registers.A);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_A = cpu->registers.A;
    step_cpu(cpu); // XOR A,0xFF
    assert(cpu->registers.A == (uint8_t) (prev_A ^ 0xFF));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);

    return 0;
}