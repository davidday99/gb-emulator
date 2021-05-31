#ifndef ISA_SM83_H
#define ISA_SM83_H

#include <stdint.h>

#define FLAG_Z_MASK 0x80
#define FLAG_N_MASK 0x40
#define FLAG_H_MASK 0x20
#define FLAG_C_MASK 0x10
#define NO_FLAGS 0

#define NUM_INSTRUCTIONS_NON_CB 244
#define NUM_INSTRUCTIONS_CB 256

/* OPCODES */

/* Non-CB */

#define NOP 0
#define LD_BC_D16 0x01
#define LD_REF_BC_A 0x02
#define INC_BC 0x03
#define INC_B 0x04
#define DEC_B 0x05
#define LD_B_D8 0x06
#define RLCA 0x07
#define LD_REF_A16_SP 0x08
#define ADD_HL_BC 0x09
#define LD_A_REF_BC 0x0A
#define DEC_BC 0x0B
#define INC_C 0x0C
#define DEC_C 0x0D
#define LD_C_D8 0x0E
#define RRCA 0x0F

#define STOP_0 0x10
#define LD_DE_D16 0x11
#define LD_REF_DE_A 0x12
#define INC_DE 0x13
#define INC_D 0x14
#define DEC_D 0x15
#define LD_D_D8 0x16
#define RLA 0x17
#define JR_R8 0x18
#define ADD_HL_DE 0x19
#define LD_A_REF_DE 0x1A
#define DEC_DE 0x1B
#define INC_E 0x1C
#define DEC_E 0x1D
#define LD_E_D8 0x1E
#define RRA 0x1F

#define JR_NZ_R8 0x20
#define LD_HL_D16 0x21
#define LDI_REF_HL_A 0x22
#define INC_HL 0x23
#define INC_H 0x24
#define DEC_H 0x25
#define LD_H_D8 0x26
#define DAA 0x27
#define JR_Z_R8 0x28
#define ADD_HL_HL 0x29
#define LDI_A_REF_HL 0x2A
#define DEC_HL 0x2B
#define INC_L 0x2C
#define DEC_L 0x2D
#define LD_L_D8 0x2E
#define CPL 0x2F

#define JR_NC_R8 0x30
#define LD_SP_D16 0x31
#define LDD_REF_HL_A 0x32
#define INC_SP 0x33
#define INC_REF_HL 0x34
#define DEC_REF_HL 0x35
#define LD_REF_HL_D8 0x36
#define SCF 0x37
#define JR_C_R8 0x38
#define ADD_HL_SP 0x39
#define LDD_A_REF_HL 0x3A
#define DEC_SP 0x3B
#define INC_A 0x3C
#define DEC_A 0x3D
#define LD_A_D8 0x3E
#define CCF 0x3F

#define LD_B_B 0x40
#define LD_B_C 0x41
#define LD_B_D 0x42
#define LD_B_E 0x43
#define LD_B_H 0x44
#define LD_B_L 0x45
#define LD_B_HL 0x46
#define LD_B_A 0x47
#define LD_C_B 0x48
#define LD_C_C 0x49
#define LD_C_D 0x4A
#define LD_C_E 0x4B
#define LD_C_H 0x4C
#define LD_C_L 0x4D
#define LD_C_HL 0x4E
#define LD_C_A 0x4F

#define LD_D_B 0x50
#define LD_D_C 0x51
#define LD_D_D 0x52
#define LD_D_E 0x53
#define LD_D_H 0x54
#define LD_D_L 0x55
#define LD_D_REF_HL 0x56
#define LD_D_A 0x57
#define LD_E_B 0x58
#define LD_E_C 0x59
#define LD_E_D 0x5A
#define LD_E_E 0x5B
#define LD_E_H 0x5C
#define LD_E_L 0x5D
#define LD_E_REF_HL 0x5E
#define LD_E_A 0x5F

#define LD_H_B 0x60
#define LD_H_C 0x61
#define LD_H_D 0x62
#define LD_H_E 0x63
#define LD_H_H 0x64
#define LD_H_L 0x66
#define LD_H_REF_HL 0x66
#define LD_H_A 0x67
#define LD_L_B 0x68
#define LD_L_C 0x69
#define LD_L_D 0x6A
#define LD_L_E 0x6B
#define LD_L_H 0x6C
#define LD_L_L 0x6D
#define LD_L_REF_HL 0x6E
#define LD_L_A 0x6F

