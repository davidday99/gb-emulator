#include <stdio.h>
#include "../include/cpu.h"

/**
 *  Opcodes are organized into rows based on the table from
 *  https://www.pastraiser.com/cpu/gameboy/gameboy_opcodes.html
 */

#define NUM_TESTS 32
int test_row_0(CPU *cpu);
int test_row_1(CPU *cpu);
int test_row_2(CPU *cpu);
int test_row_3(CPU *cpu);
int test_row_4(CPU *cpu);
int test_row_5(CPU *cpu);
int test_row_6(CPU *cpu);
int test_row_7(CPU *cpu);
int test_row_8(CPU *cpu);
int test_row_9(CPU *cpu);
int test_row_a(CPU *cpu);
int test_row_b(CPU *cpu);
int test_row_c(CPU *cpu);
int test_row_d(CPU *cpu);
int test_row_e(CPU *cpu);
int test_row_f(CPU *cpu);

int test_cb_row_0(CPU *cpu);
int test_cb_row_1(CPU *cpu);
int test_cb_row_2(CPU *cpu);
int test_cb_row_3(CPU *cpu);
int test_cb_row_4(CPU *cpu);
int test_cb_row_5(CPU *cpu);
int test_cb_row_6(CPU *cpu);
int test_cb_row_7(CPU *cpu);
int test_cb_row_8(CPU *cpu);
int test_cb_row_9(CPU *cpu);
int test_cb_row_a(CPU *cpu);
int test_cb_row_b(CPU *cpu);
int test_cb_row_c(CPU *cpu);
int test_cb_row_d(CPU *cpu);
int test_cb_row_e(CPU *cpu);
int test_cb_row_f(CPU *cpu);

int (*tests[NUM_TESTS])(CPU *cpu) = {
    test_row_0,
    test_row_1,
    test_row_2,
    test_row_3,
    test_row_4,
    test_row_5,
    test_row_6,
    test_row_7,
    test_row_8,
    test_row_9,
    test_row_a,
    test_row_b,
    test_row_c,
    test_row_d,
    test_row_e,
    test_row_f,
    test_cb_row_0,
    test_cb_row_1,
    test_cb_row_2,
    test_cb_row_3,
    test_cb_row_4,
    test_cb_row_5,
    test_cb_row_6,
    test_cb_row_7,
    test_cb_row_8,
    test_cb_row_9,
    test_cb_row_a,
    test_cb_row_b,
    test_cb_row_c,
    test_cb_row_d,
    test_cb_row_e,
    test_cb_row_f
};

int main() {
    CPU cpu;
    for (int i = 0; i < NUM_TESTS; i++) {
        int retval = (*tests[i])(&cpu);
        if (retval == 0) {
            printf("Test passed.\n");
        }
    }
    printf("\nDone.\n");
    return 0;
}