/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:21:10 by famir             #+#    #+#             */
/*   Updated: 2023/09/20 20:38:22 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_print_num(t_format *format, int num)
{
	int		res;
	char	*str;

	res = 0;
	str = ft_itoa(num);
	if (num >= 0 && format->flag == '+')
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
