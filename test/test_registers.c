#include <assert.h>
#include <stdio.h>
#include "../include/cpu.h"


int test_registers() {
    printf("Running test_registers()\n");

    CPU cpu;

    /* test 8-bit and 16-bit addressability of register pair BC */
    cpu.current_state.BC = 0xFFFF;
    assert(cpu.current_state.BC  == 0xFFFF);
    assert(cpu.current_state.B = 0xFF);
    assert(cpu.current_state.C = 0xFF);

    cpu.current_state.B = 0xBE;
    assert(cpu.current_state.BC  == 0xBEFF);
    assert(cpu.current_state.B = 0xBE);
    assert(cpu.current_state.C = 0xFF);

    cpu.current_state.C = 0xEF;
    assert(cpu.current_state.BC  == 0xBEEF);
    assert(cpu.current_state.B = 0xBE);
    assert(cpu.current_state.C = 0xEF);

    return 0;
}