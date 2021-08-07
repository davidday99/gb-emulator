#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_call(CPU *cpu) {
    printf("Testing CALL.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_call.gb", "rb");

    load_program(f, cpu);

    uint16_t prev_PC = cpu->registers.PC;
    step_cpu(cpu); // CALL 0xC000
    assert(cpu->registers.PC == 0xC000);
    uint16_t *ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 3));
    assert(cpu->CYCLE_COUNT - prev_cycles == 24);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 3);

    cpu->registers.F = 0xF0;

    /* These conditionals should execute */

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // CALL Z,0xC000
    assert(cpu->registers.PC == 0xC000); 
    ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 3));
    assert(cpu->CYCLE_COUNT - prev_cycles == 24);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 3);

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // CALL C,0xC000
    assert(cpu->registers.PC == 0xC000); 
    ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 3));
    assert(cpu->CYCLE_COUNT - prev_cycles == 24);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 3);

    cpu->registers.F = 0;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // CALL NZ,0xC000
    assert(cpu->registers.PC == 0xC000); 
    ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 3));
    assert(cpu->CYCLE_COUNT - prev_cycles == 24);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 3);

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // CALL NC,0xC000
    assert(cpu->registers.PC == 0xC000);
    ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 3)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 24);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 3);

    /* These conditionals shouldn't execute */

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // CALL Z,0xC000
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 3)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // CALL C,0xC000
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 3)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0xF0;
    cpu->registers.F = 0xF0;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // CALL NZ,0xC000
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 3)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // CALL NC,0xC000
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 3)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 12);
    prev_cycles = cpu->CYCLE_COUNT;

    return 0;
}