/* SM83 CPU Core */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cpu.h"
#include "../include/isa-sm83.h"

#define Low16bits(x) ((x) & 0xFFFF)
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
    if (reg <= L) {
        value = Low8bits(value);
    } 

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
    if (n == 1) {
        cpu->next_state.F |= FLAG_N_MASK;
    } else {
        cpu->next_state.F &= ~FLAG_N_MASK;
    }
}

void set_h_flag(CPU *cpu, uint8_t h) {
    if (h == 1) {
        cpu->next_state.F |= FLAG_H_MASK;
    } else {
        cpu->next_state.F &= ~FLAG_H_MASK;
    }
}

void set_c_flag(CPU *cpu, uint8_t c) {
    if (c == 1) {
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
    cpu->RAM[address] = value;
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
            write_register(cpu, instruction->destination, dest + 1);
            if (instruction->destination <= L || instruction->destination_type == REGISTER_INDIRECT) {
                set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK, dest + 1, 0, detect_half_carry(dest, 1), 0);
            }
            break;
        case DEC:
            write_register(cpu, instruction->destination, dest - 1);
            if (instruction->destination <= L || instruction->destination_type == REGISTER_INDIRECT) {
                set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK, dest - 1, 1, detect_half_carry(dest, -1), 0);
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
    uint16_t temp = 0;
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
            temp = src & 0x80;
            src <<= 1;
            break;
        case SRA:
            temp = src & 0x80;
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 1);
            src >>= 1;
            src |= temp;
            break;
        case SRL:
            set_flags(cpu, FLAG_C_MASK, 0, 0, 0, src & 1);
            src >>= 1;
            break;
        default:
            break;
    }
    instruction->destination_type == REGISTER ?
        write_register(cpu, instruction->destination, src) :
        write_memory(cpu, src, dest);
    cpu->next_state.PC = cpu->current_state.PC + instruction->bytes;
}

void handle_bitwise_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    uint8_t bit_mask = 1 << instruction->destination;
    uint16_t temp1, temp2;

    switch (instruction->operation) {
        case BIT:
            //set Z flag if bit == 0
            temp1 = 1 << dest;
            temp2 = src & temp1;
            set_flags(cpu, FLAG_Z_MASK | FLAG_N_MASK | FLAG_H_MASK, temp2, 0, 1, 0);
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
    cpu->next_state.PC = cpu->current_state.PC + instruction->bytes;
}

void handle_jump_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    uint16_t temp;
    switch (instruction->operation) {
        case CALL:
            write_memory(cpu, (cpu->current_state.PC + instruction->bytes && 0xFF00) >> 8, cpu->current_state.SP - 1);
            write_memory(cpu, (cpu->current_state.PC + instruction->bytes && 0xFF), cpu->current_state.SP - 2);
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
    cpu->next_state.CYCLE_COUNT += JUMP_DELAY;
}

void handle_misc_operation(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    switch (instruction->operation) {
        case CCF:
            break;
        case CPL:
            write_register(cpu, instruction->destination, ~dest);
            break;
        case DAA:
            if ((cpu->current_state.F & FLAG_N_MASK) == 0) {
                if (cpu->current_state.F & FLAG_C_MASK) {
                    write_register(cpu, instruction->destination, dest + 0x60);
                    set_flags(cpu, FLAG_C_MASK, 0, 0, 0, 1);
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
/* CPU FUNCTIONS                                            */
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
    cpu->CB_mode == 1;
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
    cpu->CB_mode == 0;
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
    cpu->enable_interrupts == 1;
}

/************************************************************/
/*                                                          */
/* Procedure : disable_interrupts                           */
/*                                                          */
/* Purpose   : Disable CPU interrupts                       */
/*                                                          */
/************************************************************/

void disable_interrupts(CPU *cpu) {
    cpu->enable_interrupts == 0;
}

/************************************************************/
/*                                                          */
/* Procedure : start CPU                                    */
/*                                                          */
/* Purpose   : Allow CPU to operate normally                */
/*                                                          */
/************************************************************/
void start_cpu(CPU *cpu) {
    cpu->running = 1;
}

/************************************************************/
/*                                                          */
/* Procedure : stop_cpu                                     */
/*                                                          */
/* Purpose   : Halt CPU operation                           */
/*                                                          */
/************************************************************/
void stop_cpu(CPU *cpu) {
    cpu->running = 0;
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
void halt_cpu(CPU *cpu) {
    stop_cpu(cpu);
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
    cpu->next_state.BC = 0;
    cpu->next_state.DE = 0;
    cpu->next_state.HL = 0;
    cpu->next_state.PC = 0;
    cpu->next_state.SP = 0;
    cpu->next_state.CYCLE_COUNT = 0;

    cpu->current_state = cpu->next_state;
    cpu->CB_mode = 0;
    cpu->running = 1;
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
    printf("PC: 0x%04X\n", cpu->current_state.PC);
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
    memset(cpu->RAM, 0, sizeof(cpu->RAM));
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
/* Purpose   : Fetch a single instruction from memory       */
/*                                                          */
/************************************************************/
uint8_t fetch(CPU *cpu) {
    return read_memory(cpu, cpu->current_state.PC);
}

/************************************************************/
/*                                                          */
/* Procedure : decode                                       */
/*                                                          */
/* Purpose   : get potential immediate for instruction      */
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
            printf(instruction->mnemonic, *src);
    } else if (instruction->destination_type == IMMEDIATE_MEM ||
        instruction->destination_type == IMMEDIATE_MEM_INDIRECT) {
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

void execute(CPU *cpu, Instruction *instruction, uint16_t dest, uint16_t src) {
    if (check_condition(cpu, instruction->condition) == 0) {
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

void simulate_cycles(CPU *cpu) {
    uint8_t cycles = cpu->next_state.CYCLE_COUNT - cpu->current_state.CYCLE_COUNT;

    while (cycles > 0) {
        cycles--; // add code to simulate real CPU speed
    }
}

/************************************************************/
/*                                                          */
/* Procedure : step                                         */
/*                                                          */
/* Purpose   : execute a single instruction, return opcode  */
/*                                                          */
/************************************************************/
uint8_t step(CPU *cpu) {
    if (cpu->running) {
        uint16_t dest, src;
        Instruction instruction;
        uint8_t opcode = fetch(cpu);
        decode(cpu, opcode, &dest, &src, &instruction);
        execute(cpu, &instruction, dest, src);
        simulate_cycles(cpu);
        cpu->current_state = cpu->next_state;
        return instruction.opcode;
    } else {
        return OPCODE_NOP;
    }
    
}

/************************************************************/
/*                                                          */
/* Procedure : step_n                                       */
/*                                                          */
/* Purpose   : execute n instructions                       */
/*                                                          */
/************************************************************/
void step_n(uint32_t n, CPU *cpu) {
    while (n > 0) {
        step(cpu);
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
        step(cpu);
    } while (cpu->current_state.PC != 0);
}
