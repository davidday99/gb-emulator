#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../../include/cpu.h"
#include "../../include/isa-sm83.h"

int row_0() {
    CPU cpu;
    init_cpu(&cpu);

    int prev_cycles = 0;

    cpu.current_state.A = 0xFF;
    cpu.next_state.A = 0xFF;

    FILE *f = fopen("games/test/test_ops_row_0.gb", "rb");

    load_program(f, &cpu);

    step(&cpu); // NOP
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu.current_state.CYCLE_COUNT;
    
    step(&cpu); // LD BC,0xBEEF
    assert(cpu.current_state.BC == 0xBEEF);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    step(&cpu); // LD (BC),A
    assert(cpu.RAM[cpu.current_state.BC] == cpu.current_state.A);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    step(&cpu); // INC BC
    assert(cpu.current_state.BC == 0xBEF0);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    step(&cpu); // INC B
    assert(cpu.current_state.BC = 0xBFF0);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    step(&cpu); // DEC B
    assert(cpu.current_state.BC = 0xBEF0);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    step(&cpu); // LD B,0
    assert(cpu.current_state.B == 0);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    cpu.current_state.A = 0x80;
    cpu.next_state.A = 0x80;
    cpu.current_state.F = 0;
    cpu.next_state.F = 0;
    step(&cpu); // RLCA
    assert(cpu.current_state.A == 1);
    assert(cpu.current_state.F == FLAG_C_MASK);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    cpu.current_state.SP = 1;
    cpu.next_state.SP = 1;
    step(&cpu); // LD (0xBEEF),SP
    assert(cpu.RAM[0xBEEF] == cpu.current_state.SP);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 20);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    step(&cpu); // ADD HL,BC
    assert(cpu.current_state.HL == cpu.current_state.BC);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    cpu.RAM[cpu.current_state.BC] = 0xCC;
    step(&cpu); // LD A,(BC)
    assert(cpu.current_state.A == cpu.RAM[cpu.current_state.BC]);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    uint16_t prev_BC = cpu.current_state.BC;
    step(&cpu); // DEC BC
    assert(cpu.current_state.BC == prev_BC - 1);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    uint8_t prev_C = cpu.current_state.C;
    step(&cpu); // INC C
    assert(cpu.current_state.C == prev_C + 1);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    step(&cpu); // DEC B
    assert(cpu.current_state.C == prev_C);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 4);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    step(&cpu); // LD C,0xFF
    assert(cpu.current_state.C == 0xFF);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu.current_state.CYCLE_COUNT;

    cpu.current_state.F = FLAG_C_MASK;
    cpu.next_state.F = FLAG_C_MASK;
    step(&cpu); // RRCA
    assert(cpu.current_state.A == 0x66);
    assert(cpu.current_state.F == 0);
    assert(cpu.current_state.CYCLE_COUNT - prev_cycles == 4);

    return 0;
}