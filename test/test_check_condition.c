#include <assert.h>
#include <stdio.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

uint8_t check_condition(CPU *cpu, enum condition cc) {
    uint8_t cond = 0;
    switch (cc) {
        case UNCONDITIONAL:
            cond = 1;
            break;
        case NZ:
            cond = (cpu->current_state.F & FLAG_Z_MASK) == 0;
            break;
        case Z:
            cond = (cpu->current_state.F & FLAG_Z_MASK) != 0;
            break;
        case NC:
            cond = (cpu->current_state.F & FLAG_C_MASK) == 0;
            break;
        case CARRY:
            cond = (cpu->current_state.F & FLAG_C_MASK) != 0;
            break;
        default:
            break;
    }
    return cond;
}

int test_check_condition() {
    printf("Running test_check_condition()\n");

    CPU cpu;

    cpu.current_state.F = 0x00;

    assert(check_condition(&cpu, NZ) == 1);
    assert(check_condition(&cpu, Z) == 0);

    cpu.current_state.F = 0x80;

    assert(check_condition(&cpu, NZ) == 0);
    assert(check_condition(&cpu, Z) == 1);

    assert(check_condition(&cpu, NC) == 1);
    assert(check_condition(&cpu, CARRY) == 0);

    cpu.current_state.F = 0x10;

    assert(check_condition(&cpu, NC) == 0);
    assert(check_condition(&cpu, CARRY) == 1);

    return 0;
}