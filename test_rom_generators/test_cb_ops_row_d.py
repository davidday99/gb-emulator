PREFIX_CB = 0xCB

SET_2_B = 0xD0
SET_2_C = 0xD1
SET_2_D = 0xD2
SET_2_E = 0xD3
SET_2_H = 0xD4
SET_2_L = 0xD5
SET_2_REF_HL = 0xD6
SET_2_A = 0xD7
SET_3_B = 0xD8
SET_3_C = 0xD9
SET_3_D = 0xDA
SET_3_E = 0xDB
SET_3_H = 0xDC
SET_3_L = 0xDD
SET_3_REF_HL =0xDE
SET_3_A =0xDF

opcodes = [
    PREFIX_CB,
    SET_2_B,
    PREFIX_CB,
    SET_2_C,
    PREFIX_CB,
    SET_2_D,
    PREFIX_CB,
    SET_2_E,
    PREFIX_CB,
    SET_2_H,
    PREFIX_CB,
    SET_2_L,
    PREFIX_CB,
    SET_2_REF_HL,
    PREFIX_CB,
    SET_2_A,
    PREFIX_CB,
    SET_3_B,
    PREFIX_CB,
    SET_3_C,
    PREFIX_CB,
    SET_3_D,
    PREFIX_CB,
    SET_3_E,
    PREFIX_CB,
    SET_3_H,
    PREFIX_CB,
    SET_3_L,
    PREFIX_CB,
    SET_3_REF_HL,
    PREFIX_CB,
    SET_3_A,
]

with open('games/test/test_cb_ops_row_d.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))