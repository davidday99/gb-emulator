JP_a16 = 0xC3
a16_low = 0x00
a16_high = 0xC0
JP_Z_a16 =0xCA
JP_C_a16 = 0xDA
JP_NZ_a16 = 0xC2
JP_NC_a16 = 0xD2
JP_REF_HL = 0xE9

opcodes = [
    JP_a16,
    a16_low,
    a16_high,
    JP_Z_a16, 
    a16_low,
    a16_high,
    JP_C_a16,
    a16_low,
    a16_high,
    JP_NZ_a16, 
    a16_low,
    a16_high,
    JP_NC_a16,
    a16_low,
    a16_high,
    JP_Z_a16, 
    a16_low,
    a16_high,
    JP_C_a16,
    a16_low,
    a16_high,
    JP_NZ_a16, 
    a16_low,
    a16_high,
    JP_NC_a16,
    a16_low,
    a16_high,
    JP_REF_HL
]

with open('games/test/test_jp.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))