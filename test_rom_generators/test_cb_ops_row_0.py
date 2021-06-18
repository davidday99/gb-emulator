PREFIX_CB = 0xCB

RLC_B = 0x00
RLC_C = 0x01
RLC_D = 0x02
RLC_E = 0x03
RLC_H = 0x04
RLC_L = 0x05
RLC_REF_HL = 0x06
RLC_A = 0x07
RRC_B = 0x08
RRC_C = 0x09
RRC_D = 0x0A
RRC_E = 0x0B
RRC_H = 0x0C
RRC_L = 0x0D
RRC_REF_HL =0x0E
RRC_A =0x0F

opcodes = [
    PREFIX_CB,
    RLC_B,
    PREFIX_CB,
    RLC_C,
    PREFIX_CB,
    RLC_D,
    PREFIX_CB,
    RLC_E,
    PREFIX_CB,
    RLC_H,
    PREFIX_CB,
    RLC_L,
    PREFIX_CB,
    RLC_REF_HL,
    PREFIX_CB,
    RLC_A,
    PREFIX_CB,
    RRC_B,
    PREFIX_CB,
    RRC_C,
    PREFIX_CB,
    RRC_D,
    PREFIX_CB,
    RRC_E,
    PREFIX_CB,
    RRC_H,
    PREFIX_CB,
    RRC_L,
    PREFIX_CB,
    RRC_REF_HL,
    PREFIX_CB,
    RRC_A,
]

with open('games/test/test_cb_ops_row_0.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))