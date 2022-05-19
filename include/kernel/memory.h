#ifndef RASPOS_MEMORY_H_
#define RASPOS_MEMORY_H_

#pragma once

#include <stdint.h>
#include <system.h>

typedef struct Page
{
    struct Page *next;
} page_t;

void *kalloc(void);
void kfree(uint64_t v);
void init_memory(void);
bool map_page(uint64_t map, uint64_t v, uint64_t pa, uint64_t attribute);
void switch_vm(uint64_t map);
bool setup_uvm(struct Process *process, char *file_name);
void free_page(uint64_t map, uint64_t vstart);
void free_vm(uint64_t map);
uint64_t read_pgd(void);
bool copy_uvm(uint64_t dst_map, uint64_t src_map, int32_t size);

#endif