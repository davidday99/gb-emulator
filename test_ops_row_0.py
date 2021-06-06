# initialize A to 0xFF

NOP = 0
LD_BC_d16 = 0x01
d16_low = 0xEF
d16_high = 0xBE  # BC <- 0xBEEF
LD_REF_BC_A = 0x02
INC_BC = 0x03
INC_B = 0x04
DEC_B = 0x05
LD_B_d8 = 0x06
d8_0 = 0x00    # B <- 0x00, was 0xBE
RLCA = 0x07
LD_REF_a16_SP = 0x08
a16_low = 0xEF
a16_high = 0xBE    # SP <- 0xBEEF
ADD_HL_BC = 0x09
LD_A_REF_BC = 0x0A
DEC_BC = 0x0B
INC_C = 0x0C
DEC_C = 0x0D
LD_C_d8 = 0x0E
d8_1 = 0xFF    # C <- 0xFF
RRCA = 0x0F

opcodes = [
    NOP,
    LD_BC_d16,
    d16_low,
    d16_high,
    LD_REF_BC_A,
    INC_BC,
    INC_B,
    DEC_B,
    LD_B_d8,
    d8_0,
    RLCA,
    LD_REF_a16_SP,
    a16_low,
    a16_high,
    ADD_HL_BC,
    LD_A_REF_BC,
    DEC_BC,
    INC_C,
    DEC_C,
    LD_C_d8,
    d8_1,
    RRCA
]

with open('games/test/test_ops_row_0.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))