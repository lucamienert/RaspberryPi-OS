#ifndef RASPOS_PANIC_H_
#define RASPOS_PANIC_H_

#pragma once

#define PANIC(msg) panic(msg, __FILE__, __LINE__);

#ifdef __cplusplus
extern "C" {
#endif

extern void panic(const char *message, const char *file, uint32_t line);
extern void panic_assert(const char *file, uint32_t line, const char *desc);

#ifdef __cplusplus
}
#endif

#endif