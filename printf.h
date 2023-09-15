#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <unistd.h>

typedef struct FormatConversion
{
    char flag;
    char *width;
    char  type;
} Format;

#define NEW(len) ({                                    \
    Format *format = (Format *)malloc(sizeof(Format));     \
    format->flag = 0;                                   \
    format->str = (int *)malloc(len * sizeof(char **)); \
    format;                                             \
})

int ft_printf(const char *ptr, ...);
#endif