/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:02:48 by famir             #+#    #+#             */
/*   Updated: 2023/09/30 20:12:43 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_char(t_format *format, char c)
{
	int	res;

	res = 0;
	if (format->flag == '-' && format->width > 1)
	{
		res += ft_putchar_fd(c, 1);
		while (res < format->width)
			res += ft_putchar_fd(' ', 1);
	}
	else if (format->flag == 0 && format->width > 1)
	{
		while (res <= format->width - 2)
			res += ft_putchar_fd(' ', 1);
		res += ft_putchar_fd(c, 1);
	}
	else
		res += ft_putchar_fd(c, 1);
	return (res);
}
