#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_jp(CPU *cpu) {
    printf("Testing JP.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_jp.gb", "rb");

    load_program(f, cpu);

    uint16_t prev_PC = cpu->registers.PC;
    step_cpu(cpu); // JP 0xC000
    assert(cpu->registers.PC == 0xC000);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 3);

    cpu->registers.F = 0xF0;

    /* These conditionals should execute */

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // JP Z,0xC000
    assert(cpu->registers.PC == 0xC000); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 3);

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // JP C,0xC000
    assert(cpu->registers.PC == 0xC000); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 3);

    cpu->registers.F = 0;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // JP NZ,0xC000
    assert(cpu->registers.PC == 0xC000); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 3);

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // JP NC,0xC000
    assert(cpu->registers.PC == 0xC000);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 3);

    /* These conditionals shouldn't execute */

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // JP Z,0xC000
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 3)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // JP C,0xC000
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 3)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0xF0;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // JP NZ,0xC000
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 3)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // JP NC,0xC000
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 3)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.HL = 0xC000;
    
    step_cpu(cpu); // JP (HL)
    assert(cpu->registers.PC == 0xC000); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 4);

    return 0;
}