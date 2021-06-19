PREFIX_CB = 0xCB

RES_6_B = 0xB0
RES_6_C = 0xB1
RES_6_D = 0xB2
RES_6_E = 0xB3
RES_6_H = 0xB4
RES_6_L = 0xB5
RES_6_REF_HL = 0xB6
RES_6_A = 0xB7
RES_7_B = 0xB8
RES_7_C = 0xB9
RES_7_D = 0xBA
RES_7_E = 0xBB
RES_7_H = 0xBC
RES_7_L = 0xBD
RES_7_REF_HL =0xBE
RES_7_A =0xBF

opcodes = [
    PREFIX_CB,
    RES_6_B,
    PREFIX_CB,
    RES_6_C,
    PREFIX_CB,
    RES_6_D,
    PREFIX_CB,
    RES_6_E,
    PREFIX_CB,
    RES_6_H,
    PREFIX_CB,
    RES_6_L,
    PREFIX_CB,
    RES_6_REF_HL,
    PREFIX_CB,
    RES_6_A,
    PREFIX_CB,
    RES_7_B,
    PREFIX_CB,
    RES_7_C,
    PREFIX_CB,
    RES_7_D,
    PREFIX_CB,
    RES_7_E,
    PREFIX_CB,
    RES_7_H,
    PREFIX_CB,
    RES_7_L,
    PREFIX_CB,
    RES_7_REF_HL,
    PREFIX_CB,
    RES_7_A,
]

with open('games/test/test_cb_ops_row_b.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))