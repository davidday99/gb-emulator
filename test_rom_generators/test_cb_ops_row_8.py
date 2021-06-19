PREFIX_CB = 0xCB

RES_0_B = 0x80
RES_0_C = 0x81
RES_0_D = 0x82
RES_0_E = 0x83
RES_0_H = 0x84
RES_0_L = 0x85
RES_0_REF_HL = 0x86
RES_0_A = 0x87
RES_1_B = 0x88
RES_1_C = 0x89
RES_1_D = 0x8A
RES_1_E = 0x8B
RES_1_H = 0x8C
RES_1_L = 0x8D
RES_1_REF_HL =0x8E
RES_1_A =0x8F

opcodes = [
    PREFIX_CB,
    RES_0_B,
    PREFIX_CB,
    RES_0_C,
    PREFIX_CB,
    RES_0_D,
    PREFIX_CB,
    RES_0_E,
    PREFIX_CB,
    RES_0_H,
    PREFIX_CB,
    RES_0_L,
    PREFIX_CB,
    RES_0_REF_HL,
    PREFIX_CB,
    RES_0_A,
    PREFIX_CB,
    RES_1_B,
    PREFIX_CB,
    RES_1_C,
    PREFIX_CB,
    RES_1_D,
    PREFIX_CB,
    RES_1_E,
    PREFIX_CB,
    RES_1_H,
    PREFIX_CB,
    RES_1_L,
    PREFIX_CB,
    RES_1_REF_HL,
    PREFIX_CB,
    RES_1_A,
]

with open('games/test/test_cb_ops_row_8.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))