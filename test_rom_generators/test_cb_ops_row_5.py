PREFIX_CB = 0xCB

BIT_2_B = 0x50
BIT_2_C = 0x51
BIT_2_D = 0x52
BIT_2_E = 0x53
BIT_2_H = 0x54
BIT_2_L = 0x55
BIT_2_REF_HL = 0x56
BIT_2_A = 0x57
BIT_3_B = 0x58
BIT_3_C = 0x59
BIT_3_D = 0x5A
BIT_3_E = 0x5B
BIT_3_H = 0x5C
BIT_3_L = 0x5D
BIT_3_REF_HL =0x5E
BIT_3_A =0x5F

opcodes = [
    PREFIX_CB,
    BIT_2_B,
    PREFIX_CB,
    BIT_2_C,
    PREFIX_CB,
    BIT_2_D,
    PREFIX_CB,
    BIT_2_E,
    PREFIX_CB,
    BIT_2_H,
    PREFIX_CB,
    BIT_2_L,
    PREFIX_CB,
    BIT_2_REF_HL,
    PREFIX_CB,
    BIT_2_A,
    PREFIX_CB,
    BIT_2_B,
    PREFIX_CB,
    BIT_2_C,
    PREFIX_CB,
    BIT_2_D,
    PREFIX_CB,
    BIT_2_E,
    PREFIX_CB,
    BIT_2_H,
    PREFIX_CB,
    BIT_2_L,
    PREFIX_CB,
    BIT_2_REF_HL,
    PREFIX_CB,
    BIT_2_A,
    PREFIX_CB,
    BIT_3_B,
    PREFIX_CB,
    BIT_3_C,
    PREFIX_CB,
    BIT_3_D,
    PREFIX_CB,
    BIT_3_E,
    PREFIX_CB,
    BIT_3_H,
    PREFIX_CB,
    BIT_3_L,
    PREFIX_CB,
    BIT_3_REF_HL,
    PREFIX_CB,
    BIT_3_A,
    PREFIX_CB,
    BIT_3_B,
    PREFIX_CB,
    BIT_3_C,
    PREFIX_CB,
    BIT_3_D,
    PREFIX_CB,
    BIT_3_E,
    PREFIX_CB,
    BIT_3_H,
    PREFIX_CB,
    BIT_3_L,
    PREFIX_CB,
    BIT_3_REF_HL,
    PREFIX_CB,
    BIT_3_A,
]

with open('games/test/test_cb_ops_row_5.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))