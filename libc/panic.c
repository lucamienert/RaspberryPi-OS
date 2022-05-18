#include <panic.h>

extern void panic(const char *message, const char *file, uint32_t line)
{
    printf("[PANIC]: Exiting...");
}

extern void panic_assert(const char *file, uint32_t line, const char *desc)
{
    printf("[ASSERTION FAILURE]: Exiting...");
}