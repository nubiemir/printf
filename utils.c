#include "printf.h"

void format_initializer(Format *format)
{
    format->flag = 0;
    format->width = 0;
    format->type = 0;
}

int format_checker(char c)
{
    if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '%')
        return (1);
    return (0);
}

int flag_checker(char c)
{
    if (c == '#' || c == ' ' || c == '+' || c == '0' || c == '.' || c == '-')
        return (1);
    return (0);
}
