#ifndef ISA_SM83_H
#define ISA_SM83_H

#include <stdint.h>

#define FLAG_Z_MASK 0x80
#define FLAG_N_MASK 0x40
#define FLAG_H_MASK 0x20
#define FLAG_C_MASK 0x10
#define NO_FLAGS 0

#define NUM_OPCODES 256

/* OPCODES */

#define CB_PREFIX 0xC3

/* Non-CB */

#define OPCODE_NOP 0
#define OPCODE_LD_BC_D16 0x01
#define OPCODE_LD_REF_BC_A 0x02
#define OPCODE_INC_BC 0x03
#define OPCODE_INC_B 0x04
#define OPCODE_DEC_B 0x05
#define OPCODE_LD_B_D8 0x06
#define OPCODE_RLCA 0x07
#define OPCODE_LD_REF_A16_SP 0x08
#define OPCODE_ADD_HL_BC 0x09
#define OPCODE_LD_A_REF_BC 0x0A
#define OPCODE_DEC_BC 0x0B
#define OPCODE_INC_C 0x0C
#define OPCODE_DEC_C 0x0D
#define OPCODE_LD_C_D8 0x0E
#define OPCODE_RRCA 0x0F

#define OPCODE_STOP_0 0x10
#define OPCODE_LD_DE_D16 0x11
#define OPCODE_LD_REF_DE_A 0x12
#define OPCODE_INC_DE 0x13
#define OPCODE_INC_D 0x14
#define OPCODE_DEC_D 0x15
#define OPCODE_LD_D_D8 0x16
#define OPCODE_RLA 0x17
#define OPCODE_JR_R8 0x18
#define OPCODE_ADD_HL_DE 0x19
#define OPCODE_LD_A_REF_DE 0x1A
#define OPCODE_DEC_DE 0x1B
#define OPCODE_INC_E 0x1C
#define OPCODE_DEC_E 0x1D
#define OPCODE_LD_E_D8 0x1E
#define OPCODE_RRA 0x1F

#define OPCODE_JR_NZ_R8 0x20
#define OPCODE_LD_HL_D16 0x21
#define OPCODE_LDI_REF_HL_A 0x22
#define OPCODE_INC_HL 0x23
#define OPCODE_INC_H 0x24
#define OPCODE_DEC_H 0x25
#define OPCODE_LD_H_D8 0x26
#define OPCODE_DAA 0x27
#define OPCODE_JR_Z_R8 0x28
#define OPCODE_ADD_HL_HL 0x29
#define OPCODE_LDI_A_REF_HL 0x2A
#define OPCODE_DEC_HL 0x2B
#define OPCODE_INC_L 0x2C
#define OPCODE_DEC_L 0x2D
#define OPCODE_LD_L_D8 0x2E
#define OPCODE_CPL 0x2F

#define OPCODE_JR_NC_R8 0x30
#define OPCODE_LD_SP_D16 0x31
#define OPCODE_LDD_REF_HL_A 0x32
#define OPCODE_INC_SP 0x33
#define OPCODE_INC_REF_HL 0x34
#define OPCODE_DEC_REF_HL 0x35
#define OPCODE_LD_REF_HL_D8 0x36
#define OPCODE_SCF 0x37
#define OPCODE_JR_C_R8 0x38
#define OPCODE_ADD_HL_SP 0x39
#define OPCODE_LDD_A_REF_HL 0x3A
#define OPCODE_DEC_SP 0x3B
#define OPCODE_INC_A 0x3C
#define OPCODE_DEC_A 0x3D
#define OPCODE_LD_A_D8 0x3E
#define OPCODE_CCF 0x3F

