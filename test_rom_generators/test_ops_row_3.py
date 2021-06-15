# initialize A to 0xFF

JR_NC_r8 = 0x30
r8_0 = 0
LD_SP_d16 = 0x31
d16_low = 0xEF
d16_high = 0xBE
LDD_REF_HL_A = 0x32
INC_SP = 0x33
INC_REF_HL = 0x34
DEC_REF_HL = 0x35
LD_REF_HL_d8 = 0x36
d8_0 = 0xFF
SCF = 0x37
JR_C_r8 = 0x38
r8_1 = 0
ADD_HL_SP = 0x39
LDD_A_REF_HL = 0x3A
DEC_SP = 0x3B
INC_A = 0x3C
DEC_A = 0x3D
LD_A_d8 = 0x3E
d8_1 = 0x01
CCF = 0x3F


opcodes = [
    JR_NC_r8,
    r8_0,
    LD_SP_d16,
    d16_low,
    d16_high,
    LDD_HL_A,
    INC_SP,
    INC_REF_HL,
    DEC_REF_HL,
    LD_REF_HL_d8,
    d8_0,
    SCF,
    JR_C_r8,
    r8_1,
    ADD_HL_SP,
    LDD_A_REF_HL,
    DEC_SP,
    INC_A,
    DEC_A,
    LD_A_d8,
    d8_1,
    CCF
]

with open('games/test/test_ops_row_3.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))