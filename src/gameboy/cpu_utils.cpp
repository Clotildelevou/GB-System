#include "gameboy.h"

//Set 8bits registers
void set_a(gameboy *gameboy, uint8_t value)
{
    gameboy->cpu->A = value;
}

void set_b(gameboy *gameboy, uint8_t value)
{
    gameboy->cpu->B = value;
}

void set_c(gameboy *gameboy, uint8_t value)
{
    gameboy->cpu->C = value;
}

void set_d(gameboy *gameboy, uint8_t value)
{
    gameboy->cpu->D = value;
}

void set_e(gameboy *gameboy, uint8_t value)
{
    gameboy->cpu->E = value;
}

void set_f(gameboy *gameboy, uint8_t value)
{
    gameboy->cpu->F = value;
}

void set_h(gameboy *gameboy, uint8_t value)
{
    gameboy->cpu->H = value;
}

void set_l(gameboy *gameboy, uint8_t value)
{
    gameboy->cpu->L = value;
}

//Set 16bits registers
void set_af(gameboy *gameboy, uint16_t value)
{
    uint8_t first = value >> 4; //Gets the first half of a uint16_t into a uint8_t
    uint8_t second = value; //Gets the second half of a uint16_t into a uint8_t

    set_a(gameboy, first);
    set_f(gameboy, second);
}

void set_bc(gameboy *gameboy, uint16_t value)
{
    uint8_t first = value >> 4; //Gets the first half of a uint16_t into a uint8_t
    uint8_t second = value; //Gets the second half of a uint16_t into a uint8_t

    set_b(gameboy, first);
    set_c(gameboy, second);
}

void set_de(gameboy *gameboy, uint16_t value)
{
    uint8_t first = value >> 4; //Gets the first half of a uint16_t into a uint8_t
    uint8_t second = value; //Gets the second half of a uint16_t into a uint8_t

    set_d(gameboy, first);
    set_e(gameboy, second);
}

void set_hl(gameboy *gameboy, uint16_t value)
{
    uint8_t first = value >> 4; //Gets the first half of a uint16_t into a uint8_t
    uint8_t second = value; //Gets the second half of a uint16_t into a uint8_t

    set_h(gameboy, first);
    set_l(gameboy, second);
}

//Set flags
void set_flag_z(gameboy *gameboy)
{
    gameboy->cpu->F &= 0x80;
}

void set_flag_n(gameboy *gameboy)
{
    gameboy->cpu->F &= 0x40;
}

void set_flag_h(gameboy *gameboy)
{
    gameboy->cpu->F &= 0x20;
}

void set_flag_c(gameboy *gameboy)
{
    gameboy->cpu->F &= 0x10;
}