#define OPCODE_LD_B_B 0x40
#define OPCODE_LD_B_C 0x41
#define OPCODE_LD_B_D 0x42
#define OPCODE_LD_B_E 0x43
#define OPCODE_LD_B_H 0x44
#define OPCODE_LD_B_L 0x45
#define OPCODE_LD_B_HL 0x46
#define OPCODE_LD_B_A 0x47
#define OPCODE_LD_C_B 0x48
#define OPCODE_LD_C_C 0x49
#define OPCODE_LD_C_D 0x4A
#define OPCODE_LD_C_E 0x4B
#define OPCODE_LD_C_H 0x4C
#define OPCODE_LD_C_L 0x4D
#define OPCODE_LD_C_HL 0x4E
#define OPCODE_LD_C_A 0x4F

#define OPCODE_LD_D_B 0x50
#define OPCODE_LD_D_C 0x51
#define OPCODE_LD_D_D 0x52
#define OPCODE_LD_D_E 0x53
#define OPCODE_LD_D_H 0x54
#define OPCODE_LD_D_L 0x55
#define OPCODE_LD_D_REF_HL 0x56
#define OPCODE_LD_D_A 0x57
#define OPCODE_LD_E_B 0x58
#define OPCODE_LD_E_C 0x59
#define OPCODE_LD_E_D 0x5A
#define OPCODE_LD_E_E 0x5B
#define OPCODE_LD_E_H 0x5C
#define OPCODE_LD_E_L 0x5D
#define OPCODE_LD_E_REF_HL 0x5E
#define OPCODE_LD_E_A 0x5F

#define OPCODE_LD_H_B 0x60
#define OPCODE_LD_H_C 0x61
#define OPCODE_LD_H_D 0x62
#define OPCODE_LD_H_E 0x63
#define OPCODE_LD_H_H 0x64
#define OPCODE_LD_H_L 0x66
#define OPCODE_LD_H_REF_HL 0x66
#define OPCODE_LD_H_A 0x67
#define OPCODE_LD_L_B 0x68
#define OPCODE_LD_L_C 0x69
#define OPCODE_LD_L_D 0x6A
#define OPCODE_LD_L_E 0x6B
#define OPCODE_LD_L_H 0x6C
#define OPCODE_LD_L_L 0x6D
#define OPCODE_LD_L_REF_HL 0x6E
#define OPCODE_LD_L_A 0x6F

#define OPCODE_LD_HL_B 0x70
#define OPCODE_LD_HL_C 0x71
#define OPCODE_LD_HL_D 0x72
#define OPCODE_LD_HL_E 0x73
#define OPCODE_LD_HL_H 0x74
#define OPCODE_LD_HL_L 0x75
#define OPCODE_HALT 0x76
#define OPCODE_LD_REF_HL_A 0x77
#define OPCODE_LD_A_B 0x78
#define OPCODE_LD_A_C 0x79
#define OPCODE_LD_A_D 0x7A
#define OPCODE_LD_A_E 0x7B
#define OPCODE_LD_A_H 0x7C
#define OPCODE_LD_A_L 0x7D
#define OPCODE_LD_A_REF_HL 0x7E
#define OPCODE_LD_A_A 0x7F

#define OPCODE_ADD_A_B 0x80 
#define OPCODE_ADD_A_C 0x81
#define OPCODE_ADD_A_D 0x82
#define OPCODE_ADD_A_E 0x83
#define OPCODE_ADD_A_H 0x84
#define OPCODE_ADD_A_L 0x85
#define OPCODE_ADD_A_REF_HL 0x86
#define OPCODE_ADD_A_A 0x87
#define OPCODE_ADC_A_B 0x88
#define OPCODE_ADC_A_C 0x89
#define OPCODE_ADC_A_D 0x8A
#define OPCODE_ADC_A_E 0x8B
#define OPCODE_ADC_A_H 0x8C
#define OPCODE_ADC_A_L 0x8D
#define OPCODE_ADC_A_REF_HL 0x8E
#define OPCODE_ADC_A_A 0x8F

