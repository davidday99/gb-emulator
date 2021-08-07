#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_5(CPU *cpu) {
    printf("Testing CB opcodes row 5.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_cb_ops_row_5.gb", "rb");

    load_program(f, cpu);

    cpu->registers.A = 4;
    cpu->registers.B = 4;
    cpu->registers.C = 4;
    cpu->registers.D = 4;
    cpu->registers.E = 4;
    cpu->registers.H = 4;
    cpu->registers.L = 4;

    /* Test for bit[2] == 1 */

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,B
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,C
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,D
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,E
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,H
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,L
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = 4;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,(HL)
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,A
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    /* Test for bit[2] == 0 */

    cpu->registers.A = ~cpu->registers.A;
    cpu->registers.B = ~cpu->registers.B;
    cpu->registers.C = ~cpu->registers.C;
    cpu->registers.D = ~cpu->registers.D;
    cpu->registers.E = ~cpu->registers.E;
    cpu->registers.H = ~cpu->registers.H;
    cpu->registers.L = ~cpu->registers.L;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,B
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,C
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,D
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,E
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,H
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,L
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = ~4;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,(HL)
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,A
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.A = 8;
    cpu->registers.B = 8;
    cpu->registers.C = 8;
    cpu->registers.D = 8;
    cpu->registers.E = 8;
    cpu->registers.H = 8;
    cpu->registers.L = 8;

    /* Test for bit[3] == 1 */

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,B
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,C
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,D
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,E
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,H
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,L
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = 8;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,(HL)
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,A
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    /* Test for bit[3] == 0 */

    cpu->registers.A = ~cpu->registers.A;
    cpu->registers.B = ~cpu->registers.B;
    cpu->registers.C = ~cpu->registers.C;
    cpu->registers.D = ~cpu->registers.D;
    cpu->registers.E = ~cpu->registers.E;
    cpu->registers.H = ~cpu->registers.H;
    cpu->registers.L = ~cpu->registers.L;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,B
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,C
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,D
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,E
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,H
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,L
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = ~8;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,(HL)
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,A
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;    
    
    return 0;
}