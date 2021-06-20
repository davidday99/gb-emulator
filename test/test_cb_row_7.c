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

    cpu->current_state.A = 64;
    cpu->next_state.A = 64;
    cpu->current_state.B = 64;
    cpu->next_state.B = 64;
    cpu->current_state.C = 64;
    cpu->next_state.C = 64;
    cpu->current_state.D = 64;
    cpu->next_state.D = 64;
    cpu->current_state.E = 64;
    cpu->next_state.E = 64;
    cpu->current_state.H = 64;
    cpu->next_state.H = 64;
    cpu->current_state.L = 64;
    cpu->next_state.L = 64;

    /* Test for bit[6] == 1 */

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,B
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,C
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,D
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,E
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,H
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,L
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 64;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,(HL)
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,A
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    /* Test for bit[6] == 0 */

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
    step_cpu(cpu); // BIT 6,B
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,C
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,D
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,E
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,H
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,L
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = ~64;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,(HL)
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 6,A
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.A = 128;
    cpu->next_state.A = 128;
    cpu->current_state.B = 128;
    cpu->next_state.B = 128;
    cpu->current_state.C = 128;
    cpu->next_state.C = 128;
    cpu->current_state.D = 128;
    cpu->next_state.D = 128;
    cpu->current_state.E = 128;
    cpu->next_state.E = 128;
    cpu->current_state.H = 128;
    cpu->next_state.H = 128;
    cpu->current_state.L = 128;
    cpu->next_state.L = 128;

    /* Test for bit[7] == 1 */

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,B
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,C
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,D
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,E
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,H
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,L
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = 128;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,(HL)
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,A
    assert(cpu->current_state.F == FLAG_H_MASK);
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    /* Test for bit[7] == 0 */

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
    step_cpu(cpu); // BIT 7,B
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,C
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,D
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,E
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,H
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,L
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    cpu->RAM[cpu->current_state.HL] = ~128;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,(HL)
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 16);
    prev_cycles = cpu->current_state.CYCLE_COUNT;

    cpu->current_state.F = 0;
    cpu->next_state.F = 0;
    step_cpu(cpu); // Enter CB Mode
    step_cpu(cpu); // BIT 7,A
    assert(cpu->current_state.F == (FLAG_Z_MASK | FLAG_H_MASK));
    assert(cpu->current_state.CYCLE_COUNT - prev_cycles == 8);
    prev_cycles = cpu->current_state.CYCLE_COUNT;    
    
    return 0;
}