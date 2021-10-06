#include "cpu.h"

cpu *init_cpu(void)
{
    cpu *new_cpu = malloc(sizeof(cpu));

    //Init register
    new_cpu->A = 0x0;
    new_cpu->B = 0x0;
    new_cpu->C = 0x0;
    new_cpu->D = 0x0;
    new_cpu->E = 0x0;
    new_cpu->F = 0x0;
    new_cpu->H = 0x0;
    new_cpu->L = 0x0;

    new_cpu->PC = 0x0;
    new_cpu->SP = 0x0;

    return new_cpu;
}
void free_cpu(cpu *cpu)
{
    free(cpu);
}
