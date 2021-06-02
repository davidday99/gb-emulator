#include <stdint.h>
#include "../include/isa-sm83.h"

const Instruction INSTRUCTIONS[] = {
    {"NOP", 0x00, NONE, NA, NONE, NA, MISC, UNCONDITIONAL, 4, 0, 1},
    {"LD BC, d16", 0x01, BC, REGISTER, D16, IMMEDIATE_MEM, LD_ST_MOV, UNCONDITIONAL, 3},
};

const Instruction CB_INSTRUCTIONS[];

