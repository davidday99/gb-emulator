#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../include/sm83.h"

#define RAM_SIZE 0x10000

#define Low16bits(x) ((x) & 0xFFFF)
#define Low8bits(x) ((x) & 0xFF)

uint64_t CYCLE_COUNT;

Registers CURRENT_REGISTERS;
Registers NEXT_REGISTERS;

uint8_t RAM[RAM_SIZE];

/************************************************************/
/*                                                          */
/* Procedure : load_program                                 */
/*                                                          */
/* Purpose   : Load a program ROM into memory               */ 
/*                                                          */
/************************************************************/

void load_program(FILE *fp) {
    memset(RAM, 0, sizeof(RAM));
    uint32_t word;
    uint32_t i = 0;
    
    while (!feof(fp)) {
        fread(&word, sizeof(uint8_t), 1, fp);
        RAM[i++] = Low8bits(word);
    }

    CURRENT_REGISTERS.PC = 0x100;
    
}

/************************************************************/
/*                                                          */
/* Procedure : fetch                                        */
/*                                                          */
/* Purpose   : Fetch a single instruction from memory       */ 
/*                                                          */
/************************************************************/
uint16_t fetch() {
  uint16_t lowByte = RAM[CURRENT_REGISTERS.PC];
  //uint16_t highByte = MEMORY[CURRENT_LATCHES.PC + 1] << 8;

  //return lowByte | highByte;
  return (uint8_t) lowByte;
}

void process_instruction() {
    uint16_t instruction = fetch();
    printf("Instruction: 0x%X\n", instruction);
    NEXT_REGISTERS.PC = CURRENT_REGISTERS.PC + 2;
}

char get_command() {
    char input[20];

    fgets(input, 20, stdin);

    fflush(stdin);

    return input[0];

}

void quit() {
    NEXT_REGISTERS.PC = 0;
}

void run() {
    do {
        printf("> ");

        char command = get_command(); 

        switch (command)
        {
        case 'r':
            process_instruction();
            break;

        case 'q':
            printf("Bye!\n");
            quit();
            break;
        
        default:
            break;
        };

        CURRENT_REGISTERS = NEXT_REGISTERS;
        
    } while (CURRENT_REGISTERS.PC != 0);
}

int main() {
    FILE *f = fopen("../games/tetris.gb", "rb");

    if (f == NULL) {
        printf("Error: could not open file.\n");
        exit(-1);
    }

    load_program(f);

    run();

    fclose(f);

    return 0;
}