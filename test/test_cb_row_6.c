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

    cpu->current_state.A = 16;
    cpu->next_state.A = 16;
    cpu->current_state.B = 16;
    cpu->next_state.B = 16;
    cpu->current_state.C = 16;
    cpu->next_state.C = 16;
    cpu->current_state.D = 16;
    cpu->next_state.D = 16;
    cpu->current_state.E = 16;
    cpu->next_state.E = 16;
    cpu->current_state.H = 16;
    cpu->next_state.H = 16;
    cpu->current_state.L = 16;
    cpu->next_state.L = 16;

    /* Test for bit[4] == 1 */

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,B
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,C
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,D
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,E
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,H
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,L
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 16;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,(HL)
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,A
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    /* Test for bit[4] == 0 */

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
    step_cpu(cpu); // BIT 4,B
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,C
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,D
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,E
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,H
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,L
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = ~16;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,(HL)
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 4,A
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 32;
    cpu->next_state.A = 32;
    cpu->current_state.B = 32;
    cpu->next_state.B = 32;
    cpu->current_state.C = 32;
    cpu->next_state.C = 32;
    cpu->current_state.D = 32;
    cpu->next_state.D = 32;
    cpu->current_state.E = 32;
    cpu->next_state.E = 32;
    cpu->current_state.H = 32;
    cpu->next_state.H = 32;
    cpu->current_state.L = 32;
    cpu->next_state.L = 32;

    /* Test for bit[5] == 1 */

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,B
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,C
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,D
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,E
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,H
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,L
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 32;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,(HL)
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,A
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    /* Test for bit[5] == 0 */

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
    step_cpu(cpu); // BIT 5,B
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,C
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,D
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,E
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,H
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,L
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = ~32;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,(HL)
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 5,A
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;    
    
    return 0;
}