#define OPCODE_SUB_B 0x90
#define OPCODE_SUB_C 0x91
#define OPCODE_SUB_D 0x92
#define OPCODE_SUB_E 0x93
#define OPCODE_SUB_H 0x94
#define OPCODE_SUB_L 0x95
#define OPCODE_SUB_REF_HL 0x96
#define OPCODE_SUB_A 0x97
#define OPCODE_SBC_A_B 0x98
#define OPCODE_SBC_A_C 0x99
#define OPCODE_SBC_A_D 0x9A
#define OPCODE_SBC_A_E 0x9B
#define OPCODE_SBC_A_H 0x9C
#define OPCODE_SBC_A_L 0x9D
#define OPCODE_SBC_A_REF_HL 0x9E
#define OPCODE_SBC_A_A 0x9F

#define OPCODE_AND_B 0xA0
#define OPCODE_AND_C 0xA1
#define OPCODE_AND_D 0xA2
#define OPCODE_AND_E 0xA3
#define OPCODE_AND_H 0xA4
#define OPCODE_AND_L 0xA5
#define OPCODE_AND_REF_HL 0xA6
#define OPCODE_AND_A 0xA7
#define OPCODE_XOR_B 0xA8
#define OPCODE_XOR_C 0xA9
#define OPCODE_XOR_D 0xAA
#define OPCODE_XOR_E 0xAB
#define OPCODE_XOR_H 0xAC
#define OPCODE_XOR_L 0xAD
#define OPCODE_XOR_REF_HL 0xAE
#define OPCODE_XOR_A 0xAF

#define OPCODE_OR_B 0xB0
#define OPCODE_OR_C 0xB1
#define OPCODE_OR_D 0xB2
#define OPCODE_OR_E 0xB3
#define OPCODE_OR_H 0xB4
#define OPCODE_OR_L 0xB5
#define OPCODE_OR_REF_HL 0xB6
#define OPCODE_OR_A 0xB7
#define OPCODE_CP_B 0xB8
#define OPCODE_CP_C 0xB9
#define OPCODE_CP_D 0xBA
#define OPCODE_CP_E 0xBB
#define OPCODE_CP_H 0xBC
#define OPCODE_CP_L 0xBD
#define OPCODE_CP_REF_HL 0xBE
#define OPCODE_CP_A 0xBF

#define OPCODE_RET_NZ 0xC0
#define OPCODE_POP_BC 0xC1
#define OPCODE_JP_NZ_A16 0xC2
#define OPCODE_JP_A16 0xC3
#define OPCODE_CALL_NZ4_A16 0xC4
#define OPCODE_PUSH_BC 0xC5
#define OPCODE_ADD_A_D8 0xC6
#define OPCODE_RST_00H 0xC7
#define OPCODE_RET_Z 0xC8
#define OPCODE_RET 0xC9
#define OPCODE_JP_Z_A16 0xCA
#define OPCODE_PREFIX_CB 0xCB
#define OPCODE_CALL_Z_A16 0xCC
#define OPCODE_CALL_A16 0xCD
#define OPCODE_ADC_D8 0xCE
#define OPCODE_RST_08H 0xCF

#define OPCODE_RET_NC 0xD0
#define OPCODE_POP_DE 0xD1
#define OPCODE_JP_NC_A16 0xD2
#define OPCODE_CALL_NC_A16 0xD4
#define OPCODE_PUSH_DE 0XD5
#define OPCODE_SUB_D8 0xD6
#define OPCODE_RST_10H 0xD7
#define OPCODE_RET_C 0xD8
#define OPCODE_RETI 0xD9
#define OPCODE_JP_C_A16 0xDA
#define OPCODE_CALL_C_A16 0xDC
#define OPCODE_SUBC_A_D8 0xDE
#define OPCODE_RST_18H 0xDF

#define OPCODE_LDH_REF_A8_A 0xE0
#define OPCODE_POP_HL 0xE1
#define OPCODE_LD_REF_C_A 0xE2
#define OPCODE_PUSH_HL 0xE5
#define OPCODE_AND_D8 0xE6
#define OPCODE_RST_20H 0xE7
#define OPCODE_ADD_SP_R8 0xE8
#define OPCODE_JP_REF_HL 0xE9
#define OPCODE_LD_REF_A16_A 0xEA
#define OPCODE_XOR_D8 0xEE
#define OPCODE_RST_28H 0xEF

