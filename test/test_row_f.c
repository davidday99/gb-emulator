#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_f(CPU *cpu) {
    printf("Testing opcodes row F.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->registers.SP = 0xFFFD;

    FILE *f = fopen("games/test/test_ops_row_f.gb", "rb");

    load_program(f, cpu);

    cpu->registers.A = 0;
    cpu->RAM[0xFF01] = 0xFF;
    step_cpu(cpu); // LDH A,(0x01)
    assert(cpu->registers.A == cpu->RAM[0xFF01]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[0xFFFD] = 0xFF; // will pop into F register
    cpu->RAM[0xFFFE] = 0x01; // will pop into A register

    uint16_t prev_SP = cpu->registers.SP;
    step_cpu(cpu); // POP AF
    assert(cpu->registers.AF == 0x01FF);
    assert(cpu->registers.SP == (uint16_t) (prev_SP + 2));
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;


    cpu->RAM[0xFF02] = 0xCC;
    cpu->registers.C = 2;
    step_cpu(cpu); // LD A,(C)
    assert(cpu->registers.A == cpu->RAM[0xFF02]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // DI
    assert(cpu->interrupts_enabled == 0);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_SP = cpu->registers.SP;
    cpu->registers.AF = 0xFEED;
    step_cpu(cpu); // PUSH AF
    assert(cpu->registers.SP == (uint16_t) (prev_SP - 2));
    uint16_t *ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == 0xFEED);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    uint8_t prev_A = cpu->registers.A;
    step_cpu(cpu); // OR 0x55
    assert(cpu->registers.A == (uint8_t) (prev_A | 0x55));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LDHL SP,1
    assert(cpu->registers.HL == (uint16_t) (cpu->registers.SP + 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // LD SP,HL
    assert(cpu->registers.SP == cpu->registers.HL);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->RAM[0xFF03] = 0xCC;
    step_cpu(cpu); // LD A,(0xFF03)
    assert(cpu->registers.A == cpu->RAM[0xFF03]);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    step_cpu(cpu); // EI
    assert(cpu->interrupts_enabled == 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_A = cpu->registers.A;
    step_cpu(cpu); // CP A,0xFF
    assert(cpu->registers.A == prev_A);
    assert((cpu->registers.F & 0xF0) == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);

    return 0;
}