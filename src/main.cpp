#include <stdio.h>

#include "gameboy/gameboy.h"

int main(void)
{
    gameboy *new_gb = init_gameboy();
    printf("It works !");
    free_gameboy(new_gb);
}
