/* SM83 CPU Core */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cpu.h"
#include "../include/isa-sm83.h"

#define Low8bits(x) ((x) & 0xFF)

void enable_interrupts(CPU *cpu);
void disable_interrupts(CPU *cpu);
void enable_cb_mode(CPU *cpu);
void disable_cb_mode(CPU *cpu);
void start_cpu(CPU *cpu);
void stop_cpu(CPU *cpu);
void halt_cpu(CPU *cpu);

/************************************************************/
/*                                                          */
/* REGISTER ACCESS FUNCTIONS                                */
/*                                                          */
/************************************************************/

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
    if (reg <= L) {
        value = (int8_t) value;
    }
    return value;
}

void write_register(CPU *cpu, enum operand reg, uint16_t value) {
    switch (reg) {
        case A:
            cpu->next_state.A = value;
            break;
        case B:
            cpu->next_state.B = value;
            break;
        case C:
            cpu->next_state.C = value;
            break;
        case D:
            cpu->next_state.D = value;
            break;
        case E:
            cpu->next_state.E = value;
            break;
        case H:
            cpu->next_state.H = value;
            break;
        case L:
            cpu->next_state.L = value;
            break;
        case AF:
            cpu->next_state.AF = value;
            break;
        case BC:
            cpu->next_state.BC = value;
            break;
        case DE:
            cpu->next_state.DE = value;
            break;
        case HL:
            cpu->next_state.HL = value;
            break;
        case PC:
            cpu->next_state.PC = value;
            break;
        case SP:
            cpu->next_state.SP = value;
            break;
    }
}

/************************************************************/
/*                                                          */
/* FLAG REGISTER FUNCTIONS                                  */
/*                                                          */
/************************************************************/

void set_z_flag(CPU *cpu, uint8_t z) {
    uint8_t is_zero = !z;
    if (is_zero) {
        cpu->next_state.F |= FLAG_Z_MASK;
    } else {
        cpu->next_state.F &= ~FLAG_Z_MASK;
    }
}

void set_n_flag(CPU *cpu, uint8_t n) {
    if (n != 0) {
        cpu->next_state.F |= FLAG_N_MASK;
    } else {
        cpu->next_state.F &= ~FLAG_N_MASK;
    }
}

void set_h_flag(CPU *cpu, uint8_t h) {
    if (h != 0) {
        cpu->next_state.F |= FLAG_H_MASK;
    } else {
        cpu->next_state.F &= ~FLAG_H_MASK;
    }
}

void set_c_flag(CPU *cpu, uint8_t c) {
    if (c != 0) {
        cpu->next_state.F |= FLAG_C_MASK;
    } else {
        cpu->next_state.F &= ~FLAG_C_MASK;
    }
}

void set_flags(CPU *cpu, uint8_t flag_mask, uint8_t z, uint8_t n, uint8_t h, uint8_t c) {
    if (flag_mask & FLAG_Z_MASK) {
        set_z_flag(cpu, z);
    }
    if (flag_mask & FLAG_N_MASK) {
        set_n_flag(cpu, n);
    }
    if (flag_mask & FLAG_H_MASK) {
        set_h_flag(cpu, h);
    }
    if (flag_mask & FLAG_C_MASK) {
        set_c_flag(cpu, c);
    }
}

uint8_t detect_half_carry(uint8_t op1, uint8_t op2) {
    op1 &= 0xF;
    op2 &= 0xF;

    uint8_t sum = op1 + op2;

    return (sum & 0x10) == 0x10;
}

uint8_t detect_carry(uint8_t op1, uint8_t op2, uint8_t is_CP) {
    if (is_CP) {
        return op1 < op2;
    } else {
        op1 &= 0xFF;
        op2 &= 0xFF;

        uint16_t sum = op1 + op2;
        
        return (sum & 0x100) == 0x100;
    }
}

uint8_t check_condition(CPU *cpu, enum condition cc) {
    uint8_t cond = 0;
    switch (cc) {
        case UNCONDITIONAL:
            cond = 1;
            break;
        case NZ:
            cond = (cpu->current_state.F & FLAG_Z_MASK) == 0;
            break;
        case Z:
            cond = (cpu->current_state.F & FLAG_Z_MASK) != 0;
            break;
        case NC:
            cond = (cpu->current_state.F & FLAG_C_MASK) == 0;
            break;
        case CARRY:
            cond = (cpu->current_state.F & FLAG_C_MASK) != 0;
    }
    return cond;
}

