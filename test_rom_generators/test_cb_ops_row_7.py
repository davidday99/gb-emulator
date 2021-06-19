PREFIX_CB = 0xCB

BIT_6_B = 0x70
BIT_6_C = 0x71
BIT_6_D = 0x72
BIT_6_E = 0x73
BIT_6_H = 0x74
BIT_6_L = 0x75
BIT_6_REF_HL = 0x76
BIT_6_A = 0x77
BIT_7_B = 0x78
BIT_7_C = 0x79
BIT_7_D = 0x7A
BIT_7_E = 0x7B
BIT_7_H = 0x7C
BIT_7_L = 0x7D
BIT_7_REF_HL =0x7E
BIT_7_A =0x7F

opcodes = [
    PREFIX_CB,
    BIT_6_B,
    PREFIX_CB,
    BIT_6_C,
    PREFIX_CB,
    BIT_6_D,
    PREFIX_CB,
    BIT_6_E,
    PREFIX_CB,
    BIT_6_H,
    PREFIX_CB,
    BIT_6_L,
    PREFIX_CB,
    BIT_6_REF_HL,
    PREFIX_CB,
    BIT_6_A,
    PREFIX_CB,
    BIT_6_B,
    PREFIX_CB,
    BIT_6_C,
    PREFIX_CB,
    BIT_6_D,
    PREFIX_CB,
    BIT_6_E,
    PREFIX_CB,
    BIT_6_H,
    PREFIX_CB,
    BIT_6_L,
    PREFIX_CB,
    BIT_6_REF_HL,
    PREFIX_CB,
    BIT_6_A,
    PREFIX_CB,
    BIT_7_B,
    PREFIX_CB,
    BIT_7_C,
    PREFIX_CB,
    BIT_7_D,
    PREFIX_CB,
    BIT_7_E,
    PREFIX_CB,
    BIT_7_H,
    PREFIX_CB,
    BIT_7_L,
    PREFIX_CB,
    BIT_7_REF_HL,
    PREFIX_CB,
    BIT_7_A,
    PREFIX_CB,
    BIT_7_B,
    PREFIX_CB,
    BIT_7_C,
    PREFIX_CB,
    BIT_7_D,
    PREFIX_CB,
    BIT_7_E,
    PREFIX_CB,
    BIT_7_H,
    PREFIX_CB,
    BIT_7_L,
    PREFIX_CB,
    BIT_7_REF_HL,
    PREFIX_CB,
    BIT_7_A,
]

with open('games/test/test_cb_ops_row_7.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))