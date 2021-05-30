#include <assert.h>
#include <stdio.h>
#include "../include/cpu.h"


int main() {
    CPU cpu;

    /* test 8-bit and 16-bit addressability of register pair BC */
    cpu.BC = 0xFFFF;
    assert(cpu.BC  == 0xFFFF);
    assert(cpu.B = 0xFF);
    assert(cpu.C = 0xFF);

    cpu.B = 0xBE;
    assert(cpu.BC  == 0xBEFF);
    assert(cpu.B = 0xBE);
    assert(cpu.C = 0xFF);

    cpu.C = 0xEF;
    assert(cpu.BC  == 0xBEEF);
    assert(cpu.B = 0xBE);
    assert(cpu.C = 0xEF);

    printf("Test passed.\n");
}