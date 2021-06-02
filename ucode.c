#include <stdio.h>
#include "include/cpu.h"

enum operand {
    A,
    B,
    C,
    D,
    E,
    H,
    L,
    AF,
    BC,
    DE,
    HL,
    PC,
    SP,
    A8,
    D8,
    A16,
    D16,
    NONE
};

enum addressing_mode {
    REGISTER,
    REGISTER_INDIRECT,
    IMMEDIATE,
    IMMEDIATE_MEM,
    IMMEDIATE_MEM_INDIRECT,
    NA
};

enum condition {
    UNCONDITIONAL,
    NZ,
    Z,
    NC,
    CARRY
};

enum operation {
    LD,
    LDD,
    LDI,
    LDH,
    LDHL,
    PUSH,
    POP,
    ADD,
    ADC,
    SUB,
    SBC,
    AND,
    OR,
    XOR,
    CP,
    INC,
    DEC,
    SWAP,
    DAA,
    CPL,
    CCF,
    SCF,
    NOP,
    HALT,
    STOP,
    DI,
    EI,
    RLCA,
    RLA,
    RRCA,
    RRA,
    RLC,
    RL,
    RRC,
    RR,
    SLA,
    SRA,
    SRL,
    BIT,
    SET,
    RES,
    JP,
    JR,
    CALL,
    RST,
    RET,
    RETI
};

enum operation_type {
    MEMORY,
    ALU,
    SHIFTER,
    BITWISE,
    JUMP,
    MISC
};

typedef struct Instruction {
    char mnemonic[20];
    uint8_t opcode;
    enum operand destination;
    enum addressing_mode destination_type;
    enum operand source;
    enum addressing_mode source_type;
    enum operation operation;
    enum operation_type operation_type;
    enum condition condition;
    uint8_t action_taken_cycles;
    uint8_t action_not_taken_cycles;
    uint8_t bytes;
} Instruction;

const Instruction INSTRUCTIONS[] = {
    {"NOP", 0x00, NONE, NA, NONE, NA, MISC, UNCONDITIONAL, 4, 0, 1},
    {"LD BC, d16", 0x01, BC, REGISTER, D16, IMMEDIATE_MEM, MEMORY, UNCONDITIONAL, 3},
};
const Instruction CB_INSTRUCTIONS[] = {};

uint16_t get_register_value(CPU *cpu, enum operand reg) {
    uint16_t value;
    switch (reg) {
        case A:
            value = cpu->current_state.A;
            break;
        case B:
            value = cpu->current_state.B;
            break;
        case C:
            value = cpu->current_state.C;
            break;
        case D:
            value = cpu->current_state.D;
            break;
        case E:
            value = cpu->current_state.E;
            break;
        case H:
            value = cpu->current_state.H;
            break;
        case L:
            value = cpu->current_state.L;
            break;
        case AF:
            value = cpu->current_state.AF;
            break;
        case BC:
            value = cpu->current_state.BC;
            break;
        case DE:
            value = cpu->current_state.DE;
            break;
        case HL:
            value = cpu->current_state.HL;
            break;
        case PC:
            value = cpu->current_state.PC;
            break;
        case SP:
            value = cpu->current_state.SP;
            break;
    }
    return value;
}

void write_register(CPU *cpu, enum operand reg, uint16_t value) {
    if (reg <= L) {
        value = (uint8_t) value;
    }
    switch (reg) {
        case A:
            cpu->current_state.A = value;
            break;
        case B:
            value = cpu->current_state.B = value;
            break;
        case C:
            value = cpu->current_state.C = value;
            break;
        case D:
            value = cpu->current_state.D = value;
            break;
        case E:
            value = cpu->current_state.E = value;
            break;
        case H:
            value = cpu->current_state.H = value;
            break;
        case L:
            value = cpu->current_state.L = value;
            break;
        case AF:
            value = cpu->current_state.AF = value;
            break;
        case BC:
            value = cpu->current_state.BC = value;
            break;
        case DE:
            value = cpu->current_state.DE = value;
            break;
        case HL:
            value = cpu->current_state.HL = value;
            break;
        case PC:
            value = cpu->current_state.PC = value;
            break;
        case SP:
            value = cpu->current_state.SP = value;
            break;
    }
}

uint16_t get_operand(CPU *cpu, enum operand operand, enum addressing_mode addr_mode, uint8_t is_CB) {
    uint16_t op;
    switch (addr_mode) {
        case REGISTER:
            op = get_register_value(cpu, operand);
            break;

        case REGISTER_INDIRECT:
            op = cpu->RAM[get_register_value(cpu, operand)];

            if (operand == C) {
                op += 0xFF00;
            }
            break;

        case IMMEDIATE:
            op = operand;
            break;

        case IMMEDIATE_MEM:
            if (operand == A8) {
                op = (uint8_t) cpu->RAM[cpu->current_state.PC + 1 + is_CB];
            } else if (operand == D8) {
                op = (int8_t) cpu->RAM[cpu->current_state.PC + 1 + is_CB];
            } else if (operand == A16) {
                op = (uint16_t) cpu->RAM[cpu->current_state.PC + 1 + is_CB] | 
                        (cpu->RAM[cpu->current_state.PC + 2 + is_CB] << 8);
            } else if (operand == D16) {
                op = (int16_t) cpu->RAM[cpu->current_state.PC + 1 + is_CB] | 
                        (cpu->RAM[cpu->current_state.PC + 2 + is_CB] << 8);
            }
            break;

        case IMMEDIATE_MEM_INDIRECT:
            if (operand == A8) {
                op = (uint8_t) cpu->RAM[cpu->current_state.PC + 1 + is_CB];
                op += 0xFF00;
            } else if (operand == A16) {
                op = (uint16_t) cpu->RAM[cpu->current_state.PC + 1 + is_CB] | 
                        (cpu->RAM[cpu->current_state.PC + 2 + is_CB] << 8);
                op = cpu->RAM[op];
            } 

            break;

        default:
            break;
    }
    return op;
}

