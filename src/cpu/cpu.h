#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cpu
{
    //REGISTERS OF THE CPU

    // 8 bits registers of the CPU
    uint8_t A;
    uint8_t B;
    uint8_t C;
    uint8_t D;
    uint8_t E;
    uint8_t H;
    uint8_t L;

    // Flag register
    uint8_t F;

    //Stack Pointer and Program Counter (16 bits registers)
    uint16_t SP;
    uint16_t PC;

} cpu;

cpu *init_cpu(void);
void free_cpu(cpu *cpu);

#endif
