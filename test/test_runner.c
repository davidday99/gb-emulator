#include <stdio.h>

#define NUM_TESTS 1
int test_row_0();

int (*tests[NUM_TESTS])() = {
    test_row_0
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