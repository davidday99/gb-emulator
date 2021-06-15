# initialize A to 1
# init B to 2
# init C to 3
# init D to 0
# init E to 1
# init H to 6
# init L to 7

LD_D_B = 0x50
LD_D_C = 0x51
LD_D_D = 0x52
LD_D_E = 0x53
LD_D_H = 0x54
LD_D_L = 0x55
LD_D_REF_HL = 0x56
LD_D_A = 0x57
LD_E_B = 0x58
LD_E_C = 0x59
LD_E_D = 0x5A
LD_E_E = 0x5B
LD_E_H = 0x5C
LD_E_L = 0x5D
LD_E_REF_HL = 0x5E
LD_E_A = 0x5F

opcodes = [
    LD_D_B,
    LD_D_C,
    LD_D_D,
    LD_D_E,
    LD_D_H,
    LD_D_L,
    LD_D_REF_HL,
    LD_D_A,
    LD_E_B,
    LD_E_C,
    LD_E_D,
    LD_E_E,
    LD_E_H,
    LD_E_L,
    LD_E_REF_HL,
    LD_E_A
]

with open('games/test/test_ops_row_5.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))