#define OPCODE_LD_A_REF_A8 0xF0
#define OPCODE_POP_AF 0xF1
#define OPCODE_LD_A_REF_C 0xF2
#define OPCODE_DI 0xF3

#define OPCODE_PUSH_AF 0xF5
#define OPCODE_OR_D8 0xF6
#define OPCODE_RST_30H 0xF7
#define OPCODE_LD_HL_SP_R8 0xF8
#define OPCODE_LD_SP_HL 0xF9
#define OPCODE_LD_A_REF_A16 0xFA
#define OPCODE_EI 0xFB

#define OPCODE_CP 0xFE
#define OPCODE_RST_38H 0xFF 

/* CB-Prefixed */

#define OPCODE_RLC_B 0x00
#define OPCODE_RLC_C 0x01
#define OPCODE_RLC_D 0x02
#define OPCODE_RLC_E 0x03
#define OPCODE_RLC_H 0x04
#define OPCODE_RLC_L 0x05
#define OPCODE_RLC_REF_HL 0x06
#define OPCODE_RLC_A 0x07
#define OPCODE_RRC_B 0x08
#define OPCODE_RRC_C 0x09
#define OPCODE_RRC_D 0x0A
#define OPCODE_RRC_E 0x0B
#define OPCODE_RRC_H 0x0C
#define OPCODE_RRC_L 0x0D
#define OPCODE_RRC_REF_HL 0x0E
#define OPCODE_RRC_A 0x0F

#define OPCODE_RL_B 0x10
#define OPCODE_RL_C 0x11
#define OPCODE_RL_D 0x12
#define OPCODE_RL_E 0x13
#define OPCODE_RL_H 0x14
#define OPCODE_RL_L 0x15
#define OPCODE_RL_REF_HL 0x16
#define OPCODE_RL_A 0x17
#define OPCODE_RR_B 0x18
#define OPCODE_RR_C 0x19
#define OPCODE_RR_D 0x1A
#define OPCODE_RR_E 0x1B
#define OPCODE_RR_H 0x1C
#define OPCODE_RR_L 0x1D
#define OPCODE_RR_REF_HL 0x1E
#define OPCODE_RR_A 0x1F

#define OPCODE_SLA_B 0x20
#define OPCODE_SLA_C 0x21
#define OPCODE_SLA_D 0x22
#define OPCODE_SLA_E 0x23
#define OPCODE_SLA_H 0x24
#define OPCODE_SLA_L 0x25
#define OPCODE_SLA_REF_HL 0x26
#define OPCODE_SLA_A 0x27
#define OPCODE_SRA_B 0x28
#define OPCODE_SRA_C 0x29
#define OPCODE_SRA_D 0x2A
#define OPCODE_SRA_E 0x2B
#define OPCODE_SRA_H 0x2C
#define OPCODE_SRA_L 0x2D
#define OPCODE_SRA_REF_HL 0x2E
#define OPCODE_SRA_A 0x2F

#define OPCODE_SWAP_B 0x30
#define OPCODE_SWAP_C 0x31
#define OPCODE_SWAP_D 0x32
#define OPCODE_SWAP_E 0x33
#define OPCODE_SWAP_H 0x34
#define OPCODE_SWAP_L 0x35
#define OPCODE_SWAP_REF_HL 0x36
#define OPCODE_SWAP_A 0x37
#define OPCODE_SRL_B 0x38
#define OPCODE_SRL_C 0x39
#define OPCODE_SRL_D 0x3A
#define OPCODE_SRL_E 0x3B
#define OPCODE_SRL_H 0x3C
#define OPCODE_SRL_L 0x3D
#define OPCODE_SRL_REF_HL 0x3E
#define OPCODE_SRL_A 0x3F

