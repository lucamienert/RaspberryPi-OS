#ifndef RASPOS_STDIO_H_
#define RASPOS_STDIO_H_

#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

static int udecimal_to_string(char *buffer, int position, uint64_t digits);
static int decimal_to_string(char *buffer, int position, int64_t digits);
static int hex_to_string(char *buffer, int position, uint64_t digits);
static int read_string(char *buffer, int position, const char *string);
int printf(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif