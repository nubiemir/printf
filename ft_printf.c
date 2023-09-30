/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:49:24 by famir             #+#    #+#             */
/*   Updated: 2023/09/30 14:54:41 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_parser(t_format *format, const char *str, int counter)
{
	unsigned int	start;
	int				width;

	start = counter;
	while (!format_checker(str[start]))
		start++;
	width = ft_atoi((str + counter));
	format->width = width;
	return (start);
}

int	handle_format(t_format *format, const char *str, int counter)
{
	while (!format_checker(str[counter]))
	{
		if (flag_checker(str[counter]))
			format->flag = str[counter++];
		else if (str[counter] >= '1' && str[counter] <= '9')
			counter = width_parser(format, str, counter);
		else
			break ;
	}
	format->type = str[counter++];
	return (counter);
}

int	handle_print(t_format *format, int res, va_list args)
{
	if (format->type == 'c')
		res += ft_print_char(format, va_arg(args, int));
	else if (format->type == 's')
		res += ft_print_str(format, va_arg(args, char *));
	else if (format->type == 'd' || format->type == 'i')
		res += ft_print_num(format, va_arg(args, int));
	else if (format->type == 'u')
		res += ft_print_un(format, va_arg(args, unsigned int));
	else if (format->type == 'x' || format->type == 'X')
		res += ft_print_hex(format, va_arg(args, unsigned int));
	else if (format->type == 'p')
		res += ft_print_ptr(format, va_arg(args, unsigned long));
	else if (format->type == '%')
		res += ft_putchar_fd(format->type, 1);
	else if (!format_checker(format->type))
		res += ft_putchar_fd(format->type, 1);
	return (res);
}

int	ft_printf(const char *ptr, ...)
{
	va_list			args;
	unsigned int	counter;
	t_format		*format;
	int				res;

	va_start(args, ptr);
	counter = 0;
	res = 0;
	format = (t_format *)malloc(sizeof(t_format));
	if (!(format))
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
	safe_free((void **)&format);
	va_end(args);
	return (res);
}