#define LD_HL_B 0x70
#define LD_HL_C 0x71
#define LD_HL_D 0x72
#define LD_HL_E 0x73
#define LD_HL_H 0x74
#define LD_HL_L 0x75
#define HALT 0x76
#define LD_REF_HL_A 0x77
#define LD_A_B 0x78
#define LD_A_C 0x79
#define LD_A_D 0x7A
#define LD_A_E 0x7B
#define LD_A_H 0x7C
#define LD_A_L 0x7D
#define LD_A_REF_HL 0x7E
#define LD_A_A 0x7F

#define ADD_A_B 0x80 
#define ADD_A_C 0x81
#define ADD_A_D 0x82
#define ADD_A_E 0x83
#define ADD_A_H 0x84
#define ADD_A_L 0x85
#define ADD_A_REF_HL 0x86
#define ADD_A_A 0x87
#define ADC_A_B 0x88
#define ADC_A_C 0x89
#define ADC_A_D 0x8A
#define ADC_A_E 0x8B
#define ADC_A_H 0x8C
#define ADC_A_L 0x8D
#define ADC_A_REF_HL 0x8E
#define ADC_A_A 0x8F

#define SUB_B 0x90
#define SUB_C 0x91
#define SUB_D 0x92
#define SUB_E 0x93
#define SUB_H 0x94
#define SUB_L 0x95
#define SUB_REF_HL 0x96
#define SUB_A 0x97
#define SBC_A_B 0x98
#define SBC_A_C 0x99
#define SBC_A_D 0x9A
#define SBC_A_E 0x9B
#define SBC_A_H 0x9C
#define SBC_A_L 0x9D
#define SBC_A_REF_HL 0x9E
#define SBC_A_A 0x9F

#define AND_B 0xA0
#define AND_C 0xA1
#define AND_D 0xA2
#define AND_E 0xA3
#define AND_H 0xA4
#define AND_L 0xA5
#define AND_REF_HL 0xA6
#define AND_A 0xA7
#define XOR_B 0xA8
#define XOR_C 0xA9
#define XOR_D 0xAA
#define XOR_E 0xAB
#define XOR_H 0xAC
#define XOR_L 0xAD
#define XOR_REF_HL 0xAE
#define XOR_A 0xAF

#define OR_B 0xB0
#define OR_C 0xB1
#define OR_D 0xB2
#define OR_E 0xB3
#define OR_H 0xB4
#define OR_L 0xB5
#define OR_REF_HL 0xB6
#define OR_A 0xB7
#define CP_B 0xB8
#define CP_C 0xB9
#define CP_D 0xBA
#define CP_E 0xBB
#define CP_H 0xBC
#define CP_L 0xBD
#define CP_REF_HL 0xBE
#define CP_A 0xBF

#define RET_NZ 0xC0
#define POP_BC 0xC1
#define JP_NZ_A16 0xC2
#define JP_A16 0xC3
#define CALL_NZ4_A16 0xC4
#define PUSH_BC 0xC5
#define ADD_A_D8 0xC6
#define RST_00H 0xC7
#define RET_Z 0xC8
#define RET 0xC9
#define JP_Z_A16 0xCA
#define PREFIX_CB 0xCB
#define CALL_Z_A16 0xCC
#define CALL_A16 0xCD
#define ADC_D8 0xCE
#define RST_08H 0xCF

#define RET_NC 0xD0
#define POP_DE 0xD1
#define JP_NC_A16 0xD2
#define CALL_NC_A16 0xD4
#define PUSH_DE 0XD5
#define SUB_D8 0xD6
#define RST_10H 0xD7
#define RET_C 0xD8
#define RETI 0xD9
#define JP_C_A16 0xDA
#define CALL_C_A16 0xDC
#define SUBC_A_D8 0xDE
#define RST_18H 0xDF

#define LDH_REF_A8_A 0xE0
#define POP_HL 0xE1
#define LD_REF_C_A 0xE2
#define PUSH_HL 0xE5
#define AND_D8 0xE6
#define RST_20H 0xE7
#define ADD_SP_R8 0xE8
#define JP_REF_HL 0xE9
#define LD_REF_A16_A 0xEA
#define XOR_D8 0xEE
#define RST_28H 0xEF

#define LD_A_REF_A8 0xF0
#define POP_AF 0xF1
#define LD_A_REF_C 0xF2
#define DI 0xF3

#define PUSH_AF 0xF5
#define OR_D8 0xF6
#define RST_30H 0xF7
#define LD_HL_SP_R8 0xF8
#define LD_SP_HL 0xF9
#define LD_A_REF_A16 0xFA
#define EI 0xFB

#define CP 0xFE
#define RST_38H 0xFF 

/* CB-Prefixed */

