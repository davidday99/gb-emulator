RET = 0xC9
RET_Z =0xC8
RET_C = 0xD8
RET_NZ = 0xC0
RET_NC = 0xD0
RETI = 0xD9

opcodes = [
    RET,
    RET_Z,
    RET_C,
    RET_NZ,
    RET_NC,
    RET_Z,
    RET_C,
    RET_NZ,
    RET_NC,
    RETI
]

with open('games/test/test_ret.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))