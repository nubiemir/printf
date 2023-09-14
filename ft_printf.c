#include <stdarg.h>
#include "printf.h"

int flag_checker(char c)
{
    if (c == '#' || c == ' ' || c == '+' || c == '0' || c == '.' || c == '-')
        return (1);
    return (0);
}

int format_checker(char c)
{
    if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '%')
        return (1);
    return (0);
}

char *handle_width()
{
    return ("hello");
}

Stack *handle_flag(char c, char *str)
{
    Stack *stack;
    int len;

    if (c == '0' || '.' || '-')
        len = 3;
    else
        len = 2;
    stack = NEW(len);
    return (stack);
}

int ft_printf(const char *ptr, ...)
{
    va_list args;
    va_start(args, ptr);
    unsigned int counter;
    int res;

    counter = 0;
    res = 0;
    while (ptr[counter])
    {
        if (ptr[counter] != '%')
            res += write(1, &ptr[counter], 1);
        else
        {
            write(1, "\n", 1);
            if (flag_checker(ptr[++counter]))
            {
                Stack *stack = handle_flag(ptr[counter], &ptr[counter]);
            }
            else if (format_checker(ptr[counter]))
                printf("format found %c\n", ptr[counter]);
        }
        counter++;
    }
    return (res);
}