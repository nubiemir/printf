/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_un.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:03:28 by famir             #+#    #+#             */
/*   Updated: 2023/09/21 19:43:59 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_un(t_format *format, unsigned int num)
{
	int				res;

	res = 0;
	res += ft_print_num(format, num);
	return (res);
}
