PREFIX_CB = 0xCB

RL_B = 0x10
RL_C = 0x11
RL_D = 0x12
RL_E = 0x13
RL_H = 0x14
RL_L = 0x15
RL_REF_HL = 0x16
RL_A = 0x17
RR_B = 0x18
RR_C = 0x19
RR_D = 0x1A
RR_E = 0x1B
RR_H = 0x1C
RR_L = 0x1D
RR_REF_HL =0x1E
RR_A =0x1F

opcodes = [
    PREFIX_CB,
    RL_B,
    PREFIX_CB,
    RL_C,
    PREFIX_CB,
    RL_D,
    PREFIX_CB,
    RL_E,
    PREFIX_CB,
    RL_H,
    PREFIX_CB,
    RL_L,
    PREFIX_CB,
    RL_REF_HL,
    PREFIX_CB,
    RL_A,
    PREFIX_CB,
    RR_B,
    PREFIX_CB,
    RR_C,
    PREFIX_CB,
    RR_D,
    PREFIX_CB,
    RR_E,
    PREFIX_CB,
    RR_H,
    PREFIX_CB,
    RR_L,
    PREFIX_CB,
    RR_REF_HL,
    PREFIX_CB,
    RR_A,
]

with open('games/test/test_cb_ops_row_1.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))