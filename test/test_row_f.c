#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_f(CPU *cpu) {
    printf("Testing opcodes row F.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.SP = 0xFFFD;
    cpu->next_state.SP = 0xFFFD;

    FILE *f = fopen("games/test/test_ops_row_f.gb", "rb");

    load_program(f, cpu);

    cpu->current_state.A = 0;
    cpu->next_state.A = 0;
    cpu->RAM[0xFF01] = 0xFF;
    step(cpu); // LDH A,(0x01)
    assert(cpu->current_state.A == cpu->RAM[0xFF01]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;


    cpu->RAM[0xFFFD] = 0xFF; // will pop into F register
    cpu->RAM[0xFFFE] = 0x01; // will pop into A register

    uint16_t prev_SP = cpu->current_state.SP;
    step(cpu); // POP AF
    assert(cpu->current_state.AF == 0x01FF);
    assert(cpu->current_state.SP == (uint16_t) (prev_SP + 2));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;


    cpu->RAM[0xFF02] = 0xCC;
    cpu->current_state.C = 2;
    cpu->next_state.C = 2;
    step(cpu); // LD A,(C)
    assert(cpu->current_state.A == cpu->RAM[0xFF02]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step(cpu); // DI
    assert(cpu->interrupts_enabled == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_SP = cpu->current_state.SP;
    cpu->current_state.AF = 0xFEED;
    cpu->next_state.AF = 0xFEED;
    step(cpu); // PUSH AF
    assert(cpu->current_state.SP == (uint16_t) (prev_SP - 2));
    uint16_t *ptr = (uint16_t*) &cpu->RAM[cpu->current_state.SP];
    assert(*ptr == 0xFEED);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint8_t prev_A = cpu->current_state.A;
    step(cpu); // OR 0x55
    assert(cpu->current_state.A == (uint8_t) (prev_A | 0x55));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step(cpu); // LDHL SP,1
    assert(cpu->current_state.HL == (uint16_t) (cpu->current_state.SP + 1));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step(cpu); // LD SP,HL
    assert(cpu->current_state.SP == cpu->current_state.HL);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->RAM[0xFF03] = 0xCC;
    step(cpu); // LD A,(0xFF03)
    assert(cpu->current_state.A == cpu->RAM[0xFF03]);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step(cpu); // EI
    assert(cpu->interrupts_enabled == 1);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_A = cpu->current_state.A;
    step(cpu); // CP A,0xFF
    assert(cpu->current_state.A == prev_A);
    assert((cpu->current_state.F & 0xF0) == (FLAG_N_MASK | FLAG_C_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);

    return 0;
}