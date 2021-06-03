#include <assert.h>
#include <stdio.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

uint16_t get_register_value(enum operand reg, CPU *cpu) {
    uint16_t value;
    switch (reg) {
        case A:
            value = cpu->current_state.A;
            break;
        case B:
            value = cpu->current_state.B;
            break;
        case C:
            value = cpu->current_state.C;
            break;
        case D:
            value = cpu->current_state.D;
            break;
        case E:
            value = cpu->current_state.E;
            break;
        case H:
            value = cpu->current_state.H;
            break;
        case L:
            value = cpu->current_state.L;
            break;
        case AF:
            value = cpu->current_state.AF;
            break;
        case BC:
            value = cpu->current_state.BC;
            break;
        case DE:
            value = cpu->current_state.DE;
            break;
        case HL:
            value = cpu->current_state.HL;
            break;
        case PC:
            value = cpu->current_state.PC;
            break;
        case SP:
            value = cpu->current_state.SP;
            break;
    }
    return value;
}

int test_get_register_value() {
    printf("Running test_get_register_value()\n");

    CPU cpu;
    cpu.current_state.AF = 0xFFFF;
    cpu.current_state.BC = 0xFFFF;
    cpu.current_state.DE = 0xFFFF;
    cpu.current_state.HL = 0xFFFF;
    
    assert(get_register_value(AF, &cpu) == 0xFFFF);
    assert((uint8_t) get_register_value(A, &cpu) == 0xFF);
    assert((uint8_t) get_register_value(B, &cpu) == 0xFF);
    assert((uint8_t) get_register_value(C, &cpu) == 0xFF);
    assert((uint8_t) get_register_value(D, &cpu) == 0xFF);
    assert((uint8_t) get_register_value(E, &cpu) == 0xFF);
    assert((uint8_t) get_register_value(H, &cpu) == 0xFF);
    assert((uint8_t) get_register_value(L, &cpu) == 0xFF);

    return 0;
}
