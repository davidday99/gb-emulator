#include "../include/input.h"
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

void init_input(Input input, CPU *cpu) {
    input.p1 = &cpu->RAM[P1_REGISTER];
}

void set_input(Input *input, uint8_t value) {
    *input->p1 = value;
}

void set_input_select(Input *input) {
    set_input(input, SELECT);
}