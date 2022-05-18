#ifndef RASPOS_SYSTEM_H_
#define RASPOS_SYSTEM_H_

#pragma once

#include <stdint.h>

#define KERNEL_BASE 0xffff000000000000
#define P2V(p) ((uint64_t)(p) + KERNEL_BASE)
#define V2P(v) ((uint64_t)(v) - KERNEL_BASE)

#define MEMORY_END  P2V(0x30000000)
#define PAGE_SIZE   (2*1024*1024)

#define PA_UP(v)    ((((uint64_t)v + PAGE_SIZE - 1) >> 21) << 21)
#define PA_DOWN(v)  (((uint64_t)v >> 21) << 21)

#define PDE_ADDR(p) ((uint64_t)p & 0xfffffffff000)
#define PTE_ADDR(p) ((uint64_t)p & 0xffffffe00000)

#define ENTRY_V         (1 << 0)
#define TABLE_ENTRY     (1 << 1)
#define BLOCK_ENTRY     (0 << 1)
#define ENTRY_ACCESSED  (1 << 10)
#define NORMAL_MEMORY   (1 << 2)
#define DEVICE_MEMORY   (0 << 2)
#define USER            (1 << 6)

#endif