#define OPCODE_BIT_0_B 0x40
#define OPCODE_BIT_0_C 0x41
#define OPCODE_BIT_0_D 0x42
#define OPCODE_BIT_0_E 0x43
#define OPCODE_BIT_0_H 0x44
#define OPCODE_BIT_0_L 0x45
#define OPCODE_BIT_0_REF_HL 0x46
#define OPCODE_BIT_0_A 0x47
#define OPCODE_BIT_1_B 0x48
#define OPCODE_BIT_1_C 0x49
#define OPCODE_BIT_1_D 0x4A
#define OPCODE_BIT_1_E 0x4B
#define OPCODE_BIT_1_H 0x4C
#define OPCODE_BIT_1_L 0x4D
#define OPCODE_BIT_1_REF_HL 0x4E
#define OPCODE_BIT_1_A 0x4F

#define OPCODE_BIT_2_B 0x50
#define OPCODE_BIT_2_C 0x51
#define OPCODE_BIT_2_D 0x52
#define OPCODE_BIT_2_E 0x53
#define OPCODE_BIT_2_H 0x54
#define OPCODE_BIT_2_L 0x55
#define OPCODE_BIT_2_REF_HL 0x56
#define OPCODE_BIT_2_A 0x57
#define OPCODE_BIT_3_B 0x58
#define OPCODE_BIT_3_C 0x59
#define OPCODE_BIT_3_D 0x5A
#define OPCODE_BIT_3_E 0x5B
#define OPCODE_BIT_3_H 0x5C
#define OPCODE_BIT_3_L 0x5D
#define OPCODE_BIT_3_REF_HL 0x5E
#define OPCODE_BIT_3_A 0x5F

#define OPCODE_BIT_4_B 0x60
#define OPCODE_BIT_4_C 0x61
#define OPCODE_BIT_4_D 0x62
#define OPCODE_BIT_4_E 0x63
#define OPCODE_BIT_4_H 0x64
#define OPCODE_BIT_4_L 0x65
#define OPCODE_BIT_4_REF_HL 0x66
#define OPCODE_BIT_4_A 0x67
#define OPCODE_BIT_5_B 0x68
#define OPCODE_BIT_5_C 0x69
#define OPCODE_BIT_5_D 0x6A
#define OPCODE_BIT_5_E 0x6B
#define OPCODE_BIT_5_H 0x6C
#define OPCODE_BIT_5_L 0x6D
#define OPCODE_BIT_5_REF_HL 0x6E
#define OPCODE_BIT_5_A 0x6F

#define OPCODE_BIT_6_B 0x70
#define OPCODE_BIT_6_C 0x71
#define OPCODE_BIT_6_D 0x72
#define OPCODE_BIT_6_E 0x73
#define OPCODE_BIT_6_H 0x74
#define OPCODE_BIT_6_L 0x75
#define OPCODE_BIT_6_REF_HL 0x76
#define OPCODE_BIT_6_A 0x77
#define OPCODE_BIT_7_B 0x78
#define OPCODE_BIT_7_C 0x79
#define OPCODE_BIT_7_D 0x7A
#define OPCODE_BIT_7_E 0x7B
#define OPCODE_BIT_7_H 0x7C
#define OPCODE_BIT_7_L 0x7D
#define OPCODE_BIT_7_REF_HL 0x7E
#define OPCODE_BIT_7_A 0x7F

#define OPCODE_RES_0_B 0x80
#define OPCODE_RES_0_C 0x81
#define OPCODE_RES_0_D 0x82
#define OPCODE_RES_0_E 0x83
#define OPCODE_RES_0_H 0x84
#define OPCODE_RES_0_L 0x85
#define OPCODE_RES_0_REF_HL 0x86
#define OPCODE_RES_0_A 0x87
#define OPCODE_RES_1_B 0x88
#define OPCODE_RES_1_C 0x89
#define OPCODE_RES_1_D 0x8A
#define OPCODE_RES_1_E 0x8B
#define OPCODE_RES_1_H 0x8C
#define OPCODE_RES_1_L 0x8D
#define OPCODE_RES_1_REF_HL 0x8E
#define OPCODE_RES_1_A 0x8F