/************************************************************/
/*                                                          */
/* MEMORY ACCESS FUNCTIONS                                  */
/*                                                          */
/************************************************************/

uint8_t read_memory(CPU *cpu, uint16_t address) {
    cpu->next_state.CYCLE_COUNT += MEM_CYCLE_DELAY;
    return cpu->RAM[address];
}

void write_memory(CPU *cpu, uint8_t value, uint16_t address) {
    if (address == P1_REGISTER)
        return;
    else 
        cpu->RAM[address] = value;

    if (address == DMA_REGISTER)
        cpu->dma_flag = 1;

    cpu->next_state.CYCLE_COUNT += MEM_CYCLE_DELAY;
}

/************************************************************/
/*                                                          */
/* DECODE/EXECUTE HELPER FUNCTIONS                          */
/*                                                          */
/************************************************************/

uint16_t get_operand(CPU *cpu, enum operand operand, enum addressing_mode addr_mode) {
    uint16_t op;
    switch (addr_mode) {
        case REGISTER:
            op = get_register_value(cpu, operand);
            break;

        case REGISTER_INDIRECT:
            op = get_register_value(cpu, operand);

            if (operand == C) {
                op &= 0x00FF;
                op += 0xFF00;
            }
            break;

        case IMMEDIATE:
            op = operand;
            break;

        case IMMEDIATE_MEM:
            if (operand == A8) {
                op = read_memory(cpu, cpu->current_state.PC + 1);
            } else if (operand == D8) {
                op = (int8_t) read_memory(cpu, cpu->current_state.PC + 1);  // cast to sign-extend
            } else if (operand == A16) {
                op = read_memory(cpu, cpu->current_state.PC + 1) | 
                        (read_memory(cpu, cpu->current_state.PC + 2) << 8);
            } else if (operand == D16) {
                op = read_memory(cpu, cpu->current_state.PC + 1) | 
                    (read_memory(cpu, cpu->current_state.PC + 2) << 8);
            }
            break;

        case IMMEDIATE_MEM_INDIRECT:
            if (operand == A8) {
                op = read_memory(cpu, cpu->current_state.PC + 1);
                op += 0xFF00;
            } else if (operand == A16) {
                op = read_memory(cpu, cpu->current_state.PC + 1) | 
                    (read_memory(cpu, cpu->current_state.PC + 2) << 8);
            } 

            break;

        case NA:
            op = 0;
            break;

        default:
            break;
    }
    return op;
}

void exec_ld(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    if (instruction->destination_type == REGISTER) {
        write_register(cpu, instruction->destination, src);
    } else if (instruction->destination_type == REGISTER_INDIRECT || 
                instruction->destination_type == IMMEDIATE_MEM_INDIRECT) {
        write_memory(cpu, src, dest);
    }
}

void handle_ld_st_mov_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    uint16_t temp;
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
        case LDHL:
            exec_ld(cpu, instruction, dest, src + cpu->current_state.SP);
            break;
        case PUSH:
            write_memory(cpu, (src & 0xFF00) >> 8, cpu->current_state.SP - 1);
            write_memory(cpu, src & 0xFF, cpu->current_state.SP - 2);
            cpu->next_state.SP = cpu->current_state.SP - 2;
            break;
        case POP:
            temp = read_memory(cpu, cpu->current_state.SP) |
                    (read_memory(cpu, cpu->current_state.SP + 1) << 8);
            write_register(cpu, instruction->destination, temp);
            cpu->next_state.SP = cpu->current_state.SP + 2;
        default:
            break;
    }
    cpu->next_state.PC = cpu->current_state.PC + instruction->bytes;
}

