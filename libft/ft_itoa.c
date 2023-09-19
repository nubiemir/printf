/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:40:36 by famir             #+#    #+#             */
/*   Updated: 2023/09/19 20:29:01 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	digit_counter(long int n)
{
	if (n < 0)
		n = -n;
	if (n < 10)
		return (1);
	return (1 + digit_counter(n / 10));
}

char	*ft_itoa(int n)
{
	char				*res;
	unsigned long int	digit_num;
	long int			num;

	num = n;
	digit_num = digit_counter(num);
	if (num < 0)
	{
		num *= -1;
		digit_num++;
	}
	res = (char *)malloc(digit_num + 1 * sizeof(char));
	if (!res)
		return (0);
	*(res + digit_num) = '\0';
	while (digit_num--)
	{
		*(res + digit_num) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*(res + 0) = '-';
	return (res);
}
