#include <assert.h>
#include <stdio.h>
#include "../include/sm83.h"


int main() {
    Registers registers;

    /* test 8-bit and 16-bit addressability of register pair BC */
    registers.BC = 0xFFFF;
    assert(registers.BC  == 0xFFFF);
    assert(registers.B = 0xFF);
    assert(registers.C = 0xFF);

    registers.B = 0xBE;
    assert(registers.BC  == 0xBEFF);
    assert(registers.B = 0xBE);
    assert(registers.C = 0xFF);

    registers.C = 0xEF;
    assert(registers.BC  == 0xBEEF);
    assert(registers.B = 0xBE);
    assert(registers.C = 0xEF);

    printf("Test passed.\n");
}