void handle_alu_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    switch (instruction->operation) {
        uint16_t temp1, temp2, temp3;
        case ADD:
            write_register(cpu, instruction->destination, dest + src);
            if (instruction->destination <= L) {
                set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK |FLAG_H_MASK | FLAG_C_MASK, dest + src, 0, detect_half_carry(dest, src), detect_carry(dest, src, 0));
            } else {
                set_flags(cpu, FLAG_N_MASK |FLAG_H_MASK | FLAG_C_MASK, 0, 0, detect_half_carry(dest, src), detect_carry(dest, src, 0));
            }
            break;
        case ADC:
            temp1 = (cpu->current_state.F & FLAG_C_MASK) >> 4;
            temp2 = detect_half_carry(dest, src) | detect_half_carry(dest + src, temp1);
            temp3 = detect_carry(dest, src, 0) | detect_carry(dest + src, temp1, 0);
            write_register(cpu, instruction->destination, dest + src + temp1);
            set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK |FLAG_H_MASK | FLAG_C_MASK, dest + src + temp1, 0, temp2, temp3);
            break;
        case SUB:
            write_register(cpu, instruction->destination, dest - src);
            set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK |FLAG_H_MASK | FLAG_C_MASK, dest - src, 1, detect_half_carry(dest, -src), detect_carry(dest, -src, 0));
            break;
        case SBC:
            temp1 = (cpu->current_state.F & FLAG_C_MASK) >> 4;
            temp2 = detect_half_carry(dest, -src) | detect_half_carry(dest - src, -temp1);
            temp3 = detect_carry(dest, -src, 0) | detect_carry(dest - src, -temp1, 0);
            write_register(cpu, instruction->destination, dest - src - temp1);
            set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK |FLAG_H_MASK | FLAG_C_MASK, dest - src - temp1, 0, temp2, temp3);
            break;
            break;
        case INC:
            if (instruction->destination_type == REGISTER) {
                write_register(cpu, instruction->destination, dest + 1);
                temp1 = dest + 1;
                temp2 = detect_half_carry(dest, 1);
            } else {
                write_memory(cpu, src + 1, dest);
                temp1 = src + 1;
                temp2 = detect_half_carry(src, 1);
            }
            if (instruction->destination <= L || instruction->destination_type == REGISTER_INDIRECT) {
                set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK, temp1, 0, temp2, 0);
            }
            break;
        case DEC:
            if (instruction->destination_type == REGISTER) {
                write_register(cpu, instruction->destination, dest - 1);
                temp1 = dest - 1;
                temp2 = detect_half_carry(dest, -1);
            } else {
                write_memory(cpu, src - 1, dest);
                temp1 = src - 1;
                temp2 = detect_half_carry(src, -1);
            }
            if (instruction->destination <= L || instruction->destination_type == REGISTER_INDIRECT) {
                set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK, temp1, 1, temp2, 0);
            }
            break;
        case AND:
            write_register(cpu, instruction->destination, dest & src);
            set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK |FLAG_H_MASK | FLAG_C_MASK, dest & src, 0, 1, 0);
            break;
        case CP:
            set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK | FLAG_C_MASK, dest - src, 1, detect_half_carry(dest, -src), detect_carry(dest, src, 1));
            break;
        case OR:
            write_register(cpu, instruction->destination, dest | src);
            set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK | FLAG_C_MASK, dest | src, 0 , 0, 0);
            break;
        case XOR:
            write_register(cpu, instruction->destination, dest ^ src);
            set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK | FLAG_C_MASK, dest ^ src, 0 , 0, 0);
            break;
        default:
            break;
    }
    if (instruction->destination >= AF && instruction->destination <= SP && instruction->destination_type == REGISTER) {
        cpu->next_state.CYCLE_COUNT += ALU_DELAY_16_BIT;
    }
    cpu->next_state.PC = cpu->current_state.PC + instruction->bytes;
}

void handle_shift_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    src = Low8bits(src);
    uint16_t temp, temp1;
    switch (instruction->operation) {
        case RL:
            temp = cpu->current_state.F & FLAG_C_MASK;
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 0x80);
            src <<= 1;
            src |= (temp >> 4);
            set_flags(cpu, FLAG_Z_MASK, src, 0, 0, 0);
            break;
        case RLA:
            temp = cpu->current_state.F & FLAG_C_MASK;
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 0x80);
            src <<= 1;
            src |= (temp >> 4);
            break;
        case RLC:
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 0x80);
            temp = src & 0x80;
            src <<= 1;
            src |= (temp >> 7);
            set_flags(cpu, FLAG_Z_MASK, src, 0, 0, 0);
            break;
        case RLCA:
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 0x80);
            temp = src & 0x80;
            src <<= 1;
            src |= (temp >> 7);
            break;
        case RR:
            temp = cpu->current_state.F & FLAG_C_MASK;
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 1);
            src >>= 1;
            src |= (temp << 3);
            set_flags(cpu, FLAG_Z_MASK, src, 0, 0, 0);
            break;
        case RRA:
            temp = cpu->current_state.F & FLAG_C_MASK;
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 1);
            src >>= 1;
            src |= (temp << 3);
            break;
        case RRC:
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 1);
            temp = src & 1;
            src >>= 1;
            src |= (temp << 7);
            set_flags(cpu, FLAG_Z_MASK, src, 0, 0, 0);
            break;
        case RRCA:
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 1);
            temp = src & 1;
            src >>= 1;
            src |= (temp << 7);
            break;
        case SLA:
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 0x80);
            temp = src & 0x80;
            src <<= 1;
            set_flags(cpu, FLAG_Z_MASK, src, 0, 0, 0);
            break;
        case SRA:
            temp = src & 0x80; // preserve sign
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 1);
            src >>= 1;
            src |= temp;
            set_flags(cpu, FLAG_Z_MASK, src, 0, 0, 0);
            break;
        case SRL:
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 1);
            src >>= 1;
            set_flags(cpu, FLAG_Z_MASK, src, 0, 0, 0);
            break;
        case SWAP:
            temp = (src & 0x0F) << 4;
            temp1 = (src & 0xF0) >> 4;
            src = (uint8_t) temp | temp1;
            set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK | FLAG_C_MASK, src, 0, 0, 0);
            break;
        default:
            break;
    }
    instruction->destination_type == REGISTER ?
        write_register(cpu, instruction->destination, src) :
        write_memory(cpu, src, dest);
    cpu->next_state.PC = cpu->current_state.PC + instruction->bytes;
}

