/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famir <famir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:06:20 by famir             #+#    #+#             */
/*   Updated: 2023/09/20 21:29:23 by famir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *ptr, ...);
int		format_checker(char c);
int		flag_checker(char c);
void	format_initializer(t_format *format);
int		handle_print(t_format *format, int res, va_list args);
int		ft_print_char(t_format *format, char c);
int		ft_print_str(t_format *format, char *str);
int		ft_print_num(t_format *format, long int num);
int		ft_print_un(t_format *format, unsigned int num);

#endif
