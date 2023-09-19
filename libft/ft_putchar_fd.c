/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:48:39 by famir             #+#    #+#             */
/*   Updated: 2023/09/19 19:50:33 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int	res;

	res = 0;
	res = write(fd, &c, 1);
	return (res);
}
