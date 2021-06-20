#include <stdint.h>
#include <string.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

#define RUNNING 4
#define CLOCK_SELECT 3
#define DIV_FREQ 16384

const uint32_t FREQS[] = {4096,262144,65536,16384};

typedef struct Timer {
    uint8_t *divider;
    uint8_t *counter;
    uint8_t *modulo;
    uint8_t *control;
    uint8_t *interrupt_flag_register;
    uint8_t overflow;
    uint64_t CYCLE_COUNT;
} Timer;

void init_timer(Timer *timer, CPU *cpu) {
    timer->divider = &cpu->RAM[DIV_REGISTER];
    timer->counter = &cpu->RAM[TIMA_REGISTER];
    timer->modulo = &cpu->RAM[TMA_REGISTER];
    timer->control = &cpu->RAM[TAC_REGISTER];
    timer->interrupt_flag_register = &cpu->RAM[IF_REGISTER];
    timer->overflow = 0;
    timer->CYCLE_COUNT = 0;
}

void increment_timer(Timer *timer) {
    if (*timer->counter == UINT8_MAX) {
        timer->overflow = 1;
    }
    *timer->counter++;
}

void increment_div(Timer *timer) {
    *timer->divider++;
}

void load_timer(Timer *timer) {
    *timer->counter = *timer->modulo;
}

void generate_interrupt(Timer *timer) {
    *timer->interrupt_flag_register |= TIM_OFLOW_MASK;
}

void step_timer(Timer *timer) {
    if ((*timer->control & RUNNING) == 0) {
        return;
    }

    if (timer->overflow) {
        timer->overflow = 0;
        load_timer(timer);
        generate_interrupt(timer);
    } else if ((timer->CYCLE_COUNT % 
                FREQS[*timer->control & CLOCK_SELECT]) == 0) {
        increment_timer(timer);
    }
}