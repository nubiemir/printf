#include "printf.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>



int format_checker(char c)
{
    if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '%')
        return (1); 
    return (0);
}


int flag_checker(char c)
{
    if (c == '#' || c == ' ' || c == '+' || c == '0' || c == '.' || c == '-')
        return (1);
    return (0);
}


int width_parser(Format *format, const char *str, int counter)
{
    unsigned int    start;
    char            *sub;
    int             width;

    start = counter;
    while (!format_checker(str[counter++]))
    sub = ft_substr(str, start, (size_t)counter);
    width = ft_atoi(sub);
    format->width = width;
    return (counter);
}

int handle_format(Format *format, const char *str, int counter)
{
    while (!format_checker(str[counter]))
    {
        if (flag_checker(str[counter]))
        {
            format->flag = str[++counter];
            counter++;
        }
        if (str[counter] >= '1' && str[counter] <= '9')
            counter+= width_parser(format,str, counter);
    }
    format->type = str[counter];
    printf("\nflag: %c\n width: %d\n type: %c\n", format->flag, format->width, format->type);
    return (counter);
}


int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' 
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

unsigned int	ft_strlen(const char *s)
{
	unsigned int	res;
	unsigned int	counter;

	counter = 0;
	res = 0;
	while (s[counter])
	{
		counter++;
		res++;
	}
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char			*res;
	unsigned int	len;
	unsigned int	counter;

	len = ft_strlen(s1);
	res = (char *)malloc(len + 1);
	counter = 0;
	if (res != NULL)
	{
		while (counter < len)
		{
			res[counter] = s1[counter];
			counter++;
		}
		res[counter] = '\0';
	}
	return (res);
}



char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	counter;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	counter = 0;
	if (len > ft_strlen(s))
		substring = (char *)malloc((ft_strlen(s) - start) + 1);
	else
		substring = (char *)malloc(len + 1);
	if (substring != NULL)
	{
		while (s[start] && counter < len)
			substring[counter++] = s[start++]; 
		substring[counter] = '\0';
	}
	return (substring);
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
            res += write(1, &ptr[counter++], 1);
        else
            counter += handle_format(format, ptr, counter+1);
    }
    return (res);
}

int main()
{
    // printf("%+012d", 12);
    ft_printf("Hello World%.2ss");
}


