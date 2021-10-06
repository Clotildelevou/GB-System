#include "gameboy.h"

gameboy *init_gameboy(void)
{
    gameboy *new_gameboy = malloc(sizeof(gameboy));
    if (new_gameboy == NULL)
    {
        fprintf(stderr, "Couldn't init GameBoy");
        exit(-1);
    }

    new_gameboy->cpu = init_cpu();
    if (new_gameboy->cpu == NULL)
    {
        fprintf(stderr, "Couldn't init CPU\n");
        free_gameboy(new_gameboy);
        exit(-1);
    }

    return new_gameboy;
}

void free_gameboy(gameboy *gameboy)
{
    //Free components
    free_cpu(gameboy->cpu);

    //Free the structure
    free(gameboy);
}

