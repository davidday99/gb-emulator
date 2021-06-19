PREFIX_CB = 0xCB

BIT_0_B = 0x40
BIT_0_C = 0x41
BIT_0_D = 0x42
BIT_0_E = 0x43
BIT_0_H = 0x44
BIT_0_L = 0x45
BIT_0_REF_HL = 0x46
BIT_0_A = 0x47
BIT_1_B = 0x48
BIT_1_C = 0x49
BIT_1_D = 0x4A
BIT_1_E = 0x4B
BIT_1_H = 0x4C
BIT_1_L = 0x4D
BIT_1_REF_HL =0x4E
BIT_1_A =0x4F

opcodes = [
    PREFIX_CB,
    BIT_0_B,
    PREFIX_CB,
    BIT_0_C,
    PREFIX_CB,
    BIT_0_D,
    PREFIX_CB,
    BIT_0_E,
    PREFIX_CB,
    BIT_0_H,
    PREFIX_CB,
    BIT_0_L,
    PREFIX_CB,
    BIT_0_REF_HL,
    PREFIX_CB,
    BIT_0_A,
    PREFIX_CB,
    BIT_0_B,
    PREFIX_CB,
    BIT_0_C,
    PREFIX_CB,
    BIT_0_D,
    PREFIX_CB,
    BIT_0_E,
    PREFIX_CB,
    BIT_0_H,
    PREFIX_CB,
    BIT_0_L,
    PREFIX_CB,
    BIT_0_REF_HL,
    PREFIX_CB,
    BIT_0_A,
    PREFIX_CB,
    BIT_1_B,
    PREFIX_CB,
    BIT_1_C,
    PREFIX_CB,
    BIT_1_D,
    PREFIX_CB,
    BIT_1_E,
    PREFIX_CB,
    BIT_1_H,
    PREFIX_CB,
    BIT_1_L,
    PREFIX_CB,
    BIT_1_REF_HL,
    PREFIX_CB,
    BIT_1_A,
    PREFIX_CB,
    BIT_1_B,
    PREFIX_CB,
    BIT_1_C,
    PREFIX_CB,
    BIT_1_D,
    PREFIX_CB,
    BIT_1_E,
    PREFIX_CB,
    BIT_1_H,
    PREFIX_CB,
    BIT_1_L,
    PREFIX_CB,
    BIT_1_REF_HL,
    PREFIX_CB,
    BIT_1_A,
]

with open('games/test/test_cb_ops_row_4.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))