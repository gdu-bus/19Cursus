# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 19:21:32 by gdu-bus-          #+#    #+#              #
#    Updated: 2019/11/07 18:51:43 by gdu-bus-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_atoi.c ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
				ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c \
				ft_calloc.c ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c \
				ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_split.c ft_itoa.c \

SRCS_B		=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -c
RM			=	rm -f
NORM		=	norminette *.h && norminette *.c 

OBJS		=	$(SRCS:%.c=%.o)

OBJS_B		=	$(SRCS_B:%.c=%.o)

all			:	$(NAME)

$(NAME) 	:	$(OBJS)
				ar rc $(NAME) $(OBJS)

$(OBJS) 	:	$(SRCS)
				$(CC) $(CFLAGS) $(SRCS)

$(OBJS_B) 	:	$(SRCS_B)
				$(CC) $(CFLAGS) $(SRCS_B)

n			:
				$(NORM)

bonus 		:	fclean $(OBJS) $(OBJS_B)
				ar rc $(NAME) $(OBJS) $(OBJS_B)

clean		: 
				$(RM) $(OBJS) $(OBJS_B)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