/************************************************************/
/*                                                          */
/* Procedure : get_bit                                      */
/*                                                          */
/* Purpose   : Decode which bit is being operated on based  */ 
/*             on the opcode                                */
/*                                                          */
/************************************************************/
uint8_t get_bit(uint8_t opcode) {
    uint8_t high_nibble = (opcode & 0xF0) >> 4;
    uint8_t low_nibble = opcode & 0xF;
    uint8_t bit;
    switch (high_nibble) {
        case 4:
        case 8:
        case 12:
            bit = low_nibble < 8 ? 0 : 1;
            break;
        case 5:
        case 9:
        case 13:
            bit = low_nibble < 8 ? 2 : 3;
            break;
        case 6:
        case 10:
        case 14:
            bit = low_nibble < 8 ? 4 : 5;
            break;
        case 7:
        case 11:
        case 15:
            bit = low_nibble < 8 ? 6 : 7;
            break;
        default:
            break;
    }
    return bit;
}

void handle_bitwise_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    uint8_t bit_mask = 1 << get_bit(instruction->opcode);

    switch (instruction->operation) {
        case BIT:
            src &= bit_mask;
            set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK, src, 0, 1, 0);
            break;
        case SET:
            src |= bit_mask;
            break;
        case RES:            
            src &= ~bit_mask;
            break;
        default:
            break;
    }
    if (instruction->operation != BIT) {
        instruction->destination_type == REGISTER ? 
            write_register(cpu, instruction->destination, src) :
            write_memory(cpu, src, dest);
    }
    cpu->next_state.PC = cpu->current_state.PC + instruction->bytes;
}

void handle_jump_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    uint16_t temp;
    switch (instruction->operation) {
        case CALL:
            write_memory(cpu, ((cpu->current_state.PC + instruction->bytes) & 0xFF00) >> 8, cpu->current_state.SP - 1);
            write_memory(cpu, ((cpu->current_state.PC + instruction->bytes) & 0xFF), cpu->current_state.SP - 2);
            cpu->next_state.SP = cpu->current_state.SP - 2;
            cpu->next_state.PC = dest;
            break;
        case JP:
            cpu->next_state.PC = dest;
            break;
        case JR:
            cpu->next_state.PC = cpu->current_state.PC + instruction->bytes + dest;
            break;
        case RET:
            temp = read_memory(cpu, cpu->current_state.SP) |
                    (read_memory(cpu, cpu->current_state.SP + 1) << 8);
            cpu->next_state.SP = cpu->current_state.SP + 2;
            cpu->next_state.PC = temp;
            break;
        case RETI:
            temp = read_memory(cpu, cpu->current_state.SP) |
                    (read_memory(cpu, cpu->current_state.SP + 1) << 8);
            cpu->next_state.SP = cpu->current_state.SP + 2;
            cpu->next_state.PC = temp;
            enable_interrupts(cpu);
            break;
        case RST:
            write_memory(cpu, ((cpu->current_state.PC + instruction->bytes) & 0xFF00) >> 8, cpu->current_state.SP - 1);
            write_memory(cpu, (cpu->current_state.PC + instruction->bytes) & 0xFF, cpu->current_state.SP - 2);
            cpu->next_state.SP = cpu->current_state.SP - 2;
            cpu->next_state.PC = dest;
            break;
        default:
            break;
    }
    if (instruction->opcode != 0xE9) {
        cpu->next_state.CYCLE_COUNT += JUMP_DELAY;
    }
}

