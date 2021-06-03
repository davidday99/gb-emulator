#include <stdio.h>
#include <assert.h>
#include "../include/cpu.h"

#define FLAG_Z_MASK 0x80
#define FLAG_N_MASK 0x40
#define FLAG_H_MASK 0x20
#define FLAG_C_MASK 0x10
#define NO_FLAGS 0

/************************************************************/
/*                                                          */
/* FLAG REGISTER FUNCTIONS                                  */
/*                                                          */
/************************************************************/

void set_z_flag(CPU *cpu, uint8_t z) {
    uint8_t is_zero = !z;
    if (is_zero) {
        cpu->next_state.F |= FLAG_Z_MASK;
    } else {
        cpu->next_state.F &= ~FLAG_Z_MASK;
    }
}

void set_n_flag(CPU *cpu, uint8_t n) {
    if (n == 1) {
        cpu->next_state.F |= FLAG_N_MASK;
    } else {
        cpu->next_state.F &= ~FLAG_N_MASK;
    }
}

void set_h_flag(CPU *cpu, uint8_t h) {
    if (h == 1) {
        cpu->next_state.F |= FLAG_H_MASK;
    } else {
        cpu->next_state.F &= ~FLAG_H_MASK;
    }
}

void set_c_flag(CPU *cpu, uint8_t c) {
    if (c == 1) {
        cpu->next_state.F |= FLAG_C_MASK;
    } else {
        cpu->next_state.F &= ~FLAG_C_MASK;
    }
}

void set_flags(CPU *cpu, uint8_t flag_mask, uint8_t z, uint8_t n, uint8_t h, uint8_t c) {
    if (flag_mask & FLAG_Z_MASK) {
        set_z_flag(cpu, z);
    }
    if (flag_mask & FLAG_N_MASK) {
        set_n_flag(cpu, n);
    }
    if (flag_mask & FLAG_H_MASK) {
        set_h_flag(cpu, h);
    }
    if (flag_mask & FLAG_C_MASK) {
        set_c_flag(cpu, c);
    }
}

int test_set_flag_register() {
    printf("Running test_set_flags_register()\n");

    CPU cpu;

    cpu.current_state.F = 0;
    cpu.next_state.F = 0;

    /* Set each individual flag and check that other flags aren't overwritten */

    /* Set Z flag */

    int zero = 0;

    set_flags(&cpu, FLAG_Z_MASK, zero, 1, 1, 1);

    assert(cpu.next_state.F == FLAG_Z_MASK);

    /* Set N flag */

    set_flags(&cpu, FLAG_N_MASK, 0, 1, 1, 1);

    assert(cpu.next_state.F == (FLAG_Z_MASK | FLAG_N_MASK));

    /* Set H flag */

    set_flags(&cpu, FLAG_H_MASK, 0, 0, 1, 1);

    assert(cpu.next_state.F == (FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK));

    /* Set H flag */

    set_flags(&cpu, FLAG_C_MASK, 0, 0, 0, 1);

    assert(cpu.next_state.F == (FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK | FLAG_C_MASK));

    return 0;
}