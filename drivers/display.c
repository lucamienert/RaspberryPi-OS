#include <drivers/display.h>

void write_char(unsigned char c)
{
    while (in_word(UART0_FR) & (1 << 3)) {}
    out_word(UART0_DR, c);
}

unsigned char read_char()
{
    return in_word(UART0_DR);
}

void write_string(const char *string)
{
    for (int32_t i = 0; string[i] != '\0'; ++i)
        write_char(string[i]);
}

void init_display()
{
    out_word(UART0_CR, 0);
    out_word(UART0_IBRD, 26);
    out_word(UART0_FBRD, 0);
    out_word(UART0_LCRH, (1 << 5) | (1 << 6));
    out_word(UART0_IMSC, (1 << 4));
    out_word(UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));
}