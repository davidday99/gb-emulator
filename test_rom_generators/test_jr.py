JR_r8_fwd_0 = 0x18
r8_0 = 2
JR_r8_fwd_1 = 0x18
r8_1 = 2
JR_r8_bwd = 0x18
r8_2 = 0xFC  # offset of -4
JR_r8_no_jmp = 0x18
r8_3 = 0
JR_Z_r8 = 0x28
JR_C_r8 = 0x38
JR_NZ_r8 = 0x20
JR_NC_r8 = 0x30

opcodes = [
    JR_r8_fwd_0,
    r8_0,
    JR_r8_fwd_1,
    r8_1,
    JR_r8_bwd,
    r8_2,
    JR_r8_no_jmp,
    r8_3,
    JR_Z_r8,
    r8_3,
    JR_C_r8,
    r8_3,
    JR_NZ_r8,
    r8_3,
    JR_NC_r8,
    r8_3,
    JR_Z_r8,
    r8_3,
    JR_C_r8,
    r8_3,
    JR_NZ_r8,
    r8_3,
    JR_NC_r8,
    r8_3
]

with open('games/test/test_jr.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))