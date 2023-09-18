#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
    int res;

    res = 0;
	while (*s)
	{
		res += ft_putchar_fd(*s, fd);
		s++;
	}
    return (res);
}