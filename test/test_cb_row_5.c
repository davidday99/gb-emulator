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

    cpu->current_state.A = 4;
    cpu->next_state.A = 4;
    cpu->current_state.B = 4;
    cpu->next_state.B = 4;
    cpu->current_state.C = 4;
    cpu->next_state.C = 4;
    cpu->current_state.D = 4;
    cpu->next_state.D = 4;
    cpu->current_state.E = 4;
    cpu->next_state.E = 4;
    cpu->current_state.H = 4;
    cpu->next_state.H = 4;
    cpu->current_state.L = 4;
    cpu->next_state.L = 4;

    /* Test for bit[2] == 1 */

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,B
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,C
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,D
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,E
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,H
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,L
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 4;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,(HL)
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,A
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    /* Test for bit[2] == 0 */

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
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,B
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,C
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,D
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,E
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,H
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,L
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = ~4;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,(HL)
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 2,A
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 8;
    cpu->next_state.A = 8;
    cpu->current_state.B = 8;
    cpu->next_state.B = 8;
    cpu->current_state.C = 8;
    cpu->next_state.C = 8;
    cpu->current_state.D = 8;
    cpu->next_state.D = 8;
    cpu->current_state.E = 8;
    cpu->next_state.E = 8;
    cpu->current_state.H = 8;
    cpu->next_state.H = 8;
    cpu->current_state.L = 8;
    cpu->next_state.L = 8;

    /* Test for bit[3] == 1 */

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,B
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,C
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,D
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,E
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,H
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,L
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 8;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,(HL)
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,A
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    /* Test for bit[3] == 0 */

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
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,B
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,C
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,D
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,E
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,H
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,L
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = ~8;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,(HL)
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 3,A
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;    
    
    return 0;
}