# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 19:21:32 by gdu-bus-          #+#    #+#              #
#    Updated: 2019/10/11 20:43:07 by gdu-bus-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libft.a

SRCS	=		ft_atoi.c ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
				ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrch.c \
				ft_calloc.c ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c \
				ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c \

OBJS	=		$(SRCS:.c=.o)
CC		=		gcc
CFLAGS	=		-Wall -Wextra -Werror
RM		=		rm -f
%.o		:		%.c
				$(CC) $(CCFLAGS) -c -o $@ $<

all		:		$(NAME)

$(NAME)	:		$(OBJS) libft.h
				ar rc $(NAME) $(OBJS)

clean	:
				$(RM) $(OBJS)
fclean	:		clean
				$(RM) $(NAME)
re		:		fclean all
