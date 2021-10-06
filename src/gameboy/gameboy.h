#ifndef GAMEBOY_H
#define GAMEBOY_H

#include "cpu/cpu.h"

typedef struct gameboy
{
    cpu *cpu;

} gameboy;

gameboy *init_gameboy(void);
void free_gameboy(gameboy *gameboy);

//Set 8bits registers
void set_a(gameboy *gameboy, uint8_t value);
void set_b(gameboy *gameboy, uint8_t value);
void set_c(gameboy *gameboy, uint8_t value);
void set_d(gameboy *gameboy, uint8_t value);
void set_e(gameboy *gameboy, uint8_t value);
void set_f(gameboy *gameboy, uint8_t value);
void set_h(gameboy *gameboy, uint8_t value);
void set_l(gameboy *gameboy, uint8_t value);

//Set 16bits registers
void set_af(gameboy *gameboy, uint16_t value);
void set_bc(gameboy *gameboy, uint16_t value);
void set_de(gameboy *gameboy, uint16_t value);
void set_hl(gameboy *gameboy, uint16_t value);

//Set flags
void set_flag_z(gameboy *gameboy);
void set_flag_n(gameboy *gameboy);
void set_flag_h(gameboy *gameboy);
void set_flag_c(gameboy *gameboy);




#endif
