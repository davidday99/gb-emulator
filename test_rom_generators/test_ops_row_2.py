# initialize A to 0xFF

JR_NZ_r8 = 0x20
r8_0 = 0
LD_HL_d16 = 0x21
d16_low = 0xEF
d16_high = 0xBE  # HL <- 0xBEEF
LDI_REF_HL_A = 0x22
INC_HL = 0x23
INC_H = 0x24
DEC_H = 0x25
LD_H_d8 = 0x26
d8_0 = 0x00    # D <- 0x00, was 0xBE
DAA = 0x27
JR_Z_r8 = 0x28
r8_1 = 0x00    # JP 0, essentially NOP
ADD_HL_HL = 0x29
LDI_A_REF_HL = 0x2A
DEC_HL = 0x2B
INC_L = 0x2C
DEC_L = 0x2D
LD_L_d8 = 0x2E
d8_1 = 0xFF    # L <- 0xFF
CPL = 0x2F

opcodes = [
    JR_NZ_r8,
    r8_0,
    LD_HL_d16,
    d16_low,
    d16_high,
    LDI_REF_HL_A,
    INC_HL,
    INC_H,
    DEC_H,
    LD_H_d8,
    d8_0,
    DAA,
    JR_NZ_r8,
    r8_0,
    ADD_HL_HL,
    LDI_A_REF_HL,
    DEC_HL,
    INC_L,
    DEC_L,
    LD_L_d8,
    d8_1,
    CPL
]

with open('games/test/test_ops_row_2.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))