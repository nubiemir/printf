#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <unistd.h>

typedef struct FormatConversion
{
    char    flag;
    char    *width;
    char    type;
} Format;

int ft_printf(const char *ptr, ...);
int format_checker(char c);
int flag_checker(char c);

#endif