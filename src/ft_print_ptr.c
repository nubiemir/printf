/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:19:00 by famir             #+#    #+#             */
/*   Updated: 2023/09/30 21:34:34 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_ptr(t_format *format, unsigned long num)
{
	int	res;
	int	hex_count;

	hex_count = count_hex_digits(num);
	res = 0;
	res += ft_putstr_fd("0x", 1);
	if (format->flag == '-' && format->width > hex_count)
	{
		if (num == 0)
			res += ft_putchar_fd('0', 1);
		else
			res += put_hex(format, num, 0);
		while (res < format->width)
			res += ft_putchar_fd(' ', 1);
	}
	else if (num == 0)
		res += ft_putchar_fd('0', 1);
	else
		res += put_hex(format, num, 0);
	return (res);
}