void handle_misc_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    switch (instruction->operation) {
        case CCF:
            set_flags(cpu, FLAG_N_MASK | FLAG_H_MASK | FLAG_C_MASK, 0, 0, 0, !(cpu->current_state.F & FLAG_C_MASK));
            break;
        case CPL:
            write_register(cpu, instruction->destination, ~dest);
            set_flags(cpu, FLAG_N_MASK | FLAG_H_MASK, 0, 1, 1, 0);
            break;
        case DAA:
            if ((cpu->current_state.F & FLAG_N_MASK) == 0) {
                if (cpu->current_state.F & FLAG_C_MASK) {
                    write_register(cpu, instruction->destination, dest + 0x60);
                    set_flags(cpu, FLAG_H_MASK | FLAG_C_MASK, 0, 0, 0, 1);
                }
                if ((cpu->current_state.F & FLAG_H_MASK) || (dest & 0x0F) > 0x09) {
                    write_register(cpu, instruction->destination, dest + 0x06);
                }
            } else {
                if (cpu->current_state.F & FLAG_C_MASK) {
                    write_register(cpu, instruction->destination, dest - 0x60);
                }
                if (cpu->current_state.F & FLAG_H_MASK) {
                    write_register(cpu, instruction->destination, dest - 0x06);
                }
            }
            set_flags(cpu, FLAG_Z_MASK | FLAG_H_MASK, get_register_value(cpu, instruction->destination), 0, 0, 0);
            break;
        case DI:
            disable_interrupts(cpu);
            break;
        case EI:
            enable_interrupts(cpu);
            break;
        case CB_PREFIX:
            break;
        case HALT:
            halt_cpu(cpu);
            break;
        case NOP:
            break;
        case SCF:
            set_flags(cpu, FLAG_N_MASK | FLAG_H_MASK | FLAG_C_MASK, 0, 0, 0, 1);
            break;
        case STOP:
            stop_cpu(cpu);
            break;
        default:
            break;
    }
    cpu->next_state.PC = cpu->current_state.PC + instruction->bytes;
}

/************************************************************/
/*                                                          */
/* CPU CONTROL FUNCTIONS                                    */
/*                                                          */
/************************************************************/

/************************************************************/
/*                                                          */
/* Procedure : enable_cb_mode                               */
/*                                                          */
/* Purpose   : Enable CB Mode when a CB prefix is fetched   */ 
/*                                                          */
/************************************************************/
void enable_cb_mode(CPU *cpu) {
    cpu->CB_mode = 1;
}

/************************************************************/
/*                                                          */
/* Procedure : disable_cb_mode                              */
/*                                                          */
/* Purpose   : Disable CB Mode after a CB instruction       */ 
/*             is executed                                  */
/*                                                          */
/************************************************************/
void disable_cb_mode(CPU *cpu) {
    cpu->CB_mode = 0;
}

/************************************************************/
/*                                                          */
/* Procedure : toggle_cb_mode                               */
/*                                                          */
/* Purpose   : Toggle CB Mode                               */ 
/*                                                          */
/************************************************************/
void toggle_cb_mode(CPU *cpu) {
    cpu->CB_mode = !cpu->CB_mode;
}

/************************************************************/
/*                                                          */
/* Procedure : enable_interrupts                            */
/*                                                          */
/* Purpose   : Enable CPU interrupts                        */ 
/*                                                          */
/************************************************************/
void enable_interrupts(CPU *cpu) {
    cpu->interrupts_enabled = 1;
}

/************************************************************/
/*                                                          */
/* Procedure : disable_interrupts                           */
/*                                                          */
/* Purpose   : Disable CPU interrupts                       */
/*                                                          */
/************************************************************/
void disable_interrupts(CPU *cpu) {
    cpu->interrupts_enabled = 0;
}

/************************************************************/
/*                                                          */
/* Procedure : set_dma_flag                                 */
/*                                                          */
/* Purpose   : Indicate DMA is ready to begin               */ 
/*                                                          */
/************************************************************/
void set_dma_flag(CPU *cpu) {
    cpu->dma_flag = 1;
}

/************************************************************/
/*                                                          */
/* Procedure : reset_dma_flag                               */
/*                                                          */
/* Purpose   : Clear DMA flag after DMA service begins      */
/*                                                          */
/************************************************************/
void reset_dma_flag(CPU *cpu) {
    cpu->dma_flag = 0;
}

