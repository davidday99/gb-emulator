PREFIX_CB = 0xCB

RES_4_B = 0xA0
RES_4_C = 0xA1
RES_4_D = 0xA2
RES_4_E = 0xA3
RES_4_H = 0xA4
RES_4_L = 0xA5
RES_4_REF_HL = 0xA6
RES_4_A = 0xA7
RES_5_B = 0xA8
RES_5_C = 0xA9
RES_5_D = 0xAA
RES_5_E = 0xAB
RES_5_H = 0xAC
RES_5_L = 0xAD
RES_5_REF_HL =0xAE
RES_5_A =0xAF

opcodes = [
    PREFIX_CB,
    RES_4_B,
    PREFIX_CB,
    RES_4_C,
    PREFIX_CB,
    RES_4_D,
    PREFIX_CB,
    RES_4_E,
    PREFIX_CB,
    RES_4_H,
    PREFIX_CB,
    RES_4_L,
    PREFIX_CB,
    RES_4_REF_HL,
    PREFIX_CB,
    RES_4_A,
    PREFIX_CB,
    RES_5_B,
    PREFIX_CB,
    RES_5_C,
    PREFIX_CB,
    RES_5_D,
    PREFIX_CB,
    RES_5_E,
    PREFIX_CB,
    RES_5_H,
    PREFIX_CB,
    RES_5_L,
    PREFIX_CB,
    RES_5_REF_HL,
    PREFIX_CB,
    RES_5_A,
]

with open('games/test/test_cb_ops_row_a.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))