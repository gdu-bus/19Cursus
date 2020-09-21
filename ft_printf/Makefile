# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 13:48:22 by gdu-bus-          #+#    #+#              #
#    Updated: 2020/09/21 13:49:20 by gdu-bus-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

LIBFT_P = libft/

SRC = ft_printf.c parser_convers.c convers_d.c flag_parser.c utils.c utils_d.c \
	  convers_u.c utils_u.c convers_x.c utils_x.c convers_p.c convers_s.c \
	  convers_c.c utils_p.c \


OBJ = $(SRC:.c=.o)
	INCLUDE = ft_printf.h

all : $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT_P) all
		cp $(LIBFT_P)libft.a $(NAME)
		ar rc $(NAME) $(OBJ) ft_printf.h

%.o: %.c $(INCLUDE)
		$(CC) $(CCFLAGS) -c -o $@ $<

clean:
		make -C $(LIBFT_P) clean
		rm -f $(OBJ)

fclean : clean
		rm -rf $(NAME)
		rm -rf $(LIBFT_P)/libft.a

re: fclean all
