/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:25:05 by famir             #+#    #+#             */
/*   Updated: 2023/09/30 14:40:49 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
int	main(void)
{
	int x;
	x = ft_printf("%.0s, %.0s, %.0s, %.0s", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	// ft_printf(" %#X ", 100);
	// printf(" %#X ", 100);
	printf("\n");
	printf("%.0s, %.0s, %.0s, %.0s", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
}