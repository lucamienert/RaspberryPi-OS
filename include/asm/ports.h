#ifndef RASPOS_PORTS_H_
#define RASPOS_PORTS_H_

#pragma once

#include <stdint.h>

extern void out_word(uint64_t addr, uint32_t value);
extern uint32_t in_word(uint64_t addr);

#endif