/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:21:10 by famir             #+#    #+#             */
/*   Updated: 2023/09/30 21:34:58 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_num_zero(t_format *format, char *str, long int num)
{
	int	res;

	res = 0;
	if (num < 0)
	{
		res += ft_putchar_fd('-', 1);
		while (format-> width && ((res + (ft_strlen(str) - 1)) 
				<= format->width - 1))
			res += ft_putchar_fd('0', 1);
		res += ft_putstr_fd(str + 1, 1);
	}
	else
	{
		while ((res + ft_strlen(str)) <= format->width - 1)
			res += ft_putchar_fd('0', 1);
		res += ft_putstr_fd(str, 1);
	}
	return (res);
}

int	ft_print_num_dot(t_format *format, char *str, long int num)
{
	int	res;

	res = 0;
	if (num < 0)
	{
		res += ft_putchar_fd('-', 1);
		while (format-> width && ((res + (ft_strlen(str) - 2)) 
				<= format->width - 1))
			res += ft_putchar_fd('0', 1);
		res += ft_putstr_fd(str + 1, 1);
	}
	else
	{
		while ((res + ft_strlen(str)) <= format->width - 1)
			res += ft_putchar_fd('0', 1);
		res += ft_putstr_fd(str, 1);
	}
	return (res);
}

int	ft_print_num(t_format *format, long int num)
{
	int		res;
	char	*str;

	res = 0;
	str = ft_itoa(num);
	if (num >= 0 && (format->flag == '+' || format -> flag == ' ') 
		&& (format->type == 'd'
			|| format->type == 'i'))
	{
		res += ft_putchar_fd(format->flag, 1);
		res += ft_putstr_fd(str, 1);
	}
	else if (format->flag == '0')
	{
		res += ft_print_num_zero(format, str, num);
	}
	else if (format->flag == '.')
	{
		res += ft_print_num_dot(format, str, num);
	}
	else
		res += ft_print_str(format, str);
	safe_free((void **)&str);
	return (res);
}
