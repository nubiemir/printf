/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:25:07 by famir             #+#    #+#             */
/*   Updated: 2023/09/30 20:21:59 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_handle_minus(char *str, t_format *format)
{
	int	res;

	res = 0;
	res += ft_putstr_fd(str, 1);
	while (res < format->width)
		res += ft_putchar_fd(' ', 1);
	return (res);
}

int	ft_handle_zero_space(char *str, t_format *format)
{
	int	res;

	res = 0;
	while ((res + ft_strlen(str)) <= format->width - 1)
		res += ft_putchar_fd(' ', 1);
	res += ft_putstr_fd(str, 1);
	return (res);
}

int	ft_print_str(t_format *format, char *str)
{
	int	res;

	res = 0;
	if (!str)
		str = "(null)";
	if (format->flag == '-' && format->width > ft_strlen(str))
	{
		res += ft_handle_minus(str, format);
	}
	else if ((format->flag == 0 || format->flag == ' ') 
		&& format-> width > ft_strlen(str))
	{
		res += ft_handle_zero_space(str, format);
	}
	else if (format->flag == '.' && format->width < ft_strlen(str))
	{
		while (res < format->width)
			res += ft_putchar_fd(str[res], 1);
	}
	else
		res += ft_putstr_fd(str, 1);
	return (res);
}
