#include <stdint.h>
#include "../include/isa-sm83.h"

const Instruction INSTRUCTIONS[] = {
    {"NOP", OPCODE_NOP, NONE, NA, NONE, NA, NOP, MISC, UNCONDITIONAL, 0, 1},
    {"LD BC,%d", OPCODE_LD_BC_D16, BC, REGISTER, D16, IMMEDIATE_MEM, LD, LD_ST_MOV, UNCONDITIONAL, 0, 3},
    {"LD (BC),A", OPCODE_LD_REF_BC_A, BC, REGISTER_INDIRECT, A, REGISTER, LD, LD_ST_MOV, UNCONDITIONAL, 0, 1},
    {"INC BC", OPCODE_INC_BC, BC, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"INC B", OPCODE_INC_B, B, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"DEC B", OPCODE_DEC_B, B, REGISTER, NONE, NA, DEC, ALU, UNCONDITIONAL, 0, 1},
    {"LD B,%d", OPCODE_LD_B_D8, B, REGISTER, D8, IMMEDIATE_MEM, LD, LD_ST_MOV, UNCONDITIONAL, 0 , 2},
    {"RLCA", OPCODE_RLCA, A, REGISTER, NONE, NA, RLCA, SHIFTER, UNCONDITIONAL, 0, 1},
    {"LD (%#4X),SP", OPCODE_LD_REF_A16_SP, A16, IMMEDIATE_MEM_INDIRECT, SP, REGISTER, LD, LD_ST_MOV, UNCONDITIONAL, 0, 3},
    {"ADD HL,BC", OPCODE_ADD_HL_BC, HL, REGISTER, BC, REGISTER, ADD, ALU, UNCONDITIONAL, 0, 1},
    {"LD A,(BC)", OPCODE_LD_A_REF_BC, A, REGISTER, BC, REGISTER_INDIRECT, LD, LD_ST_MOV, UNCONDITIONAL, 0, 1},
    {"DEC BC", OPCODE_DEC_BC, BC, REGISTER, NONE, NA, DEC, ALU, UNCONDITIONAL, 0, 1},
    {"INC C", OPCODE_INC_C, C, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"DEC C", OPCODE_DEC_C, C, REGISTER, NONE, NA, DEC, ALU, UNCONDITIONAL, 0, 1},
    {"LD C,%d", OPCODE_LD_C_D8, C, REGISTER, D8, IMMEDIATE_MEM, LD, LD_ST_MOV, UNCONDITIONAL, 0, 2},
    {"RRCA", OPCODE_RRCA, A, REGISTER, NONE, NA, RRCA, SHIFTER, UNCONDITIONAL, 0, 1},
    {"STOP", OPCODE_STOP_0, NONE, NA, NONE, NA, STOP, MISC, UNCONDITIONAL, 0, 1},
    {"LD DE,%d", OPCODE_LD_DE_D16, DE, REGISTER, D16, IMMEDIATE_MEM, LD, LD_ST_MOV, UNCONDITIONAL, 0, 3},
    {"LD (DE),A", OPCODE_LD_REF_DE_A, DE, REGISTER_INDIRECT, A, REGISTER, LD, LD_ST_MOV, UNCONDITIONAL, 0, 1},
    {"INC DE", OPCODE_INC_DE, DE, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"INC D", OPCODE_INC_D, D, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"DEC D", OPCODE_DEC_D, D, REGISTER, NONE, NA, DEC, ALU, UNCONDITIONAL, 0, 1},
    {"LD D,%d", OPCODE_LD_D_D8, D, REGISTER, D8, IMMEDIATE_MEM, LD, LD_ST_MOV, UNCONDITIONAL, 0 , 2},
    {"RLA", OPCODE_RLA, A, REGISTER, NONE, NA, RLA, SHIFTER, UNCONDITIONAL, 0, 1},
    {"JR %d", OPCODE_JR_R8, D8, IMMEDIATE_MEM, NONE, NA, JR, JUMP, UNCONDITIONAL, 0, 2},
    {"ADD HL,DE", OPCODE_ADD_HL_DE, HL, REGISTER, DE, REGISTER, ADD, ALU, UNCONDITIONAL, 0, 1},
    {"LD A,(DE)", OPCODE_LD_A_REF_DE, A, REGISTER, DE, REGISTER_INDIRECT, LD, LD_ST_MOV, UNCONDITIONAL, 0, 1},
    {"DEC DE", OPCODE_DEC_DE, DE, REGISTER, NONE, NA, DEC, ALU, UNCONDITIONAL, 0, 1},
    {"INC E", OPCODE_INC_E, E, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"DEC E", OPCODE_DEC_E, E, REGISTER, NONE, NA, DEC, ALU, UNCONDITIONAL, 0, 1},
    {"LD E,%d", OPCODE_LD_E_D8, E, REGISTER, D8, IMMEDIATE_MEM, LD, LD_ST_MOV, UNCONDITIONAL, 0, 2},
    {"RRA", OPCODE_RRA, A, REGISTER, NONE, NA, RRA, SHIFTER, UNCONDITIONAL, 0, 1},
    {"JR NZ,%d", OPCODE_JR_NZ_R8, D8, IMMEDIATE_MEM, NONE, NA, JR, JUMP, NZ, 0, 2},
    {"LD HL,%d", OPCODE_LD_HL_D16, HL, REGISTER, D16, IMMEDIATE_MEM, LD, LD_ST_MOV, UNCONDITIONAL, 0, 3},
    {"LD (HL+),A", OPCODE_LDD_REF_HL_A, HL, REGISTER_INDIRECT, A, REGISTER, LDI, LD_ST_MOV, UNCONDITIONAL, 0, 1},
    {"INC HL", OPCODE_INC_HL, HL, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"INC H", OPCODE_INC_H, H, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"DEC H", OPCODE_DEC_H, H, REGISTER, NONE, NA, DEC, ALU, UNCONDITIONAL, 0, 1},
    {"LD H,%d", OPCODE_LD_H_D8, H, REGISTER, NONE, NA, LD, LD_ST_MOV, UNCONDITIONAL, 0, 2},
    {"DAA", OPCODE_DAA, A, REGISTER, NONE, NA, DAA, MISC, UNCONDITIONAL, 0, 1},
    {"JR Z,%d", OPCODE_JR_Z_R8, D8, IMMEDIATE_MEM, NONE, NA, JR, JUMP, Z, 0, 2},
    {"ADD HL,HL", OPCODE_ADD_HL_HL, HL, REGISTER, HL, REGISTER, ADD, ALU, UNCONDITIONAL, 0, 1},
    {"LD A,(HL+)", OPCODE_LDI_A_REF_HL, A, REGISTER, HL, REGISTER_INDIRECT, LDI, LD_ST_MOV, UNCONDITIONAL, 0, 1},
    {"DEC HL", OPCODE_DEC_HL, HL, REGISTER, NONE, NA, DEC, ALU, UNCONDITIONAL, 0, 1},
    {"INC L", OPCODE_INC_L, L, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"DEC L", OPCODE_DEC_L, L, REGISTER, NONE, NA, DEC, ALU, UNCONDITIONAL, 0, 1},
    {"LD L,%d", OPCODE_LD_L_D8, L, REGISTER, D8, IMMEDIATE_MEM, LD, LD_ST_MOV, UNCONDITIONAL, 0, 2},
    {"CPL", OPCODE_CPL, A, REGISTER, NONE, NA, CPL, MISC, UNCONDITIONAL, 0, 1},
    {"JR NC,%d", OPCODE_JR_NC_R8, D8, IMMEDIATE_MEM, NONE, NA, JR, JUMP, NC, 0, 2},
    {"LD SP,%d", OPCODE_LD_SP_D16, SP, REGISTER, D16, IMMEDIATE_MEM, LD, LD_ST_MOV, 0, 3},
    {"LD (HL-),A", OPCODE_LDD_REF_HL_A, HL, REGISTER_INDIRECT, A, REGISTER, LDD, LD_ST_MOV, UNCONDITIONAL, 0, 1},
    {"INC SP", OPCODE_INC_SP, SP, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"INC (HL)", OPCODE_INC_REF_HL, HL, REGISTER_INDIRECT, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"DEC (HL)", OPCODE_DEC_REF_HL, HL, REGISTER_INDIRECT, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"LD (HL),%d", OPCODE_LD_REF_HL_D8, HL, REGISTER_INDIRECT, D8, IMMEDIATE_MEM, LD, LD_ST_MOV, UNCONDITIONAL, 0, 2},
    {"SCF", OPCODE_SCF, NONE, NA, NONE, NA, SCF, MISC, UNCONDITIONAL, 0, 1},
    {"JR C,%d", OPCODE_JR_C_R8, D8, IMMEDIATE_MEM, NONE, NA, JR, JUMP, C, 0, 2},
    {"ADD HL,SP", OPCODE_ADD_HL_SP, HL, REGISTER, SP, REGISTER, ADD, ALU, UNCONDITIONAL, 0, 1},
    {"LD A,(HL-)", OPCODE_LDD_A_REF_HL, A, REGISTER, HL, REGISTER_INDIRECT, LDD, LD_ST_MOV, UNCONDITIONAL, 0, 1},
    {"DEC SP", OPCODE_DEC_SP, SP, REGISTER, NONE, NA, DEC, ALU, UNCONDITIONAL, 0, 1},
    {"INC A", OPCODE_INC_A, A, REGISTER, NONE, NA, INC, ALU, UNCONDITIONAL, 0, 1},
    {"DEC A", OPCODE_DEC_A, A, REGISTER, NONE, NA, DEC, ALU, UNCONDITIONAL, 0, 1},
    {"LD A,%d", OPCODE_LD_A_D8, A, REGISTER, D8, IMMEDIATE_MEM, LD, LD_ST_MOV, UNCONDITIONAL, 0, 2},
    {"CCF", OPCODE_CCF, NONE, NA, NONE, NA, CCF, MISC, UNCONDITIONAL, 0, 1},
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
    {"JP 0x%04X", OPCODE_JP_A16, A16, IMMEDIATE_MEM, NONE, NA, JP, JUMP, UNCONDITIONAL, 0, 3},
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
    {"LDH %#2X,A", OPCODE_LDH_REF_A8_A, A8, IMMEDIATE_MEM_INDIRECT, A, REGISTER, LDH, LD_ST_MOV, UNCONDITIONAL, 0, 2},
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
    {"LDH A,%#2X", OPCODE_LDH_A_REF_A8, A, REGISTER, A8, IMMEDIATE_MEM_INDIRECT, LDH, LD_ST_MOV, UNCONDITIONAL, 0, 2},
    {"NA"},
    {"NA"},
    {"DI", OPCODE_DI, NONE, NA, NONE, NA, DI, MISC, UNCONDITIONAL, 0, 1},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"NA"},
    {"LD SP,HL", OPCODE_LD_SP_HL, SP, REGISTER, HL, REGISTER, LD, LD_ST_MOV, UNCONDITIONAL, 0, 1},
    {"NA"},
    {"EI", OPCODE_EI, NONE, NA, NONE, NA, EI, MISC, UNCONDITIONAL, 0, 1},
    {"NA"},
    {"NA"},
    {"CP %d", OPCODE_CP_D8, A, REGISTER, D8, IMMEDIATE_MEM, CP, ALU, UNCONDITIONAL, 0, 2},
    {"NA"}
};

const Instruction CB_INSTRUCTIONS[];

