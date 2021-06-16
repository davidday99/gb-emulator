# initialize A to 1
# init B to 2
# init C to 3
# init D to 4
# init E to 5
# init H to 0
# init L to 0

LD_REF_HL_B = 0x70
LD_REF_HL_C = 0x71
LD_REF_HL_D = 0x72
LD_REF_HL_E = 0x73
LD_REF_HL_H = 0x74
LD_REF_HL_L = 0x75
LD_REF_HL_A = 0x77
LD_A_B = 0x78
LD_A_C = 0x79
LD_A_D = 0x7A
LD_A_E = 0x7B
LD_A_H = 0x7C
LD_A_L = 0x7D
LD_A_REF_HL = 0x7E
LD_A_A = 0x7F
HALT = 0x76

opcodes = [

]

with open('games/test/test_ops_row_8.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))