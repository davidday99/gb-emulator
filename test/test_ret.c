#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_ret(CPU *cpu) {
    printf("Testing RET.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_ret.gb", "rb");

    load_program(f, cpu);

    cpu->RAM[cpu->registers.SP - 1] = 0xC0;
    cpu->RAM[cpu->registers.SP - 2] = 0x00;
    cpu->registers.SP -= 2;

    uint16_t prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RET
    assert(cpu->registers.PC == 0xC000);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 1);

    cpu->registers.F = 0xF0;

    /* These conditionals should execute */

    cpu->registers.SP -= 2;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RET Z
    assert(cpu->registers.PC == 0xC000); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 20);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 1);

    cpu->registers.SP -= 2;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RET C
    assert(cpu->registers.PC == 0xC000); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 20);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 1);

    cpu->registers.F = 0;

    cpu->registers.SP -= 2;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RET NZ
    assert(cpu->registers.PC == 0xC000); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 20);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 1);

    cpu->registers.SP -= 2;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RET NC
    assert(cpu->registers.PC == 0xC000);
    assert(cpu->CYCLE_COUNT - prev_cycles == 20);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.PC = (uint16_t) (prev_PC + 1);

    /* These conditionals shouldn't execute */

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RET Z
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 1)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RET C
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 1)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0xF0;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RET NZ
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 1)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    prev_PC = cpu->registers.PC;
    step_cpu(cpu); // RET NC
    assert(cpu->registers.PC == (uint16_t) (prev_PC + 1)); 
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->interrupts_enabled = 0;
    cpu->registers.SP -= 2;

    step_cpu(cpu); // RETI
    assert(cpu->registers.PC == 0xC000); 
    assert(cpu->interrupts_enabled == 1);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    return 0;
}