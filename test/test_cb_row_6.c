#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_6(CPU *cpu) {
    printf("Testing CB opcodes row 6.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_cb_ops_row_6.gb", "rb");

    load_program(f, cpu);

    cpu->registers.A = 16;
    cpu->registers.B = 16;
    cpu->registers.C = 16;
    cpu->registers.D = 16;
    cpu->registers.E = 16;
    cpu->registers.H = 16;
    cpu->registers.L = 16;

    /* Test for bit[4] == 1 */

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,B
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,C
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,D
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,E
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,H
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,L
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = 16;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,(HL)
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,A
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    /* Test for bit[4] == 0 */

    cpu->registers.A = ~cpu->registers.A;
    cpu->registers.B = ~cpu->registers.B;
    cpu->registers.C = ~cpu->registers.C;
    cpu->registers.D = ~cpu->registers.D;
    cpu->registers.E = ~cpu->registers.E;
    cpu->registers.H = ~cpu->registers.H;
    cpu->registers.L = ~cpu->registers.L;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,B
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,C
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,D
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,E
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,H
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,L
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = ~16;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,(HL)
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,A
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.A = 32;
    cpu->registers.B = 32;
    cpu->registers.C = 32;
    cpu->registers.D = 32;
    cpu->registers.E = 32;
    cpu->registers.H = 32;
    cpu->registers.L = 32;

    /* Test for bit[5] == 1 */

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,B
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,C
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,D
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,E
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,H
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,L
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = 32;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,(HL)
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,A
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    /* Test for bit[5] == 0 */

    cpu->registers.A = ~cpu->registers.A;
    cpu->registers.B = ~cpu->registers.B;
    cpu->registers.C = ~cpu->registers.C;
    cpu->registers.D = ~cpu->registers.D;
    cpu->registers.E = ~cpu->registers.E;
    cpu->registers.H = ~cpu->registers.H;
    cpu->registers.L = ~cpu->registers.L;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,B
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,C
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,D
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,E
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,H
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,L
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = ~32;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,(HL)
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,A
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;    
    
    return 0;
}