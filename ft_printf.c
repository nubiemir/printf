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
        else if (str[counter] >= '1' && str[counter] <= '9')
            counter = width_parser(format, str, counter);
        else
            break;
    }
    format->type = str[counter++];
    return (counter);
}


int handle_print(Format *format, int res, va_list args)
{
    if (format->type == 'c')
        res += ft_putchar_fd(va_arg(args, int), 1);
    if (format->type == 's')
        res += ft_putstr_fd(va_arg(args, char *), 1);
    // if (format->type == 'i' || format->type == 'd')
    //     res += ft_putint_fd(va_arg(args, int), 1);
    // if (format->type == 'x' || format->type == 'X')
    //     res += ft_puthex_fd(va_arg(args, int), 1);
    // if (format->type == 'u')
    //     res += ft_putuint_fd(va_arg(args, int), 1);
    // if (format->type == 'p')
    //     res += ft_putptr_fd(va_arg(args, int), 1);
    if (format->type == '%')
        res += ft_putchar_fd(format->type, 1);
    if (!format_checker(format->type))
        res += ft_putchar_fd(format->type, 1);
    return (res);
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
        {
            counter = handle_format(format, ptr, counter + 1);
            res = handle_print(format, res, args);
            format_initializer(format);
        }
    }
    va_end(args);
    return (res);
}
