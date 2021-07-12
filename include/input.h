#ifndef INPUT_H
#define INPUT_H

#include <stdint.h>

#define P10_IN_PORT_MASK 0
#define P11_IN_PORT_MASK 2
#define P12_IN_PORT_MASK 4
#define P13_IN_PORT_MASK 8
#define P14_OUT_PORT_MASK 16 
#define P15_OUT_PORT_MASK 32

enum Buttons {
    RIGHT,
    LEFT = 2,
    UP = 4,
    DOWN = 8,
    A = 0,
    B = 2,
    SELECT = 4,
    START = 8
};

typedef struct Input {
    uint8_t *p1;
} Input;

#endif /* INPUT_H */