/************************************************************/
/*                                                          */
/* Procedure : start CPU                                    */
/*                                                          */
/* Purpose   : Allow CPU to operate normally                */
/*                                                          */
/************************************************************/
void start_cpu(CPU *cpu) {
    cpu->stopped = 0;
}

/************************************************************/
/*                                                          */
/* Procedure : stop_cpu                                     */
/*                                                          */
/* Purpose   : Halt CPU operation                           */
/*                                                          */
/************************************************************/
void stop_cpu(CPU *cpu) {
    cpu->stopped = 1;
}

/************************************************************/
/*                                                          */
/* Procedure : halt_cpu                                     */
/*                                                          */
/* Purpose   : Halt CPU operation. Exact effect depends     */
/*             on the state of IME flag but hasn't yet      */
/*             been implemented                             */
/*                                                          */
/************************************************************/
// TODO: implement hardware bug found in GB CPU
void halt_cpu(CPU *cpu) {
    cpu->low_power_mode = 1;
}

/************************************************************/
/*                                                          */
/* Procedure : service_v_blank                              */
/*                                                          */
/* Purpose   : Push PC onto the stack and jump to the       */
/*             V-Blank ISR only if V-Blank interrupt        */
/*             is enabled                                   */
/*                                                          */
/************************************************************/
void service_v_blank(CPU *cpu) {
    disable_interrupts(cpu);
    cpu->RAM[IF_REGISTER] &= ~V_BLANK_MASK;
    write_memory(cpu, (cpu->current_state.PC & 0xFF00) >> 8, cpu->current_state.SP - 1);
    write_memory(cpu, cpu->current_state.PC & 0xFF, cpu->current_state.SP - 2);
    cpu->next_state.SP = cpu->current_state.SP - 2;
    cpu->current_state.SP = cpu->next_state.SP;
    cpu->next_state.PC = V_BLANK_ADDRESS;
    cpu->current_state.PC = cpu->next_state.PC;
}

void service_lcdc_status(CPU *cpu) {
    disable_interrupts(cpu);
    cpu->RAM[IF_REGISTER] &= ~LCDC_STATUS_MASK;
    write_memory(cpu, (cpu->current_state.PC & 0xFF00) >> 8, cpu->current_state.SP - 1);
    write_memory(cpu, cpu->current_state.PC & 0xFF, cpu->current_state.SP - 2);
    cpu->next_state.SP = cpu->current_state.SP - 2;
    cpu->current_state.SP = cpu->next_state.SP;
    cpu->next_state.PC = LCDC_STATUS_ADDRESS;
    cpu->current_state.PC = cpu->next_state.PC;
}

void service_tim_oflow(CPU *cpu) {
    disable_interrupts(cpu);
    cpu->RAM[IF_REGISTER] &= ~TIM_OFLOW_MASK;
    write_memory(cpu, (cpu->current_state.PC & 0xFF00) >> 8, cpu->current_state.SP - 1);
    write_memory(cpu, cpu->current_state.PC & 0xFF, cpu->current_state.SP - 2);
    cpu->next_state.SP = cpu->current_state.SP - 2;
    cpu->next_state.PC = TIM_OFLOW_ADDRESS;
}

/************************************************************/
/*                                                          */
/* Procedure : service_interrupts                           */
/*                                                          */
/* Purpose   : Check for pending interrupts based           */
/*             on the priority built into the SM83          */
/*                                                          */
/************************************************************/
void service_interrupts(CPU *cpu) {
    uint8_t interrupts = cpu->RAM[IF_REGISTER];
    uint8_t interrupt_enabled = cpu->RAM[IE_REGISTER];

    if ((interrupts & V_BLANK_MASK) &&
        (interrupt_enabled & V_BLANK_MASK)) {
            service_v_blank(cpu);
    } else if ((interrupts & LCDC_STATUS_MASK) &&
        (interrupt_enabled & LCDC_STATUS_MASK)) {
            service_lcdc_status(cpu);
    } else if ((interrupts & TIM_OFLOW_MASK) &&
        (interrupt_enabled & TIM_OFLOW_MASK)) {
            service_tim_oflow(cpu);
    }

    //true if at least one interrupt was serviced, so add cycle delay
    if (interrupts & interrupt_enabled) {
        cpu->current_state.CYCLE_COUNT += SERVICE_INTERRUPT_CYCLE_DELAY;
        cpu->next_state.CYCLE_COUNT = cpu->current_state.CYCLE_COUNT;
    }
}

