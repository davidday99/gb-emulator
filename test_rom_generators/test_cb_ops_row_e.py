PREFIX_CB = 0xCB

SET_4_B = 0xE0
SET_4_C = 0xE1
SET_4_D = 0xE2
SET_4_E = 0xE3
SET_4_H = 0xE4
SET_4_L = 0xE5
SET_4_REF_HL = 0xE6
SET_4_A = 0xE7
SET_5_B = 0xE8
SET_5_C = 0xE9
SET_5_D = 0xEA
SET_5_E = 0xEB
SET_5_H = 0xEC
SET_5_L = 0xED
SET_5_REF_HL =0xEE
SET_5_A =0xEF

opcodes = [
    PREFIX_CB,
    SET_4_B,
    PREFIX_CB,
    SET_4_C,
    PREFIX_CB,
    SET_4_D,
    PREFIX_CB,
    SET_4_E,
    PREFIX_CB,
    SET_4_H,
    PREFIX_CB,
    SET_4_L,
    PREFIX_CB,
    SET_4_REF_HL,
    PREFIX_CB,
    SET_4_A,
    PREFIX_CB,
    SET_5_B,
    PREFIX_CB,
    SET_5_C,
    PREFIX_CB,
    SET_5_D,
    PREFIX_CB,
    SET_5_E,
    PREFIX_CB,
    SET_5_H,
    PREFIX_CB,
    SET_5_L,
    PREFIX_CB,
    SET_5_REF_HL,
    PREFIX_CB,
    SET_5_A,
]

with open('games/test/test_cb_ops_row_e.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))