#define OPCODE_RES_2_B 0x90
#define OPCODE_RES_2_C 0x91
#define OPCODE_RES_2_D 0x92
#define OPCODE_RES_2_E 0x93
#define OPCODE_RES_2_H 0x94
#define OPCODE_RES_2_L 0x95
#define OPCODE_RES_2_REF_HL 0x96
#define OPCODE_RES_2_A 0x97
#define OPCODE_RES_3_B 0x98
#define OPCODE_RES_3_C 0x99
#define OPCODE_RES_3_D 0x9A
#define OPCODE_RES_3_E 0x9B
#define OPCODE_RES_3_H 0x9C
#define OPCODE_RES_3_L 0x9D
#define OPCODE_RES_3_REF_HL 0x9E
#define OPCODE_RES_3_A 0x9F

#define OPCODE_RES_4_B 0xA0
#define OPCODE_RES_4_C 0xA1
#define OPCODE_RES_4_D 0xA2
#define OPCODE_RES_4_E 0xA3
#define OPCODE_RES_4_H 0xA4
#define OPCODE_RES_4_L 0xA5
#define OPCODE_RES_4_REF_HL 0xA6
#define OPCODE_RES_4_A 0xA7
#define OPCODE_RES_5_B 0xA8
#define OPCODE_RES_5_C 0xA9
#define OPCODE_RES_5_D 0xAA
#define OPCODE_RES_5_E 0xAB
#define OPCODE_RES_5_H 0xAC
#define OPCODE_RES_5_L 0xAD
#define OPCODE_RES_5_REF_HL 0xAE
#define OPCODE_RES_5_A 0xAF

#define OPCODE_RES_6_B 0xB0
#define OPCODE_RES_6_C 0xB1
#define OPCODE_RES_6_D 0xB2
#define OPCODE_RES_6_E 0xB3
#define OPCODE_RES_6_H 0xB4
#define OPCODE_RES_6_L 0xB5
#define OPCODE_RES_6_REF_HL 0xB6
#define OPCODE_RES_6_A 0xB7
#define OPCODE_RES_7_B 0xB8
#define OPCODE_RES_7_C 0xB9
#define OPCODE_RES_7_D 0xBA
#define OPCODE_RES_7_E 0xBB
#define OPCODE_RES_7_H 0xBC
#define OPCODE_RES_7_L 0xBD
#define OPCODE_RES_7_REF_HL 0xBE
#define OPCODE_RES_7_A 0xBF

#define OPCODE_SET_0_B 0xC0
#define OPCODE_SET_0_C 0xC1
#define OPCODE_SET_0_D 0xC2
#define OPCODE_SET_0_E 0xC3
#define OPCODE_SET_0_H 0xC4
#define OPCODE_SET_0_L 0xC5
#define OPCODE_SET_0_REF_HL 0xC6
#define OPCODE_SET_0_A 0xC7
#define OPCODE_SET_1_B 0xC8
#define OPCODE_SET_1_C 0xC9
#define OPCODE_SET_1_D 0xCA
#define OPCODE_SET_1_E 0xCB
#define OPCODE_SET_1_H 0xCC
#define OPCODE_SET_1_L 0xCD
#define OPCODE_SET_1_REF_HL 0xCE
#define OPCODE_SET_1_A 0xCF

#define OPCODE_SET_2_B 0xD0
#define OPCODE_SET_2_C 0xD1
#define OPCODE_SET_2_D 0xD2
#define OPCODE_SET_2_E 0xD3
#define OPCODE_SET_2_H 0xD4
#define OPCODE_SET_2_L 0xD5
#define OPCODE_SET_2_REF_HL 0xD6
#define OPCODE_SET_2_A 0xD7
#define OPCODE_SET_3_B 0xD8
#define OPCODE_SET_3_C 0xD9
#define OPCODE_SET_3_D 0xDA
#define OPCODE_SET_3_E 0xDB
#define OPCODE_SET_3_H 0xDC
#define OPCODE_SET_3_L 0xDD
#define OPCODE_SET_3_REF_HL 0xDE
#define OPCODE_SET_3_A 0xDF

