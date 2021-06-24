#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_jr(CPU *cpu) {
    printf("Testing JR.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_jr.gb", "rb");

    load_program(f, cpu);

    uint16_t prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR 2
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2 + 2)); // 2 bytes for instruction, 1 byte for jump
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR -4
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2 - 4)); 
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR 2
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2 + 2)); 
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR 0
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2)); 
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;



    cpu->current_state.F = 0;
    cpu->next_state.F = 0;

    /* These conditionals shouldn't execute */

    prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR Z,0
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2)); 
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR C,0
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2)); 
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0xF0;
    cpu->next_state.F = 0xF0;

    prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR NZ,0
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR NC,0
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2)); 
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    /* These conditionals should execute */

    prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR Z,0
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2)); 
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR C,0
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2)); 
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;

    prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR NZ,0
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    prev_PC = cpu->current_state.PC;
    step_cpu(cpu); // JR NC,0
    assert(cpu->current_state.PC == (uint16_t) (prev_PC + 2)); 
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    return 0;
}