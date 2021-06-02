#include <stdint.h>
#include "../include/isa-sm83.h"

const Instruction INSTRUCTIONS[] = {
    {"NOP", OPCODE_NOP, NONE, NA, NONE, NA, NOP, MISC, UNCONDITIONAL, 0, 1},
    {"LD BC, d16", OPCODE_LD_BC_D16, BC, REGISTER, D16, IMMEDIATE_MEM, LD, LD_ST_MOV, UNCONDITIONAL, 0, 3},
    {"LD (BC),A", OPCODE_LD_REF_BC_A, BC, REGISTER_INDIRECT, A, REGISTER, LD, LD_ST_MOV, UNCONDITIONAL, 0, 3},
    {"INC BC", OPCODE_INC_BC, BC, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"INC B", OPCODE_INC_B, B, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"XOR A", OPCODE_XOR_A, A, REGISTER, A, REGISTER, XOR, ALU, UNCONDITIONAL, 0, 1},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"JP a16", OPCODE_JP_A16, A16, IMMEDIATE_MEM, NONE, NA, JP, JUMP, UNCONDITIONAL, 0, 3},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"}
};

const Instruction CB_INSTRUCTIONS[];

