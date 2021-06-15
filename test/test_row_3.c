#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_row_3(CPU *cpu) {
    printf("Testing opcodes row 3.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    cpu->current_state.A = 0xFF;
    cpu->next_state.A = 0xFF;

    FILE *f = fopen("games/test/test_ops_row_3.gb", "rb");

    load_program(f, cpu);

    step(cpu); // JR NC,0
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    
    step(cpu); // LD SP,0xBEEF
    assert(cpu->current_state.SP == 0xBEEF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint16_t prev_HL = cpu->current_state.HL;
    step(cpu); // LDD (HL),A
    assert(cpu->RAM[prev_HL] == cpu->current_state.A);
    assert(cpu->current_state.HL == (uint16_t) (prev_HL - 1));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.HL = prev_HL; // reset HL
    cpu->next_state.HL = prev_HL;

    uint16_t prev_SP = cpu->current_state.SP;
    step(cpu); // INC SP
    assert(cpu->current_state.SP == (uint16_t) (prev_SP + 1));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint8_t prev_ref_HL = cpu->RAM[cpu->current_state.HL];
    step(cpu); // INC (HL)
    assert(cpu->RAM[cpu->current_state.HL] == (uint8_t) (prev_ref_HL + 1));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step(cpu); // DEC (HL)
    assert(cpu->RAM[cpu->current_state.HL] == prev_ref_HL);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step(cpu); // LD (HL),d8
    assert(cpu->RAM[cpu->current_state.HL] == 0xFF);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // SCF
    assert(cpu->current_state.F == FLAG_C_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint16_t prev_PC = cpu->current_state.PC;
    step(cpu); // JR C,0
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_HL = cpu->current_state.HL;
    step(cpu); // ADD HL,SP
    assert(cpu->current_state.HL == cpu->current_state.SP);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_HL = cpu->current_state.HL;
    step(cpu); // LDD A,(HL)
    assert(cpu->current_state.A == cpu->RAM[prev_HL]);
    assert(cpu->current_state.HL == (uint16_t) (prev_HL - 1));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;
    cpu->current_state.HL = prev_HL; // reset HL
    cpu->next_state.HL = prev_HL;

    prev_SP = cpu->current_state.SP;
    step(cpu); // DEC SP
    assert(cpu->current_state.SP == (uint16_t) (prev_SP - 1));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    uint8_t prev_A = cpu->current_state.A;
    step(cpu); // INC A
    assert(cpu->current_state.A == (uint8_t) (prev_A + 1));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    step(cpu); // DEC A
    assert(cpu->current_state.A == prev_A);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 0;
    cpu->next_state.A = 0;
    step(cpu); // LD A,0x01
    assert(cpu->current_state.A == 0x01);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = FLAG_C_MASK;
    cpu->next_state.F = FLAG_C_MASK;
    step(cpu); // CCF
    assert(cpu->current_state.F == 0);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 4);

    return 0;
}