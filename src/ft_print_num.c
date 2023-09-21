/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:21:10 by famir             #+#    #+#             */
/*   Updated: 2023/09/21 19:43:44 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_num(t_format *format, long int num)
{
	int		res;
	char	*str;

	res = 0;
	str = ft_itoa(num);
	if (num >= 0 && format->flag == '+' && (format->type == 'd'
			|| format->type == 'i'))
	{
		res += ft_putchar_fd(format->flag, 1);
		res += ft_putstr_fd(str, 1);
	}
	else if (format->flag == '0' && format->width > ft_strlen(str))
	{
		while ((res + ft_strlen(str)) <= format->width - 1)
			res += ft_putchar_fd(format->flag, 1);
		res += ft_putstr_fd(str, 1);
	}
	else
		res += ft_print_str(format, str);
	return (res);
}
