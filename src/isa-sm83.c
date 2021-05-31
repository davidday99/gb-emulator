#include <stdint.h>
#include "../include/isa-sm83.h"

const Instruction INSTRUCTIONS[] = {
    {"NOP", NOP, 0, 0, 1, 4},
    {"LD BC,d16", LD_BC_D16, 2, 0, 3, 12},
    {"LD (BC),A", LD_BC_A, 0, 0, 1, 8},
    {"INC BC", INC_BC, 0, 0, 1, 8},
    {"INC B", INC_B, 0, 0, 1, 4},
    {"DEC B", DEC_B, 0, 0, 1, 4},
    {"LD B,d8", LD_B_D8, 1, 0, 2, 8}
};

const Instruction CB_INSTRUCTIONS[] = {

};

