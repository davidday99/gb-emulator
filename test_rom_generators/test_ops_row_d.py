POP_DE = 0xD1
PUSH_DE = 0xD5
SUB_d8 = 0xD6
d8_0 = 1
SBC_A_d8 = 0xDE
d8_1 = 0xFF


opcodes = [
    POP_DE,
    PUSH_DE,
    SUB_d8,
    d8_0,
    SBC_A_d8,
    d8_1
]

with open('games/test/test_ops_row_d.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))