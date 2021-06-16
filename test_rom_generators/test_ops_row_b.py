# initialize A to 0
# init B to 1
# init C to 2
# init D to 3
# init E to 4
# init H to 5
# init L to 6

OR_B = 0xB0
OR_C = 0xB1
OR_D = 0xB2
OR_E = 0xB3
OR_H = 0xB4
OR_L = 0xB5
OR_REF_HL = 0xB6
OR_A = 0xB7
CP_B = 0xB8
CP_C = 0xB9
CP_D = 0xBA
CP_E = 0xBB
CP_H = 0xBC
CP_L = 0xBD
CP_REF_HL = 0xBE
CP_A = 0xBF

opcodes = [
    OR_B,
    OR_C,
    OR_D,
    OR_E,
    OR_H,
    OR_L,
    OR_REF_HL,
    OR_A,
    CP_B,
    CP_C,
    CP_D,
    CP_E,
    CP_H,
    CP_L,
    CP_REF_HL,
    CP_A,
]

with open('games/test/test_ops_row_b.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))