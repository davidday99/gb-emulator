#include <stdio.h>

#define NUM_TESTS 3

int test_get_register_value();
int test_registers();
int test_set_flag_register();

int (*tests[NUM_TESTS])() = {
    test_get_register_value,
    test_registers,
    test_set_flag_register
};




int main() {
    for (int i = 0; i < NUM_TESTS; i++) {
        int retval = (*tests[i])();
        if (retval == 0) {
            printf("Test passed.\n");
        }
    }
    printf("\nDone.\n");
    return 0;
}