uint8_t read_memory(CPU *cpu, uint16_t address) {
    return cpu->RAM[address];
}

void write_memory(CPU *cpu, uint8_t value, uint16_t address) {
    cpu->RAM[address] = value;
}

void decode_test(CPU *cpu, uint8_t opcode, uint16_t *dest, uint16_t *src) {
    Instruction instruction;
    uint8_t is_CB = 0;
    if (opcode == 0xCB) {
        opcode = cpu->RAM[cpu->current_state.PC + 1];
        instruction = CB_INSTRUCTIONS[opcode];
        is_CB = 1;
    } else {
        instruction = INSTRUCTIONS[opcode];
    }

    *dest = get_operand(cpu, instruction.destination, instruction.destination_type, is_CB);
    *src = get_operand(cpu, instruction.source, instruction.source_type, is_CB);
}

void exec_ld(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    if (instruction->destination_type == REGISTER) {
        write_register(cpu, instruction->destination, src);
    } else if (instruction->destination_type == REGISTER_INDIRECT || 
                instruction->destination_type == IMMEDIATE_MEM_INDIRECT) {
        write_memory(cpu, dest, src);
    }
}

void handle_memory_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    switch (instruction->operation) {
        case LD:
            exec_ld(cpu, instruction, dest, src);
            break;
        case LDD:
            exec_ld(cpu, instruction, dest, src);
            cpu->next_state.HL--;
            break;
        case LDI:
            exec_ld(cpu, instruction, dest, src);
            cpu->next_state.HL++;
            break;
        case LDH:
            exec_ld(cpu, instruction, dest, src);
            break;
        default:
            break;
    }
}

void handle_alu_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    switch (instruction->operation) {
        case ADD:
            break;
        case ADC:
            break;
        case SUB:
            break;
        case SBC:
            break;
        case INC:
            break;
        case DEC:
            break;
        case AND:
            break;
        case CP:
            break;
        case OR:
            break;
        case XOR:
            break;
        default:
            break;
    }
}

void handle_shift_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    switch (instruction->operation) {
        case RL:
            break;
        case RLA:
            break;
        case RLC:
            break;
        case RLCA:
            break;
        case RR:
            break;
        case RRA:
            break;
        case RRC:
            break;
        case RRCA:
            break;
        case SLA:
            break;
        case SRA:
            break;
        case SRL:
            break;
        default:
            break;
    }
}

void handle_bitwise_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    uint8_t bit_mask = 1 << instruction->destination;
    uint16_t temp1, temp2;

    switch (instruction->operation) {
        case BIT:
            //set Z flag if bit == 0
            break;
        case SET:
            temp1 = instruction->destination_type == REGISTER ? 
                    get_register_value(cpu, instruction->destination) :
                    read_memory(cpu, dest);
            
            temp1 |= bit_mask;

            instruction->destination_type == REGISTER ? 
                write_register(cpu, instruction->destination, temp1) :
                write_memory(cpu, temp1, dest);
            break;
        case RES:
            temp1 = instruction->destination_type == REGISTER ? 
                    get_register_value(cpu, instruction->destination) :
                    read_memory(cpu, dest);
            
            temp1 &= ~bit_mask;

            instruction->destination_type == REGISTER ? 
                write_register(cpu, instruction->destination, temp1) :
                write_memory(cpu, temp1, dest);
            break;
        case SWAP:
            temp1 = instruction->destination_type == REGISTER ? 
                    get_register_value(cpu, instruction->destination) :
                    read_memory(cpu, dest);

            temp2 = temp1 << 4;
            temp1 &= 0xF0;
            temp1 >>= 4;
            temp1 = (uint8_t) temp1 | temp2;
            
            instruction->destination_type == REGISTER ? 
                write_register(cpu, instruction->destination, temp1) :
                write_memory(cpu, temp1, dest);
            break;
        default:
            break;
    }
}

void handle_jump_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    switch (instruction->operation) {
        case CALL:
            break;
        case JP:
            break;
        case JR:
            break;
        case RET:
            break;
        case RETI:
            break;
        case RST:
            break;
        default:
            break;
    }
}

void handle_misc_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    switch (instruction->operation) {
        case CCF:
            break;
        case CPL:
            break;
        case DAA:
            break;
        case DI:
            break;
        case EI:
            break;
        case HALT:
            break;
        case NOP:
            break;
        case SCF:
            break;
        case STOP:
            break;
        default:
            break;
    }
}

void execute_test(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    switch (instruction->operation_type) {
        case MEMORY:
            break;
        case ALU:
            break;
        case SHIFTER:
            break;
        case BITWISE:
            break;
        case JUMP:
            break;
        case MISC:
            break;
        default:
            break;
    }
}

int main() {
    CPU cpu;

    FILE *f = fopen("games\\test.gb", "rb");

    load_program(f, &cpu);

    cpu.current_state.PC = 0x103;
    
    uint16_t dest, src;

    decode_test(&cpu, 0x01, &dest, &src);

    return 0;
}

