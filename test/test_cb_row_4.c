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

    cpu->current_state.A = 1;
    cpu->next_state.A = 1;
    cpu->current_state.B = 1;
    cpu->next_state.B = 1;
    cpu->current_state.C = 1;
    cpu->next_state.C = 1;
    cpu->current_state.D = 1;
    cpu->next_state.D = 1;
    cpu->current_state.E = 1;
    cpu->next_state.E = 1;
    cpu->current_state.H = 1;
    cpu->next_state.H = 1;
    cpu->current_state.L = 1;
    cpu->next_state.L = 1;

    /* Test bit[0] == 1 */

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,B
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,C
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,D
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,E
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,H
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,L
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 1;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,(HL)
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,A
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    /* Test for bit[0] == 0 */

    cpu->current_state.A = ~cpu->current_state.A;
    cpu->next_state.A = ~cpu->next_state.A;
    cpu->current_state.B = ~cpu->current_state.B;
    cpu->next_state.B = ~cpu->next_state.B;
    cpu->current_state.C = ~cpu->current_state.C;
    cpu->next_state.C = ~cpu->next_state.C;
    cpu->current_state.D = ~cpu->current_state.D;
    cpu->next_state.D = ~cpu->next_state.D;
    cpu->current_state.E = ~cpu->current_state.E;
    cpu->next_state.E = ~cpu->next_state.E;
    cpu->current_state.H = ~cpu->current_state.H;
    cpu->next_state.H = ~cpu->next_state.H;
    cpu->current_state.L = ~cpu->current_state.L;
    cpu->next_state.L = ~cpu->next_state.L;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,B
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,C
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,D
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,E
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,H
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,L
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = ~1;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,(HL)
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 0,A
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 2;
    cpu->next_state.A = 2;
    cpu->current_state.B = 2;
    cpu->next_state.B = 2;
    cpu->current_state.C = 2;
    cpu->next_state.C = 2;
    cpu->current_state.D = 2;
    cpu->next_state.D = 2;
    cpu->current_state.E = 2;
    cpu->next_state.E = 2;
    cpu->current_state.H = 2;
    cpu->next_state.H = 2;
    cpu->current_state.L = 2;
    cpu->next_state.L = 2;

    /* Test for bit[1] == 1 */

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,B
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,C
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,D
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,E
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,H
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,L
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 2;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,(HL)
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,A
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    /* Test for bit[1] == 0 */

    cpu->current_state.A = ~cpu->current_state.A;
    cpu->next_state.A = ~cpu->next_state.A;
    cpu->current_state.B = ~cpu->current_state.B;
    cpu->next_state.B = ~cpu->next_state.B;
    cpu->current_state.C = ~cpu->current_state.C;
    cpu->next_state.C = ~cpu->next_state.C;
    cpu->current_state.D = ~cpu->current_state.D;
    cpu->next_state.D = ~cpu->next_state.D;
    cpu->current_state.E = ~cpu->current_state.E;
    cpu->next_state.E = ~cpu->next_state.E;
    cpu->current_state.H = ~cpu->current_state.H;
    cpu->next_state.H = ~cpu->next_state.H;
    cpu->current_state.L = ~cpu->current_state.L;
    cpu->next_state.L = ~cpu->next_state.L;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,B
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,C
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,D
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,E
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,H
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,L
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = ~2;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,(HL)
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step(cpu); // Enter CB Mode
    step(cpu); // BIT 1,A
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;    
    
    return 0;
}