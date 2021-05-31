#include <stdio.h>
#include <assert.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int main() {
    CPU cpu;

    cpu.current_state.F = 0;
    cpu.next_state.F = 0;

    /* Set each individual flag and check that other flags aren't overwritten */

    /* Set Z flag */

    set_flag_register(&cpu, FLAG_Z_MASK, 1, 1, 1, 1);

    assert(cpu.next_state.F == FLAG_Z_MASK);

    /* Set N flag */

    set_flag_register(&cpu, FLAG_N_MASK, 0, 1, 1, 1);

    assert(cpu.next_state.F == (FLAG_Z_MASK | FLAG_N_MASK));

    /* Set H flag */

    set_flag_register(&cpu, FLAG_H_MASK, 0, 0, 1, 1);

    assert(cpu.next_state.F == (FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK));

    /* Set H flag */

    set_flag_register(&cpu, FLAG_C_MASK, 0, 0, 0, 1);

    assert(cpu.next_state.F == (FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK | FLAG_C_MASK));

    printf("Test passed.\n");
}