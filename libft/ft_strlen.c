/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:22:23 by famir             #+#    #+#             */
/*   Updated: 2023/09/19 22:00:10 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	unsigned int	res;
	unsigned int	counter;

	counter = 0;
	res = 0;
	while (s[counter])
	{
		counter++;
		res++;
	}
	return (res);
}
