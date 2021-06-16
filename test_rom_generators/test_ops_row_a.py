# initialize A to 0xFF
# init B to 1
# init C to 2
# init D to 3
# init E to 4
# init H to 5
# init L to 6

AND_A_B = 0xA0
AND_A_C = 0xA1
AND_A_D = 0xA2
AND_A_E = 0xA3
AND_A_H = 0xA4
AND_A_L = 0xA5
AND_A_REF_HL = 0xA6
AND_A_A = 0xA7
XOR_A_B = 0xA8
XOR_A_C = 0xA9
XOR_A_D = 0xAA
XOR_A_E = 0xAB
XOR_A_H = 0xAC
XOR_A_L = 0xAD
XOR_A_REF_HL = 0xAE
XOR_A_A = 0xAF

opcodes = [
    AND_A_B,
    AND_A_C,
    AND_A_D,
    AND_A_E,
    AND_A_H,
    AND_A_L,
    AND_A_REF_HL,
    AND_A_A,
    XOR_A_B,
    XOR_A_C,
    XOR_A_D,
    XOR_A_E,
    XOR_A_H,
    XOR_A_L,
    XOR_A_REF_HL,
    XOR_A_A,
]

with open('games/test/test_ops_row_a.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))