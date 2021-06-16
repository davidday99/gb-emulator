# initialize A to 0
# init B to 1
# init C to 2
# init D to 3
# init E to 4
# init H to 5
# init L to 6

SUB_B = 0x90
SUB_C = 0x91
SUB_D = 0x92
SUB_E = 0x93
SUB_H = 0x94
SUB_L = 0x95
SUB_REF_HL = 0x96
SUB_A = 0x97
SBC_B = 0x98
SBC_C = 0x99
SBC_D = 0x9A
SBC_E = 0x9B
SBC_H = 0x9C
SBC_L = 0x9D
SBC_REF_HL = 0x9E
SBC_A = 0x9F

opcodes = [
    SUB_B,
    SUB_C,
    SUB_D,
    SUB_E,
    SUB_H,
    SUB_L,
    SUB_REF_HL,
    SUB_A,
    SBC_B,
    SBC_C,
    SBC_D,
    SBC_E,
    SBC_H,
    SBC_L,
    SBC_REF_HL,
    SBC_A,
]

with open('games/test/test_ops_row_9.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))