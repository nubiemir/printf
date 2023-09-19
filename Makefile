# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: famir <famir@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 19:38:21 by famir             #+#    #+#              #
#    Updated: 2023/09/19 20:33:56 by famir            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	libft/ft_atoi.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_itoa.c src/ft_print_char.c \
					src/ft_print_str.c src/ft_print_num.c src/ft_print_hex.c src/ft_print_percentage.c src/ft_print_ptr.c \
					src/ft_print_un.c ft_printf.c utils.c main.c

OBJS			= $(SRCS:.c=.o)

CC				= cc -g
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= printf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
