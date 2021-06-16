# initialize A to 0
# init B to 1
# init C to 2
# init D to 3
# init E to 4
# init H to 5
# init L to 6

ADD_A_B = 0x80
ADD_A_C = 0x81
ADD_A_D = 0x82
ADD_A_E = 0x83
ADD_A_H = 0x84
ADD_A_L = 0x85
ADD_A_REF_HL = 0x86
ADD_A_A = 0x87
ADC_A_B = 0x88
ADC_A_C = 0x89
ADC_A_D = 0x8A
ADC_A_E = 0x8B
ADC_A_H = 0x8C
ADC_A_L = 0x8D
ADC_A_REF_HL = 0x8E
ADC_A_A = 0x8F

opcodes = [
    ADD_A_B,
    ADD_A_C,
    ADD_A_D,
    ADD_A_E,
    ADD_A_H,
    ADD_A_L,
    ADD_A_REF_HL,
    ADD_A_A,
    ADC_A_B,
    ADC_A_C,
    ADC_A_D,
    ADC_A_E,
    ADC_A_H,
    ADC_A_L,
    ADC_A_REF_HL,
    ADC_A_A,
]

with open('games/test/test_ops_row_8.gb', 'wb') as f:
    for i in range(0x100):
        f.write(b'\x00')
    f.write(bytearray(opcodes))