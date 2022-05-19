#ifndef RASPOS_HANDLER_H_
#define RASPOS_HANDLER_H_

#pragma once

#include <stdint.h>

typedef struct TrapFrame 
{
    int64_t x0;
    int64_t x1;
    int64_t x2;
    int64_t x3;
    int64_t x4;
    int64_t x5;
    int64_t x6;
    int64_t x7;
    int64_t x8;
    int64_t x9;
    int64_t x10;
    int64_t x11;
    int64_t x12;
    int64_t x13;
    int64_t x14;
    int64_t x15;
    int64_t x16;
    int64_t x17;
    int64_t x18;
    int64_t x19;
    int64_t x20;
    int64_t x21;
    int64_t x22;
    int64_t x23;
    int64_t x24;
    int64_t x25;
    int64_t x26;
    int64_t x27;
    int64_t x28;
    int64_t x29;
    int64_t x30;
    int64_t sp0;
    int64_t trapno;
    int64_t esr;
    int64_t elr;
    int64_t spsr;
} trapframe_t;

void init_interrupt_controller();
void init_timer();
void enable_irq();
uint64_t get_ticks();

#endif