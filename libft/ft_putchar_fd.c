#include "libft.h"
#include "printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int res;

	res = 0;
	res = write(fd, &c, 1);
	return (res);
}