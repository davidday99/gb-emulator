#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_7(CPU *cpu) {
    printf("Testing CB opcodes row 7.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_cb_ops_row_7.gb", "rb");

    load_program(f, cpu);

    cpu->registers.A = 64;
    cpu->registers.B = 64;
    cpu->registers.C = 64;
    cpu->registers.D = 64;
    cpu->registers.E = 64;
    cpu->registers.H = 64;
    cpu->registers.L = 64;

    /* Test for bit[6] == 1 */

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,B
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,C
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,D
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,E
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,H
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,L
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = 64;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,(HL)
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,A
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    /* Test for bit[6] == 0 */

    cpu->registers.A = ~cpu->registers.A;
    cpu->registers.B = ~cpu->registers.B;
    cpu->registers.C = ~cpu->registers.C;
    cpu->registers.D = ~cpu->registers.D;
    cpu->registers.E = ~cpu->registers.E;
    cpu->registers.H = ~cpu->registers.H;
    cpu->registers.L = ~cpu->registers.L;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,B
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,C
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,D
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,E
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,H
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,L
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = ~64;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,(HL)
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,A
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.A = 128;
    cpu->registers.B = 128;
    cpu->registers.C = 128;
    cpu->registers.D = 128;
    cpu->registers.E = 128;
    cpu->registers.H = 128;
    cpu->registers.L = 128;

    /* Test for bit[7] == 1 */

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,B
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,C
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,D
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,E
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,H
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,L
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = 128;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,(HL)
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,A
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    /* Test for bit[7] == 0 */

    cpu->registers.A = ~cpu->registers.A;
    cpu->registers.B = ~cpu->registers.B;
    cpu->registers.C = ~cpu->registers.C;
    cpu->registers.D = ~cpu->registers.D;
    cpu->registers.E = ~cpu->registers.E;
    cpu->registers.H = ~cpu->registers.H;
    cpu->registers.L = ~cpu->registers.L;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,B
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,C
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,D
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,E
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,H
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,L
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = (uint8_t) ~128;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,(HL)
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,A
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;    
    
    return 0;
}