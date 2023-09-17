#include <stdarg.h>
#include "printf.h"

int width_parser(Format *format, const char *str, int counter)
{
    unsigned int start;
    int width;

    start = counter;
    while (!format_checker(str[start]))
        start++;
    width = ft_atoi((str + counter));
    format->width = width;
    return (start);
}

int handle_format(Format *format, const char *str, int counter)
{
    while (!format_checker(str[counter]))
    {
        if (flag_checker(str[counter]))
            format->flag = str[counter++];
        if (str[counter] >= '1' && str[counter] <= '9')
            counter = width_parser(format, str, counter);
    }
    format->type = str[counter++];
    printf("\nflag: %c\n width: %d\n type: %c\n", format->flag, format->width, format->type);
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
    if (!(format = (Format *)malloc(sizeof(Format))))
        return (0);
    format_initializer(format);
    while (ptr[counter])
    {
        if (ptr[counter] != '%')
            res += write(1, &ptr[counter++], 1);
        else
            counter += handle_format(format, ptr, counter + 1);
    }
    return (res);
}
