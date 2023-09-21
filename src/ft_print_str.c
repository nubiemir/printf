/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:25:07 by famir             #+#    #+#             */
/*   Updated: 2023/09/21 19:43:54 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_str(t_format *format, char *str)
{
	int	res;

	res = 0;
	if (format->flag == '-' && format->width > ft_strlen(str))
	{
		res += ft_putstr_fd(str, 1);
		while (res < format->width)
			res += ft_putchar_fd(' ', 1);
	}
	else if ((format->flag == 0 || format->flag == ' ') 
		&& format-> width > ft_strlen(str))
	{
		while ((res + ft_strlen(str)) <= format->width - 1)
			res += ft_putchar_fd(' ', 1);
		res += ft_putstr_fd(str, 1);
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
