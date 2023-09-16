#include <stdarg.h>
#include "printf.h"

int width_parser(char *str, int counter)
{
    return (0);
}

int handle_format(Format *format, char *str, int counter)
{
    while (format_checker(str[counter]))
    {
        if (flag_checker(str[counter]))
            format->flag = str[++counter];
        if (str[counter] >= '1' && str[counter] <= '9')
        {
            flag->width = width_parser(str, counter);
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
