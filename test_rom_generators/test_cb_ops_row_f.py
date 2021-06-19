PREFIX_CB = 0xCB

SET_6_B = 0xF0
SET_6_C = 0xF1
SET_6_D = 0xF2
SET_6_E = 0xF3
SET_6_H = 0xF4
SET_6_L = 0xF5
SET_6_REF_HL = 0xF6
SET_6_A = 0xF7
SET_7_B = 0xF8
SET_7_C = 0xF9
SET_7_D = 0xFA
SET_7_E = 0xFB
SET_7_H = 0xFC
SET_7_L = 0xFD
SET_7_REF_HL =0xFE
SET_7_A =0xFF

opcodes = [
    PREFIX_CB,
    SET_6_B,
    PREFIX_CB,
    SET_6_C,
    PREFIX_CB,
    SET_6_D,
    PREFIX_CB,
    SET_6_E,
    PREFIX_CB,
    SET_6_H,
    PREFIX_CB,
    SET_6_L,
    PREFIX_CB,
    SET_6_REF_HL,
    PREFIX_CB,
    SET_6_A,
    PREFIX_CB,
    SET_7_B,
    PREFIX_CB,
    SET_7_C,
    PREFIX_CB,
    SET_7_D,
    PREFIX_CB,
    SET_7_E,
    PREFIX_CB,
    SET_7_H,
    PREFIX_CB,
    SET_7_L,
    PREFIX_CB,
    SET_7_REF_HL,
    PREFIX_CB,
    SET_7_A,
]

with open('games/test/test_cb_ops_row_f.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))