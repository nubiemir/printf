#ifndef LIBFT_H
# define LIBFT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct FormatConversion
{
    char flag;
    int width;
    char type;
} Format;

int	    ft_atoi(const char *str);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);

#endif