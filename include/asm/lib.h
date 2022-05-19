#ifndef RASPOS_PORTS_H_
#define RASPOS_PORTS_H_

#pragma once

#include <stdint.h>

extern void delay(uint64_t value);
extern uint8_t get_el();

#endif