/************************************************************/
/*                                                          */
/* Procedure : init_cpu                                     */
/*                                                          */
/* Purpose   : initialize CPU default values                */ 
/*                                                          */
/************************************************************/
void init_cpu(CPU *cpu) {
    cpu->next_state.AF = 0;
    cpu->next_state.BC = 0x0013;
    cpu->next_state.DE = 0x00D8;
    cpu->next_state.HL = 0x014D;
    cpu->next_state.PC = 0;
    cpu->next_state.SP = 0xFFFE;
    cpu->next_state.CYCLE_COUNT = 0;
    cpu->next_state.INSTRUCTION_COUNT = 0;

    cpu->current_state = cpu->next_state;
    cpu->CB_mode = 0;
    cpu->interrupts_enabled = 0;
    cpu->stopped = 0;
    cpu->low_power_mode = 0;
    cpu->dma_flag = 0;
    
    memset(cpu->RAM, 0, sizeof(cpu->RAM));
    cpu->RAM[IF_REGISTER] = 0xE0;
    cpu->RAM[LCDC_REGISTER] = 0x91;
    cpu->RAM[BGP_REGISTER] = 0xFC;
    cpu->RAM[OBP0_REGISTER] = 0xFF;
    cpu->RAM[OBP1_REGISTER] = 0xFF;

    //TODO: remove once inputs are implemented
    cpu->RAM[P1_REGISTER] = 0x0F;
}

/************************************************************/
/*                                                          */
/* Procedure : handle_dma                                   */
/*                                                          */
/* Purpose   : Perform DMA transfer from source address     */ 
/*             specified in the DMA register to OAM         */
/*                                                          */
/************************************************************/
void handle_dma(CPU *cpu) {
    cpu->dma_flag = 0;
    uint16_t src_address = cpu->RAM[DMA_REGISTER] << 8;
    memcpy(&(cpu->RAM[OAM_ADDRESS]), &(cpu->RAM[src_address]), sizeof(uint8_t) * 0x9F);
    cpu->next_state.CYCLE_COUNT = cpu->current_state.CYCLE_COUNT + DMA_CYCLE_DELAY;
}

/************************************************************/
/*                                                          */
/* Procedure : dump_registers                               */
/*                                                          */
/* Purpose   : dump value of each CPU register              */ 
/*                                                          */
/************************************************************/
void dump_registers(CPU *cpu) {
    printf("REGISTER VALUES:\n");
    printf("********************************\n");
    printf("Cycle Count: %d\n", cpu->current_state.CYCLE_COUNT);
    printf("Instruction Count: %d\n", cpu->current_state.INSTRUCTION_COUNT);
    printf("PC: write_mex%04X\n", cpu->current_state.PC);
    printf("SP: 0x%04X\n", cpu->current_state.SP);
    printf("A: 0x%02X\t", cpu->current_state.A);
    printf("F: 0x%02X\n", cpu->current_state.F);
    printf("B: 0x%02X\t", cpu->current_state.B);
    printf("C: 0x%02X\n", cpu->current_state.C);
    printf("D: 0x%02X\t", cpu->current_state.D);
    printf("E: 0x%02X\n", cpu->current_state.E);
    printf("H: 0x%02X\t", cpu->current_state.H);
    printf("L: 0x%02X\n", cpu->current_state.L);
    printf("********************************\n");
}

/************************************************************/
/*                                                          */
/* Procedure : load_program                                 */
/*                                                          */
/* Purpose   : Load a program ROM into memory               */ 
/*                                                          */
/************************************************************/
void load_program(FILE *fp, CPU *cpu) {
    uint8_t word;
    uint32_t i = 0;
    
    while (fread(&word, sizeof(uint8_t), 1, fp) != 0) {
        cpu->RAM[i++] = word;
    }

    cpu->current_state.PC = 0x100;
}

/************************************************************/
/*                                                          */
/* Procedure : fetch                                        */
/*                                                          */
/* Purpose   : If interrupts enabled, service any pending   */
/*             interrupts, then fetch a single              */
/*             instruction from memory                      */
/*                                                          */
/************************************************************/
uint8_t fetch(CPU *cpu) {
    if (cpu->interrupts_enabled == 1) {
        service_interrupts(cpu);
    }
    return read_memory(cpu, cpu->current_state.PC);
}

