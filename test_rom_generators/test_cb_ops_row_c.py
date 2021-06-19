PREFIX_CB = 0xCB

SET_0_B = 0xC0
SET_0_C = 0xC1
SET_0_D = 0xC2
SET_0_E = 0xC3
SET_0_H = 0xC4
SET_0_L = 0xC5
SET_0_REF_HL = 0xC6
SET_0_A = 0xC7
SET_1_B = 0xC8
SET_1_C = 0xC9
SET_1_D = 0xCA
SET_1_E = 0xCB
SET_1_H = 0xCC
SET_1_L = 0xCD
SET_1_REF_HL =0xCE
SET_1_A =0xCF

opcodes = [
    PREFIX_CB,
    SET_0_B,
    PREFIX_CB,
    SET_0_C,
    PREFIX_CB,
    SET_0_D,
    PREFIX_CB,
    SET_0_E,
    PREFIX_CB,
    SET_0_H,
    PREFIX_CB,
    SET_0_L,
    PREFIX_CB,
    SET_0_REF_HL,
    PREFIX_CB,
    SET_0_A,
    PREFIX_CB,
    SET_1_B,
    PREFIX_CB,
    SET_1_C,
    PREFIX_CB,
    SET_1_D,
    PREFIX_CB,
    SET_1_E,
    PREFIX_CB,
    SET_1_H,
    PREFIX_CB,
    SET_1_L,
    PREFIX_CB,
    SET_1_REF_HL,
    PREFIX_CB,
    SET_1_A,
]

with open('games/test/test_cb_ops_row_c.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))