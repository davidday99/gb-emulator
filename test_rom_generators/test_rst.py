RST_00H = 0xC7
RST_08H = 0xCF
RST_10H = 0xD7
RST_18H = 0xDF
RST_20H = 0xE7
RST_28H = 0xEF
RST_30H = 0xF7
RST_38H = 0xFF

opcodes = [
    RST_00H,
    RST_08H,
    RST_10H,
    RST_18H,
    RST_20H,
    RST_28H,
    RST_30H,
    RST_38H
]

with open('games/test/test_rst.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))