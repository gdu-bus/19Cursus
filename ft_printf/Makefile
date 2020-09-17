# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 16:02:09 by gdu-bus-          #+#    #+#              #
#    Updated: 2020/09/17 16:57:57 by gdu-bus-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRC 		= ft_printf.c	parser_convers.c flag_parser.c convers_c.c convers_d.c \
				convers_p.c	convers_s.c convers_u.c convers_u.c	utils_d.c	utils_u.c	\
				utils_x.c	utils.c \

CC				= gcc
CFLAGS	= -Wall -Wextra -Werror -c
RM			=	rm -f

clean:
		make -C $(LIBFT) clean
		$(RM) $(OBJS)
