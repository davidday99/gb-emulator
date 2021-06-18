PREFIX_CB = 0xCB

SLA_B = 0x20
SLA_C = 0x21
SLA_D = 0x22
SLA_E = 0x23
SLA_H = 0x24
SLA_L = 0x25
SLA_REF_HL = 0x26
SLA_A = 0x27
SRA_B = 0x28
SRA_C = 0x29
SRA_D = 0x2A
SRA_E = 0x2B
SRA_H = 0x2C
SRA_L = 0x2D
SRA_REF_HL =0x2E
SRA_A =0x2F

opcodes = [
    PREFIX_CB,
    SLA_B,
    PREFIX_CB,
    SLA_C,
    PREFIX_CB,
    SLA_D,
    PREFIX_CB,
    SLA_E,
    PREFIX_CB,
    SLA_H,
    PREFIX_CB,
    SLA_L,
    PREFIX_CB,
    SLA_REF_HL,
    PREFIX_CB,
    SLA_A,
    PREFIX_CB,
    SRA_B,
    PREFIX_CB,
    SRA_C,
    PREFIX_CB,
    SRA_D,
    PREFIX_CB,
    SRA_E,
    PREFIX_CB,
    SRA_H,
    PREFIX_CB,
    SRA_L,
    PREFIX_CB,
    SRA_REF_HL,
    PREFIX_CB,
    SRA_A,
    PREFIX_CB,
    SRA_B,
    PREFIX_CB,
    SRA_C,
    PREFIX_CB,
    SRA_D,
    PREFIX_CB,
    SRA_E,
    PREFIX_CB,
    SRA_H,
    PREFIX_CB,
    SRA_L,
    PREFIX_CB,
    SRA_REF_HL,
    PREFIX_CB,
    SRA_A,
]

with open('games/test/test_cb_ops_row_2.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))