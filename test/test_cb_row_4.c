#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "../include/cpu.h"
#include "../include/isa-sm83.h"

int test_cb_row_4(CPU *cpu) {
    printf("Testing CB opcodes row 4.\n");

    init_cpu(cpu);

    int prev_cycles = 0;

    FILE *f = fopen("games/test/test_cb_ops_row_4.gb", "rb");

    load_program(f, cpu);

    cpu->registers.A = 1;
    cpu->registers.B = 1;
    cpu->registers.C = 1;
    cpu->registers.D = 1;
    cpu->registers.E = 1;
    cpu->registers.H = 1;
    cpu->registers.L = 1;

    /* Test bit[0] == 1 */

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,B
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,C
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,D
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,E
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,H
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,L
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = 1;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,(HL)
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,A
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    /* Test for bit[0] == 0 */

    cpu->registers.A = ~cpu->registers.A;
    cpu->registers.B = ~cpu->registers.B;
    cpu->registers.C = ~cpu->registers.C;
    cpu->registers.D = ~cpu->registers.D;
    cpu->registers.E = ~cpu->registers.E;
    cpu->registers.H = ~cpu->registers.H;
    cpu->registers.L = ~cpu->registers.L;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,B
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,C
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,D
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,E
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,H
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,L
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = ~1;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,(HL)
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 0,A
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.A = 2;
    cpu->registers.B = 2;
    cpu->registers.C = 2;
    cpu->registers.D = 2;
    cpu->registers.E = 2;
    cpu->registers.H = 2;
    cpu->registers.L = 2;

    /* Test for bit[1] == 1 */

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,B
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,C
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,D
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,E
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,H
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,L
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = 2;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,(HL)
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,A
    assert(cpu->registers.F == FLAG_H_MASK);
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    /* Test for bit[1] == 0 */

    cpu->registers.A = ~cpu->registers.A;
    cpu->registers.B = ~cpu->registers.B;
    cpu->registers.C = ~cpu->registers.C;
    cpu->registers.D = ~cpu->registers.D;
    cpu->registers.E = ~cpu->registers.E;
    cpu->registers.H = ~cpu->registers.H;
    cpu->registers.L = ~cpu->registers.L;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,B
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,C
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,D
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,E
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,H
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,L
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    cpu->RAM[cpu->registers.HL] = ~2;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,(HL)
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->CYCLE_COUNT;

    cpu->registers.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 1,A
    assert(cpu->registers.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->CYCLE_COUNT;    
    
    return 0;
}