/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:54:50 by famir             #+#    #+#             */
/*   Updated: 2023/09/19 20:05:50 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct FormatConversion
{
	char	flag;
	int		width;
	char	type;
}	t_format;

int		ft_atoi(const char *str);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);

#endif
