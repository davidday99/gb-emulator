#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_rst(CPU *cpu) {
    printf("Testing RST.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_rst.gb", "rb");

    load_program(f, cpu);

    uint16_t prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RST 00H
    assert(cpu->registers.PC == 0);
    uint16_t *ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 1);

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RST 08H
    assert(cpu->registers.PC == 0x08); 
    ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 1);

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RST 10H
    assert(cpu->registers.PC == 0x10); 
    ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 1);

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RST 18H
    assert(cpu->registers.PC == 0x18); 
    ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 1));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 1);

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RST 20H
    assert(cpu->registers.PC == 0x20);
    ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 1)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 1);

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RST 28H
    assert(cpu->registers.PC == 0x28);
    ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 1)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 1);

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RST 30H
    assert(cpu->registers.PC == 0x30);
    ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 1)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 1);

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RST 38H
    assert(cpu->registers.PC == 0x38);
    ptr = (uint16_t*) &cpu->RAM[cpu->registers.SP];
    assert(*ptr == (uint16_t) (prev_PC + 1)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    return 0;
}