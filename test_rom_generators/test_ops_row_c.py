# initialize A to 0
# init B to 1
# init C to 2
# init D to 3
# init E to 4
# init H to 5
# init L to 6

POP_BC = 0xC1
PUSH_BC = 0xC5
ADD_A_d8 = 0xC6
d8_0 = 0xFF
PREFIX_CB = 0xCB
ADC_A_d8 = 0xCE
d8_1 = 1

opcodes = [
    POP_BC,
    PUSH_BC,
    ADD_A_d8,
    d8_0,
    PREFIX_CB,
    ADC_A_d8,
    d8_1
]

with open('games/test/test_ops_row_c.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))