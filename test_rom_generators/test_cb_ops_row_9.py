PREFIX_CB = 0xCB

RES_2_B = 0x90
RES_2_C = 0x91
RES_2_D = 0x92
RES_2_E = 0x93
RES_2_H = 0x94
RES_2_L = 0x95
RES_2_REF_HL = 0x96
RES_2_A = 0x97
RES_3_B = 0x98
RES_3_C = 0x99
RES_3_D = 0x9A
RES_3_E = 0x9B
RES_3_H = 0x9C
RES_3_L = 0x9D
RES_3_REF_HL =0x9E
RES_3_A =0x9F

opcodes = [
    PREFIX_CB,
    RES_2_B,
    PREFIX_CB,
    RES_2_C,
    PREFIX_CB,
    RES_2_D,
    PREFIX_CB,
    RES_2_E,
    PREFIX_CB,
    RES_2_H,
    PREFIX_CB,
    RES_2_L,
    PREFIX_CB,
    RES_2_REF_HL,
    PREFIX_CB,
    RES_2_A,
    PREFIX_CB,
    RES_3_B,
    PREFIX_CB,
    RES_3_C,
    PREFIX_CB,
    RES_3_D,
    PREFIX_CB,
    RES_3_E,
    PREFIX_CB,
    RES_3_H,
    PREFIX_CB,
    RES_3_L,
    PREFIX_CB,
    RES_3_REF_HL,
    PREFIX_CB,
    RES_3_A,
]

with open('games/test/test_cb_ops_row_9.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))