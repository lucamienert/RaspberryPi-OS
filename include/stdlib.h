#ifndef RASPOS_STDLIB_H_
#define RASPOS_STDLIB_H_

#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void memcpy(void *source, void *dest, size_t nbytes);
void memset(void *dst, uint8_t value, size_t nbytes);

#ifdef __cplusplus
}
#endif

#endif