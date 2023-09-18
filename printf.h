#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"




int ft_printf(const char *ptr, ...);
int format_checker(char c);
int flag_checker(char c);
void format_initializer(Format *format);
int handle_print(Format *format, int res, va_list args);

#endif