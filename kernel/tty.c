#include <kernel/tty.h>
#include <drivers/display.h>

static int32_t read_string(char *buffer, int32_t position, const char *string)
{
    int32_t index = 0;

    for (index = 0; string[index] != '\0'; index++)
        buffer[position++] = string[index];

    return index;
}

static int32_t hex_to_string(char *buffer, int32_t position, uint64_t digits)
{
    char digits_buffer[25];
    char digits_map[16] = "0123456789ABCDEF";
    int32_t size = 0;
    
    do 
    {
        digits_buffer[size++] = digits_map[digits % 16];
        digits /= 16;
    } while (digits != 0);

    for (int32_t i = size-1; i >= 0; i--)
        buffer[position++] = digits_buffer[i];

    buffer[position++] = 'H';

    return size + 1;
}

static int32_t udecimal_to_string(char *buffer, int32_t position, uint64_t digits)
{
    char digits_map[10] = "0123456789";
    char digits_buffer[25];
    int32_t size = 0;

    do 
    {
        digits_buffer[size++] = digits_map[digits % 10];
        digits /= 10;
    } while (digits != 0);

    for (int32_t i = size-1; i >= 0; i--)
        buffer[position++] = digits_buffer[i];

    return size;
}

static int32_t decimal_to_string(char *buffer, int32_t position, int64_t digits)
{
    int32_t size = 0;

    if (digits < 0) 
    {
        digits = -digits;
        buffer[position++] = '-';
        size = 1;
    }

    size += udecimal_to_string(buffer, position, (uint64_t)digits);
    return size;
}

static void write_console(const char *buffer, int32_t size)
{
    for (int32_t i = 0; i < size; i++)
        write_char(buffer[i]);
}

int32_t print32_tk(const char *format, ...)
{
    char buffer[1024];
    int32_t buffer_size = 0;
    int32_t integer = 0;
    char *string = 0;
    va_list args;

    va_start(args, format);

    for (int32_t i = 0; format[i] != '\0'; i++) 
    {
        if (format[i] != '%')
            buffer[buffer_size++] = format[i];
        else 
        {
            switch (format[++i]) 
            {
                case 'x':
                    integer = va_arg(args, int64_t);
                    buffer_size += hex_to_string(buffer, buffer_size, (uint64_t)integer);
                    break;

                case 'u':
                    integer = va_arg(args, int64_t);
                    buffer_size += udecimal_to_string(buffer, buffer_size, (uint64_t)integer);
                    break;

                case 'd':
                    integer = va_arg(args, int64_t);
                    buffer_size += decimal_to_string(buffer, buffer_size, integer);
                    break;

                case 's':
                    string = va_arg(args, char*);
                    buffer_size += read_string(buffer, buffer_size, string);
                    break;

                default:
                    buffer[buffer_size++] = '%';
                    i--;
            }
        }
    }

    write_console(buffer, buffer_size);
    va_end(args);

    return buffer_size;
}