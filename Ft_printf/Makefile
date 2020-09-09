# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 13:02:46 by gdu-bus-          #+#    #+#              #
#    Updated: 2020/03/06 12:55:26 by gdu-bus-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	...
LIBFT_P	=	./libft/

CC			= gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			= rm -f
OBJS		=	$(SRCS:%.c=%.o)
INCL		=	ft_printf.h

all 		: $(NAME)

$(NAME)	: $(OBJS)
				make -C $(LIBFT_P) all
				cp $(LIBFT_P) libft.a $(NAME)
				ar rc $(NAME) $(OBJ) $(INCL)

%.o			:	%.c	$(INCL)
			$(CC)	$(CFLAGS) -c -o $@ $<

clean		:
					make -C $(LIBFT_P) clean
					$(RM) $(OBJS)

fclean	:	clean
				$(RM) $(NAME)
				$(RM) $(LIBFT_P)/libft.a
				
re			:	fclean all
