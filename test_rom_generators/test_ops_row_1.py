# initialize A to 0xFF

STOP = 0x10
LD_DE_d16 = 0x11
d16_low = 0xEF
d16_high = 0xBE  # DE <- 0xBEEF
LD_REF_DE_A = 0x12
INC_DE = 0x13
INC_D = 0x14
DEC_D = 0x15
LD_D_d8 = 0x16
d8_0 = 0x00    # D <- 0x00, was 0xBE
RLA = 0x17
JR_r8 = 0x18
r8 = 0x00    # JP 0, essentially NOP
ADD_HL_DE = 0x19
LD_A_REF_DE = 0x1A
DEC_DE = 0x1B
INC_E = 0x1C
DEC_E = 0x1D
LD_E_d8 = 0x1E
d8_1 = 0xFF    # C <- 0xFF
RRA = 0x1F

opcodes = [
    LD_DE_d16,
    d16_low,
    d16_high,
    LD_REF_DE_A,
    INC_DE,
    INC_D,
    DEC_D,
    LD_D_d8,
    d8_0,
    RLA,
    JR_r8,
    r8,
    ADD_HL_DE,
    LD_A_REF_DE,
    DEC_DE,
    INC_E,
    DEC_E,
    LD_E_d8,
    d8_1,
    RRA,
    STOP
]

with open('games/test/test_ops_row_1.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))