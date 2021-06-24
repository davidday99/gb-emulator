CALL_a16 = 0xCD
a16_low = 0x00
a16_high = 0xC0
CALL_Z_a16 =0xCC
CALL_C_a16 = 0xDC
CALL_NZ_a16 = 0xC4
CALL_NC_a16 = 0xD4

opcodes = [
    CALL_a16,
    a16_low,
    a16_high,
    CALL_Z_a16, 
    a16_low,
    a16_high,
    CALL_C_a16,
    a16_low,
    a16_high,
    CALL_NZ_a16, 
    a16_low,
    a16_high,
    CALL_NC_a16,
    a16_low,
    a16_high,
    CALL_Z_a16, 
    a16_low,
    a16_high,
    CALL_C_a16,
    a16_low,
    a16_high,
    CALL_NZ_a16, 
    a16_low,
    a16_high,
    CALL_NC_a16,
    a16_low,
    a16_high
]

with open('games/test/test_call.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))