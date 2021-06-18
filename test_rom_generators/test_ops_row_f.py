# init C to 2

LDH_A_REF_a8 = 0xF0
a8 = 1
POP_AF = 0xF1
LD_A_REF_C = 0xF2
DI = 0xF3
PUSH_AF = 0xF5
OR_d8 = 0xF6
d8_0 = 0x55
LDHL_SP_r8 = 0xF8
r8 = 1
LD_SP_HL = 0xF9
LD_A_ref_a16 = 0xFA
a16_low = 0x03
a16_high = 0xFF
EI = 0xFB
CP_d8 = 0xFE
d8_1 = 0xFF

opcodes = [
    LDH_A_REF_a8,
    a8,
    POP_AF,
    LD_A_REF_C,
    DI,
    PUSH_AF,
    OR_d8,
    d8_0,
    LDHL_SP_r8,
    r8,
    LD_SP_HL,
    LD_A_ref_a16,
    a16_low,
    a16_high,
    EI,
    CP_d8,
    d8_1
]

with open('games/test/test_ops_row_f.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))