#define OPCODE_SET_4_B 0xE0
#define OPCODE_SET_4_C 0xE1
#define OPCODE_SET_4_D 0xE2
#define OPCODE_SET_4_E 0xE3
#define OPCODE_SET_4_H 0xE4
#define OPCODE_SET_4_L 0xE5
#define OPCODE_SET_4_REF_HL 0xE6
#define OPCODE_SET_4_A 0xE7
#define OPCODE_SET_5_B 0xE8
#define OPCODE_SET_5_C 0xE9
#define OPCODE_SET_5_D 0xEA
#define OPCODE_SET_5_E 0xEB
#define OPCODE_SET_5_H 0xEC
#define OPCODE_SET_5_L 0xED
#define OPCODE_SET_5_REF_HL 0xEE
#define OPCODE_SET_5_A 0xEF

#define OPCODE_SET_6_B 0xF0
#define OPCODE_SET_6_C 0xF1
#define OPCODE_SET_6_D 0xF2
#define OPCODE_SET_6_E 0xF3
#define OPCODE_SET_6_H 0xF4
#define OPCODE_SET_6_L 0xF5
#define OPCODE_SET_6_REF_HL 0xF6
#define OPCODE_SET_6_A 0xF7
#define OPCODE_SET_7_B 0xF8
#define OPCODE_SET_7_C 0xF9
#define OPCODE_SET_7_D 0xFA
#define OPCODE_SET_7_E 0xFB
#define OPCODE_SET_7_H 0xFC
#define OPCODE_SET_7_L 0xFD
#define OPCODE_SET_7_REF_HL 0xFE
#define OPCODE_SET_7_A 0xFF

#define CB 1
#define NO_CB 0

enum operand {
    A,
    B,
    C,
    D,
    E,
    H,
    L,
    AF,
    BC,
    DE,
    HL,
    PC,
    SP,
    A8,
    D8,
    A16,
    D16,
    NONE
};

enum addressing_mode {
    REGISTER,
    REGISTER_INDIRECT,
    IMMEDIATE,
    IMMEDIATE_MEM,
    IMMEDIATE_MEM_INDIRECT,
    NA
};

enum condition {
    UNCONDITIONAL,
    NZ,
    Z,
    NC,
    CARRY
};

enum operation {
    LD,
    LDD,
    LDI,
    LDH,
    LDHL,
    PUSH,
    POP,
    ADD,
    ADC,
    SUB,
    SBC,
    AND,
    OR,
    XOR,
    CP,
    INC,
    DEC,
    SWAP,
    DAA,
    CPL,
    CCF,
    SCF,
    NOP,
    HALT,
    STOP,
    DI,
    EI,
    RLCA,
    RLC,
    RLA,
    RL,
    RRCA,
    RRC,
    RRA,
    RR,
    RLC,
    RL,
    RRC,
    RR,
    SLA,
    SRA,
    SRL,
    BIT,
    SET,
    RES,
    JP,
    JR,
    CALL,
    RST,
    RET,
    RETI
};

enum operation_type {
    LD_ST_MOV,
    ALU,
    SHIFTER,
    BITWISE,
    JUMP,
    MISC
};

typedef struct Instruction {
    char mnemonic[20];
    uint8_t opcode;
    enum operand destination;
    enum addressing_mode destination_type;
    enum operand source;
    enum addressing_mode source_type;
    enum operation operation;
    enum operation_type operation_type;
    enum condition condition;
    uint8_t unaccounted_cycles;
    uint8_t bytes;
} Instruction;

extern const Instruction INSTRUCTIONS[NUM_OPCODES];

extern const Instruction CB_INSTRUCTIONS[NUM_OPCODES];

#endif /* ISA_SM83_H */