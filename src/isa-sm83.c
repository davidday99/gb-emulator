#include <stdint.h>
#include "../include/isa-sm83.h"

const Instruction INSTRUCTIONS[] = {
    {"NOP", NOP, 0, 1, NO_FLAGS, NO_CB},
    {"LD BC,d16", LD_BC_D16, 2, 3, NO_FLAGS, NO_CB},
    {"LD (BC),A", LD_REF_BC_A, 0, 1, NO_FLAGS, NO_CB},
    {"INC BC", INC_BC, 0, 1, NO_FLAGS, NO_CB},
    {"INC B", INC_B, 0, 1, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK, NO_CB},
    {"DEC B", DEC_B, 0, 1, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK, NO_CB},
    {"LD B,d8", LD_B_D8, 1, 2, NO_FLAGS, NO_CB},
    {"RLCA", RLCA, 0, 1, FLAG_C_MASK, NO_CB},
    {"LD (a16),SP", LD_REF_A16_SP, 2, 3, NO_FLAGS, NO_CB},
    {"ADD HL,BC", ADD_HL_BC, 0, 1, FLAG_N_MASK | FLAG_H_MASK | FLAG_C_MASK, NO_CB},
    {"LD A,(BC)", LD_A_REF_BC, 0, 1, NO_FLAGS, NO_CB},
    {"DEC BC", DEC_BC, 0, 1, NO_FLAGS, NO_CB},
    {"INC C", INC_C, 0, 1, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK, NO_CB},
    {"DEC C", DEC_C, 0, 1, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK, NO_CB},
    {"LD C,d8", LD_C_D8, 1, 2, NO_FLAGS, NO_CB},
    {"RRCA", RRCA, 0, 1, FLAG_C_MASK, NO_CB}
};

const Instruction CB_INSTRUCTIONS[] = {

};

