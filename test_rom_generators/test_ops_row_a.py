# initialize A to 0xFF
# init B to 1
# init C to 2
# init D to 3
# init E to 4
# init H to 5
# init L to 6

AND_B = 0xA0
AND_C = 0xA1
AND_D = 0xA2
AND_E = 0xA3
AND_H = 0xA4
AND_L = 0xA5
AND_REF_HL = 0xA6
AND_A = 0xA7
XOR_B = 0xA8
XOR_C = 0xA9
XOR_D = 0xAA
XOR_E = 0xAB
XOR_H = 0xAC
XOR_L = 0xAD
XOR_REF_HL = 0xAE
XOR_A = 0xAF

opcodes = [
    AND_B,
    AND_C,
    AND_D,
    AND_E,
    AND_H,
    AND_L,
    AND_REF_HL,
    AND_A,
    XOR_B,
    XOR_C,
    XOR_D,
    XOR_E,
    XOR_H,
    XOR_L,
    XOR_REF_HL,
    XOR_A,
]

with open('games/test/test_ops_row_a.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))