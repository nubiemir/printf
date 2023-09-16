#include <stdarg.h>
#include "printf.h"

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

int handle_format(Format *format, char *str, int counter)
{
    while (str[counter] != 'u' && str[counter] != 'i' && str[counter] != 'd' && str[counter] != 'x' && str[counter] != 'X' && str[counter] != 'c' && str[counter] != 's' && str[counter] != 'p' && str[counter] != '%')
    {
        if (str[counter] == '.' || str[counter] == ' ' || str[counter] == '0' || str[counter] == '-' || str[counter] = '#' || str[counter] == '+')
        {
            format->flag = str[counter];
        }
        counter++;
    }
    format->type = str[counter]
    return (counter);
}

int ft_printf(const char *ptr, ...)
{
    va_list args;
    unsigned int counter;
    Format *format;
    int res;

    va_start(args, ptr);
    counter = 0;
    res = 0;
    if(!(format = (Format *)malloc(sizeof(Format))))
        return (0);
    while (ptr[counter])
    {
        if (ptr[counter] != '%')
            res += write(1, &ptr[counter], 1);
        else
            i = handle_format(format, ptr, i+1)
        counter++;
    }
    return (res);
}