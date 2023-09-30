/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:04:00 by famir             #+#    #+#             */
/*   Updated: 2023/09/30 21:55:15 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	count_hex_digits(unsigned long nbr)
{
	int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr)
	{
		count++;
		nbr /= 16;
	}
	return (count);
}

int	put_hex(t_format *format, unsigned long nbr, int count)
{
	int		remainder;
	char	digit;

	if (nbr == 0)
		return (count);
	remainder = nbr % 16;
	if (remainder < 10)
		digit = '0' + remainder;
	else
	{
		if (format->type == 'X')
			digit = 'A' + (remainder - 10);
		else
			digit = 'a' + (remainder - 10);
	}
	return (put_hex(format, nbr / 16, count) + ft_putchar_fd(digit, 1));
}

int	ft_handle_hashtag(t_format *format, unsigned long num)
{
	int	res;

	res = 0;
	res += ft_putchar_fd('0', 1);
	res += ft_putchar_fd(format->type, 1);
	res += put_hex(format, num, 0);
	return (res);
}

int	ft_handle_flag(t_format *format, int hex_count)
{
	int	res;

	res = 0;
	while ((res + hex_count) <= format->width - 1)
		res += ft_putchar_fd('0', 1);
	return (res);
}

int	ft_print_hex(t_format *format, unsigned long num)
{
	int	res;
	int	hex_count;

	hex_count = count_hex_digits(num);
	res = 0;
	if (num == 0)
		res += ft_putchar_fd('0', 1);
	else if (format->flag == '#' && format->width == 0)
		res += ft_handle_hashtag(format, num);
	else if ((format->flag == '0' || format->flag == '.') 
		&& format->width > hex_count)
	{
		res += ft_handle_flag(format, hex_count);
		res += put_hex(format, num, 0);
	}
	else if (format->flag == '-' && format->width > hex_count)
	{
		res += put_hex(format, num, 0);
		while (res < format->width)
			res += ft_putchar_fd(' ', 1);
	}
	else
		res += put_hex(format, num, 0);
	return (res);
}
