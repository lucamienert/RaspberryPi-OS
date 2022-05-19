#ifndef RASPOS_TTY_H_
#define RASPOS_TTY_H_

#pragma once

#include <stdarg.h>

int print_tty(const char *format, ...);
void write_console(const char *buffer, int size);

#endif