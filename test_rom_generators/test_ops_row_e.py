# init A to 0xFF
# init C to 2

LDH_REF_a8_A = 0xE0
a8 = 1
POP_HL = 0xE1
LD_REF_C_A = 0xE2
PUSH_HL = 0xE5
AND_d8 = 0xE6
d8_0 = 0x55
ADD_SP_r8 = 0xE8
r8 = 1
LD_REF_a16_A = 0xEA
a16_low = 0x03
a16_high = 0xFF
XOR_d8 = 0xEE
d8_1 = 0xFF

opcodes = [
    LDH_REF_a8_A,
    a8,
    POP_HL,
    LD_REF_C_A,
    PUSH_HL,
    AND_d8,
    d8_0,
    ADD_SP_r8,
    r8,
    LD_REF_a16_A,
    a16_low,
    a16_high,
    XOR_d8,
    d8_1
]

with open('games/test/test_ops_row_e.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))