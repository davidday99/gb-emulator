#include <stdio.h>
#include "../include/cpu.h"

#define NUM_TESTS 1
int test_row_0(CPU *cpu);

int (*tests[NUM_TESTS])(CPU *cpu) = {
    test_row_0,
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