#define RLC_B 0x00
#define RLC_C 0x01
#define RLC_D 0x02
#define RLC_E 0x03
#define RLC_H 0x04
#define RLC_L 0x05
#define RLC_REF_HL 0x06
#define RLC_A 0x07
#define RRC_B 0x08
#define RRC_C 0x09
#define RRC_D 0x0A
#define RRC_E 0x0B
#define RRC_H 0x0C
#define RRC_L 0x0D
#define RRC_REF_HL 0x0E
#define RRC_A 0x0F

#define RL_B 0x10
#define RL_C 0x11
#define RL_D 0x12
#define RL_E 0x13
#define RL_H 0x14
#define RL_L 0x15
#define RL_REF_HL 0x16
#define RL_A 0x17
#define RR_B 0x18
#define RR_C 0x19
#define RR_D 0x1A
#define RR_E 0x1B
#define RR_H 0x1C
#define RR_L 0x1D
#define RR_REF_HL 0x1E
#define RR_A 0x1F

#define SLA_B 0x20
#define SLA_C 0x21
#define SLA_D 0x22
#define SLA_E 0x23
#define SLA_H 0x24
#define SLA_L 0x25
#define SLA_REF_HL 0x26
#define SLA_A 0x27
#define SRA_B 0x28
#define SRA_C 0x29
#define SRA_D 0x2A
#define SRA_E 0x2B
#define SRA_H 0x2C
#define SRA_L 0x2D
#define SRA_REF_HL 0x2E
#define SRA_A 0x2F

#define SWAP_B 0x30
#define SWAP_C 0x31
#define SWAP_D 0x32
#define SWAP_E 0x33
#define SWAP_H 0x34
#define SWAP_L 0x35
#define SWAP_REF_HL 0x36
#define SWAP_A 0x37
#define SRL_B 0x38
#define SRL_C 0x39
#define SRL_D 0x3A
#define SRL_E 0x3B
#define SRL_H 0x3C
#define SRL_L 0x3D
#define SRL_REF_HL 0x3E
#define SRL_A 0x3F

#define BIT_0_B 0x40
#define BIT_0_C 0x41
#define BIT_0_D 0x42
#define BIT_0_E 0x43
#define BIT_0_H 0x44
#define BIT_0_L 0x45
#define BIT_0_REF_HL 0x46
#define BIT_0_A 0x47
#define BIT_1_B 0x48
#define BIT_1_C 0x49
#define BIT_1_D 0x4A
#define BIT_1_E 0x4B
#define BIT_1_H 0x4C
#define BIT_1_L 0x4D
#define BIT_1_REF_HL 0x4E
#define BIT_1_A 0x4F

#define BIT_2_B 0x50
#define BIT_2_C 0x51
#define BIT_2_D 0x52
#define BIT_2_E 0x53
#define BIT_2_H 0x54
#define BIT_2_L 0x55
#define BIT_2_REF_HL 0x56
#define BIT_2_A 0x57
#define BIT_3_B 0x58
#define BIT_3_C 0x59
#define BIT_3_D 0x5A
#define BIT_3_E 0x5B
#define BIT_3_H 0x5C
#define BIT_3_L 0x5D
#define BIT_3_REF_HL 0x5E
#define BIT_3_A 0x5F

#define BIT_4_B 0x60
#define BIT_4_C 0x61
#define BIT_4_D 0x62
#define BIT_4_E 0x63
#define BIT_4_H 0x64
#define BIT_4_L 0x65
#define BIT_4_REF_HL 0x66
#define BIT_4_A 0x67
#define BIT_5_B 0x68
#define BIT_5_C 0x69
#define BIT_5_D 0x6A
#define BIT_5_E 0x6B
#define BIT_5_H 0x6C
#define BIT_5_L 0x6D
#define BIT_5_REF_HL 0x6E
#define BIT_5_A 0x6F

#define BIT_6_B 0x70
#define BIT_6_C 0x71
#define BIT_6_D 0x72
#define BIT_6_E 0x73
#define BIT_6_H 0x74
#define BIT_6_L 0x75
#define BIT_6_REF_HL 0x76
#define BIT_6_A 0x77
#define BIT_7_B 0x78
#define BIT_7_C 0x79
#define BIT_7_D 0x7A
#define BIT_7_E 0x7B
#define BIT_7_H 0x7C
#define BIT_7_L 0x7D
#define BIT_7_REF_HL 0x7E
#define BIT_7_A 0x7F

#define RES_0_B 0x80
#define RES_0_C 0x81
#define RES_0_D 0x82
#define RES_0_E 0x83
#define RES_0_H 0x84
#define RES_0_L 0x85
#define RES_0_REF_HL 0x86
#define RES_0_A 0x87
#define RES_1_B 0x88
#define RES_1_C 0x89
#define RES_1_D 0x8A
#define RES_1_E 0x8B
#define RES_1_H 0x8C
#define RES_1_L 0x8D
#define RES_1_REF_HL 0x8E
#define RES_1_A 0x8F

