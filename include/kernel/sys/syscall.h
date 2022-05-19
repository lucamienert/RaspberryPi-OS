#ifndef RASPOS_SYSCALL_H_
#define RASPOS_SYSCALL_H_

#pragma once

#include <stdint.h>

typedef int32_t (*SYSTEMCALL)(int64_t *argptr);
void init_system_call(void);
void system_call(trapframe_t *tf);

#endif