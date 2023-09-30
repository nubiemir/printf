/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:00:14 by famir             #+#    #+#             */
/*   Updated: 2023/09/22 22:23:28 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_initializer(t_format *format)
{
	format->flag = 0;
	format->width = 0;
	format->type = 0;
}

int	format_checker(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' 
		|| c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '%')
		return (1);
	return (0);
}

int	flag_checker(char c)
{
	if (c == '#' || c == ' ' || c == '+' || c == '0' || c == '.' || c == '-')
		return (1);
	return (0);
}

void	safe_free(void **ptr)
{
	if (ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}
