PREFIX_CB = 0xCB

BIT_4_B = 0x60
BIT_4_C = 0x61
BIT_4_D = 0x62
BIT_4_E = 0x63
BIT_4_H = 0x64
BIT_4_L = 0x65
BIT_4_REF_HL = 0x66
BIT_4_A = 0x67
BIT_5_B = 0x68
BIT_5_C = 0x69
BIT_5_D = 0x6A
BIT_5_E = 0x6B
BIT_5_H = 0x6C
BIT_5_L = 0x6D
BIT_5_REF_HL =0x6E
BIT_5_A =0x6F

opcodes = [
    PREFIX_CB,
    BIT_4_B,
    PREFIX_CB,
    BIT_4_C,
    PREFIX_CB,
    BIT_4_D,
    PREFIX_CB,
    BIT_4_E,
    PREFIX_CB,
    BIT_4_H,
    PREFIX_CB,
    BIT_4_L,
    PREFIX_CB,
    BIT_4_REF_HL,
    PREFIX_CB,
    BIT_4_A,
    PREFIX_CB,
    BIT_4_B,
    PREFIX_CB,
    BIT_4_C,
    PREFIX_CB,
    BIT_4_D,
    PREFIX_CB,
    BIT_4_E,
    PREFIX_CB,
    BIT_4_H,
    PREFIX_CB,
    BIT_4_L,
    PREFIX_CB,
    BIT_4_REF_HL,
    PREFIX_CB,
    BIT_4_A,
    PREFIX_CB,
    BIT_5_B,
    PREFIX_CB,
    BIT_5_C,
    PREFIX_CB,
    BIT_5_D,
    PREFIX_CB,
    BIT_5_E,
    PREFIX_CB,
    BIT_5_H,
    PREFIX_CB,
    BIT_5_L,
    PREFIX_CB,
    BIT_5_REF_HL,
    PREFIX_CB,
    BIT_5_A,
    PREFIX_CB,
    BIT_5_B,
    PREFIX_CB,
    BIT_5_C,
    PREFIX_CB,
    BIT_5_D,
    PREFIX_CB,
    BIT_5_E,
    PREFIX_CB,
    BIT_5_H,
    PREFIX_CB,
    BIT_5_L,
    PREFIX_CB,
    BIT_5_REF_HL,
    PREFIX_CB,
    BIT_5_A,
]

with open('games/test/test_cb_ops_row_6.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))