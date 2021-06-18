PREFIX_CB = 0xCB

SWAP_B = 0x30
SWAP_C = 0x31
SWAP_D = 0x32
SWAP_E = 0x33
SWAP_H = 0x34
SWAP_L = 0x35
SWAP_REF_HL = 0x36
SWAP_A = 0x37
SRL_B = 0x38
SRL_C = 0x39
SRL_D = 0x3A
SRL_E = 0x3B
SRL_H = 0x3C
SRL_L = 0x3D
SRL_REF_HL =0x3E
SRL_A =0x3F

opcodes = [
    PREFIX_CB,
    SWAP_B,
    PREFIX_CB,
    SWAP_C,
    PREFIX_CB,
    SWAP_D,
    PREFIX_CB,
    SWAP_E,
    PREFIX_CB,
    SWAP_H,
    PREFIX_CB,
    SWAP_L,
    PREFIX_CB,
    SWAP_REF_HL,
    PREFIX_CB,
    SWAP_A,
    PREFIX_CB,
    SRL_B,
    PREFIX_CB,
    SRL_C,
    PREFIX_CB,
    SRL_D,
    PREFIX_CB,
    SRL_E,
    PREFIX_CB,
    SRL_H,
    PREFIX_CB,
    SRL_L,
    PREFIX_CB,
    SRL_REF_HL,
    PREFIX_CB,
    SRL_A,
]

with open('games/test/test_cb_ops_row_3.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))