/************************************************************/
/*                                                          */
/* Procedure : decode                                       */
/*                                                          */
/* Purpose   : decode instruction arguments                 */
/*                                                          */
/************************************************************/
void decode(CPU *cpu, uint8_t opcode, uint16_t *dest, uint16_t *src, Instruction *instruction) {
    if (cpu->CB_mode == 1) {
        *instruction = CB_INSTRUCTIONS[opcode];
    } else {
        *instruction = INSTRUCTIONS[opcode];
    }

    if (instruction->opcode == OPCODE_PREFIX_CB && cpu->CB_mode == 0) {
        enable_cb_mode(cpu);
    } else {
        disable_cb_mode(cpu);
    }


    *dest = get_operand(cpu, instruction->destination, instruction->destination_type);
    *src = get_operand(cpu, instruction->source, instruction->source_type);

#ifdef DEBUG
    if (instruction->source_type == IMMEDIATE_MEM || 
        instruction->source_type == IMMEDIATE_MEM_INDIRECT) {
            instruction->source == D8 ?
                printf(instruction->mnemonic, (uint8_t) *src) :
                printf(instruction->mnemonic, *src);
    } else if (instruction->destination_type == IMMEDIATE_MEM ||
        instruction->destination_type == IMMEDIATE_MEM_INDIRECT) {
            instruction->destination == D8 ?
                printf(instruction->mnemonic, (uint8_t) *dest) :
                printf(instruction->mnemonic, *dest);
    } else {
        printf(instruction->mnemonic);
    }
    printf("\n");
#endif

    /* decode indirect source operands here, indirect destination operands in execute stage */
    if (instruction->source_type == REGISTER_INDIRECT ||
        instruction->source_type == IMMEDIATE_MEM_INDIRECT) {
            *src = read_memory(cpu, *src);
    }
}

/************************************************************/
/*                                                          */
/* Procedure : execute                                      */
/*                                                          */
/* Purpose   : execute a single instruction                 */
/*                                                          */
/************************************************************/
void execute(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    if (check_condition(cpu, instruction->condition) == 0) {
        if (instruction->operation == RET) {
            cpu->next_state.CYCLE_COUNT += JUMP_DELAY;
        }
        cpu->next_state.PC = cpu->current_state.PC + instruction->bytes;
        return;
    }

    switch (instruction->operation_type) {
        case LD_ST_MOV:
            handle_ld_st_mov_operation(cpu, instruction, dest, src);
            break;
        case ALU:
            handle_alu_operation(cpu, instruction, dest, src);
            break;
        case SHIFTER:
            handle_shift_operation(cpu, instruction, dest, src);
            break;
        case BITWISE:
            handle_bitwise_operation(cpu, instruction, dest, src);
            break;
        case JUMP:
            handle_jump_operation(cpu, instruction, dest, src);
            break;
        case MISC:
            handle_misc_operation(cpu, instruction, dest, src);
            break;
        default:
            break;
    }
    cpu->next_state.CYCLE_COUNT += instruction->unaccounted_cycles;  // add any cycles that weren't covered by memory R/W
}

/************************************************************/
/*                                                          */
/* Procedure : step                                         */
/*                                                          */
/* Purpose   : execute a single instruction, return opcode  */
/*                                                          */
/************************************************************/
void step_cpu(CPU *cpu) {
    uint8_t running = !cpu->stopped & !cpu->low_power_mode;
    if (running) {
        if (cpu->dma_flag) {
            handle_dma(cpu);
        }
        uint16_t dest, src;
        Instruction instruction;
        uint8_t opcode = fetch(cpu);
        decode(cpu, opcode, &dest, &src, &instruction);
        execute(cpu, &instruction, dest, src);
    }
    cpu->next_state.INSTRUCTION_COUNT = cpu->current_state.INSTRUCTION_COUNT + 1;
    cpu->current_state = cpu->next_state;
}

/************************************************************/
/*                                                          */
/* Procedure : step_n                                       */
/*                                                          */
/* Purpose   : execute n instructions                       */
/*                                                          */
/************************************************************/
void step_cpu_n(uint32_t n, CPU *cpu) {
    while (n > 0) {
        step_cpu(cpu);
        n--;
    }
}

/************************************************************/
/*                                                          */
/* Procedure : run                                          */
/*                                                          */
/* Purpose   : run the CPU until completion                 */
/*                                                          */
/************************************************************/
void run(CPU *cpu) {
    do {
        step_cpu(cpu);
    } while (cpu->current_state.PC != 0);
}
