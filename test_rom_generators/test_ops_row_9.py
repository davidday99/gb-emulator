# initialize A to 0
# init B to 1
# init C to 2
# init D to 3
# init E to 4
# init H to 5
# init L to 6

SUB_A_B = 0x90
SUB_A_C = 0x91
SUB_A_D = 0x92
SUB_A_E = 0x93
SUB_A_H = 0x94
SUB_A_L = 0x95
SUB_A_REF_HL = 0x96
SUB_A_A = 0x97
SBC_A_B = 0x98
SBC_A_C = 0x99
SBC_A_D = 0x9A
SBC_A_E = 0x9B
SBC_A_H = 0x9C
SBC_A_L = 0x9D
SBC_A_REF_HL = 0x9E
SBC_A_A = 0x9F

opcodes = [
    SUB_A_B,
    SUB_A_C,
    SUB_A_D,
    SUB_A_E,
    SUB_A_H,
    SUB_A_L,
    SUB_A_REF_HL,
    SUB_A_A,
    SBC_A_B,
    SBC_A_C,
    SBC_A_D,
    SBC_A_E,
    SBC_A_H,
    SBC_A_L,
    SBC_A_REF_HL,
    SBC_A_A,
]

with open('games/test/test_ops_row_9.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))