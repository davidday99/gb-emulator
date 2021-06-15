#include <stdio.h>
#include "../include/cpu.h"

#define NUM_TESTS 3
int test_row_0(CPU *cpu);
int test_row_1(CPU *cpu);
int test_row_2(CPU *cpu);

int (*tests[NUM_TESTS])(CPU *cpu) = {
    test_row_1,
    test_row_0,
    test_row_2
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