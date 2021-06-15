# initialize A to 1
# init B to 0
# init C to 3
# init D to 4
# init E to 5
# init H to 6
# init L to 7

LD_B_B = 0x40
LD_B_C = 0x41
LD_B_D = 0x42
LD_B_E = 0x43
LD_B_H = 0x44
LD_B_L = 0x45
LD_B_REF_HL = 0x46
LD_B_A = 0x47
LD_C_B = 0x48
LD_C_C = 0x49
LD_C_D = 0x4A
LD_C_E = 0x4B
LD_C_H = 0x4C
LD_C_L = 0x4D
LD_C_REF_HL = 0x4E
LD_C_A = 0x4F

opcodes = [
    LD_B_B,
    LD_B_C,
    LD_B_D,
    LD_B_E,
    LD_B_H,
    LD_B_L,
    LD_B_REF_HL,
    LD_B_A,
    LD_C_B,
    LD_C_C,
    LD_C_D,
    LD_C_E,
    LD_C_H,
    LD_C_L,
    LD_C_REF_HL,
    LD_C_A
]

with open('games/test/test_ops_row_4.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))