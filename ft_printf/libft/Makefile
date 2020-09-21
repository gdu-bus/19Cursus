# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 13:46:08 by gdu-bus-          #+#    #+#              #
#    Updated: 2020/09/21 13:52:27 by gdu-bus-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRC = ft_strlen.c		ft_check_char.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) libft.h
	ar rc $(NAME) $(OBJ) libft.h

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
