#ifndef SM83_H_INCLUDE
#define SM83_H_INCLUDE

#include <stdint.h>

typedef struct Registers {
    uint8_t A;
    uint8_t F;

    union {
        struct {
            uint8_t C;
            uint8_t B;
        };
        uint16_t BC;
    };

    union {
        struct {
            uint8_t E;
            uint8_t D;
        };
        uint16_t DE;
    };

    
    union {
        struct {
            uint8_t L;
            uint8_t H;
        };
        uint16_t HL;
    };

    uint16_t SP;
    uint16_t PC;
} Registers;

#define FLAG_Z_MASK 0x80
#define FLAG_N_MASK 0x40
#define FLAG_H_MASK 0x20
#define FLAG_C_MASK 0x10

#endif /* SM83_H_INCLUDE */