#define RES_2_B 0x90
#define RES_2_C 0x91
#define RES_2_D 0x92
#define RES_2_E 0x93
#define RES_2_H 0x94
#define RES_2_L 0x95
#define RES_2_REF_HL 0x96
#define RES_2_A 0x97
#define RES_3_B 0x98
#define RES_3_C 0x99
#define RES_3_D 0x9A
#define RES_3_E 0x9B
#define RES_3_H 0x9C
#define RES_3_L 0x9D
#define RES_3_REF_HL 0x9E
#define RES_3_A 0x9F

#define RES_4_B 0xA0
#define RES_4_C 0xA1
#define RES_4_D 0xA2
#define RES_4_E 0xA3
#define RES_4_H 0xA4
#define RES_4_L 0xA5
#define RES_4_REF_HL 0xA6
#define RES_4_A 0xA7
#define RES_5_B 0xA8
#define RES_5_C 0xA9
#define RES_5_D 0xAA
#define RES_5_E 0xAB
#define RES_5_H 0xAC
#define RES_5_L 0xAD
#define RES_5_REF_HL 0xAE
#define RES_5_A 0xAF

#define RES_6_B 0xB0
#define RES_6_C 0xB1
#define RES_6_D 0xB2
#define RES_6_E 0xB3
#define RES_6_H 0xB4
#define RES_6_L 0xB5
#define RES_6_REF_HL 0xB6
#define RES_6_A 0xB7
#define RES_7_B 0xB8
#define RES_7_C 0xB9
#define RES_7_D 0xBA
#define RES_7_E 0xBB
#define RES_7_H 0xBC
#define RES_7_L 0xBD
#define RES_7_REF_HL 0xBE
#define RES_7_A 0xBF

#define SET_0_B 0xC0
#define SET_0_C 0xC1
#define SET_0_D 0xC2
#define SET_0_E 0xC3
#define SET_0_H 0xC4
#define SET_0_L 0xC5
#define SET_0_REF_HL 0xC6
#define SET_0_A 0xC7
#define SET_1_B 0xC8
#define SET_1_C 0xC9
#define SET_1_D 0xCA
#define SET_1_E 0xCB
#define SET_1_H 0xCC
#define SET_1_L 0xCD
#define SET_1_REF_HL 0xCE
#define SET_1_A 0xCF

#define SET_2_B 0xD0
#define SET_2_C 0xD1
#define SET_2_D 0xD2
#define SET_2_E 0xD3
#define SET_2_H 0xD4
#define SET_2_L 0xD5
#define SET_2_REF_HL 0xD6
#define SET_2_A 0xD7
#define SET_3_B 0xD8
#define SET_3_C 0xD9
#define SET_3_D 0xDA
#define SET_3_E 0xDB
#define SET_3_H 0xDC
#define SET_3_L 0xDD
#define SET_3_REF_HL 0xDE
#define SET_3_A 0xDF

#define SET_4_B 0xE0
#define SET_4_C 0xE1
#define SET_4_D 0xE2
#define SET_4_E 0xE3
#define SET_4_H 0xE4
#define SET_4_L 0xE5
#define SET_4_REF_HL 0xE6
#define SET_4_A 0xE7
#define SET_5_B 0xE8
#define SET_5_C 0xE9
#define SET_5_D 0xEA
#define SET_5_E 0xEB
#define SET_5_H 0xEC
#define SET_5_L 0xED
#define SET_5_REF_HL 0xEE
#define SET_5_A 0xEF

#define SET_6_B 0xF0
#define SET_6_C 0xF1
#define SET_6_D 0xF2
#define SET_6_E 0xF3
#define SET_6_H 0xF4
#define SET_6_L 0xF5
#define SET_6_REF_HL 0xF6
#define SET_6_A 0xF7
#define SET_7_B 0xF8
#define SET_7_C 0xF9
#define SET_7_D 0xFA
#define SET_7_E 0xFB
#define SET_7_H 0xFC
#define SET_7_L 0xFD
#define SET_7_REF_HL 0xFE
#define SET_7_A 0xFF

#define CB 1
#define NO_CB 0

typedef struct Instruction {
    char mnemonic[15];
    uint8_t opcode;
    uint8_t immediate_size;
    uint8_t byte_len;
    uint8_t flag_mask;
    uint8_t is_CB;
} Instruction;

extern const Instruction INSTRUCTIONS[NUM_INSTRUCTIONS_NON_CB];

extern const Instruction CB_INSTRUCTIONS[NUM_INSTRUCTIONS_CB];

#endif /* ISA_SM83_H */