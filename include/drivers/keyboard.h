#ifndef RASPOS_KEYBOARD_H_
#define RASPOS_KEYBOARD_H_

#pragma once

#include <stdint.h>

#define KEYBOARD_BUFFER 50

struct Keyboard
{
    char buffer[KEYBOARD_BUFFER];
    int32_t fron;
    int32_t end;
    int32_t size;
};

char read_key_buffer();
void keyboard_handler();

#endif