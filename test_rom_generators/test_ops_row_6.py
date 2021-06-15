# initialize A to 1
# init B to 2
# init C to 3
# init D to 4
# init E to 5
# init H to 0
# init L to 7

LD_H_B = 0x60
LD_H_C = 0x61
LD_H_D = 0x62
LD_H_E = 0x63
LD_H_H = 0x64
LD_H_L = 0x65
LD_H_REF_HL = 0x66
LD_H_A = 0x67
LD_L_B = 0x68
LD_L_C = 0x69
LD_L_D = 0x6A
LD_L_E = 0x6B
LD_L_H = 0x6C
LD_L_L = 0x6D
LD_L_REF_HL = 0x6E
LD_L_A = 0x6F

opcodes = [
    LD_H_B,
    LD_H_C,
    LD_H_D,
    LD_H_E,
    LD_H_H,
    LD_H_L,
    LD_H_REF_HL,
    LD_H_A,
    LD_L_B,
    LD_L_C,
    LD_L_D,
    LD_L_E,
    LD_L_H,
    LD_L_L,
    LD_L_REF_HL,
    LD_L_A
]

with open('games/test/test_ops_row_6.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))