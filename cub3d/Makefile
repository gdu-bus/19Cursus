# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:37:24 by lorenuar          #+#    #+#              #
#    Updated: 2020/10/23 14:39:21 by lorenuar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #
SHELL = bash

ifndef $(DEBUG)
	DEBUG=0
endif

OS :=	$(shell uname -s)

NAME	= cub3d
CC 		= gcc

ifeq ($(OS), Linux)
	MLX		= ./lib/mlx_linux/libmlx.a
	LIBMLX	= -lmlx
	MLXFL	= $(dir $(MLX))

	LDFLAGS = -L $(MLXFL) $(LIBMLX)
	LDFLAGS += -lXext -lX11 -lm
else
	MLX		= ./lib/mlx_mms/libmlx.dylib
	LIBMLX	= -lmlx
	MLXFL	= $(dir $(MLX))

	LDFLAGS = -L $(MLXFL) $(LIBMLX)
	LDFLAGS += -framework OpenGL -framework AppKit -lz
endif

ifeq ($(DEBUG),1)
	CFLAGS	+= -g3 -D DEBUG=1 -fsanitize=address
else
	CFLAGS 	= -Wall -Wextra -Werror
	CFLAGS	+= -D DEBUG=0
endif

SRCDIR	= src/
INCDIR	= -Iinc/ -I$(MLXFL) -I/usr/include
OBJDIR	= bin/


###▼▼▼<src-updater-do-not-edit-or-remove>▼▼▼
# **************************************************************************** #
# **   Generated with https://github.com/lorenuars19/makefile-src-updater   ** #
# **************************************************************************** #
SRCS = \
	src/parser/check_path.c \
	src/parser/parser.c \
	src/utils/alloc_and_free/free_and_null.c \
	src/utils/error/free_on_error.c \
	src/utils/error/put_error.c \
	src/utils/strings/str_ncmp.c \
	src/utils/strings/printing/put_str_fd.c \
	src/utils/strings/printing/put_chr_fd.c \
	src/utils/strings/get_next_line/hasto.c \
	src/utils/strings/get_next_line/get_next_line.c \
	src/utils/strings/get_next_line/jointo.c \
	src/utils/strings/str_len.c \
	src/utils/numbers/parse_num.c \
	src/cub3d.c \

###▲▲▲<src-updater-do-not-edit-or-remove>▲▲▲

SRC		:= $(notdir $(SRCS))#                               Files only
OBJ		:= $(SRC:.c=.o)#                                    Files only
OBJS	:= $(addprefix $(OBJDIR), $(OBJ))#                  Full path
CSRCS	:= $(addprefix ../, $(SRCS))#                       Compiler

GR	=\033[32;1m#                                            Green
RE	=\033[31;1m#                                            Red
YE	=\033[33;1m#                                            Yellow
CY	=\033[36;1m#                                            Cyan
RC	=\033[0m#                                               Reset Colors

ifndef ($(VERBOSE))
	VERBOSE=0
endif
ifeq ($(VERBOSE), 0)
	QUIET = > /dev/null 2>&1
else
	QUIET = 2>&1
endif
# ================================== RULES =================================== #

all : $(MLX) $(NAME)

run : all
	-./$(NAME)
	-./$(NAME) --save
	-./$(NAME) 78923hr789bn34f

$(MLX) :
ifeq ($(OS), Linux)
	@if [[ ! -d $(MLXFL) ]];then \
	printf "${GR}VVV Downloading minilibx-linux${RC}\n" && mkdir -p ./lib && \
	git clone https://github.com/michaelgiraldo/minilibx-linux.git $(MLXFL) ${QUIET} ;fi
	@printf "$(GR)+++ Compiling mlx $(MLX)$(RC)\n"
	@$(MAKE) -C $(MLXFL) ${QUIET}
else
	@if [[ ! -d $(MLXFL) ]];then\
	printf "${GR}VVV Downloading minilibx-mms${RC}\n" && mkdir -p $(MLXFL) && \
	curl https://projects.intra.42.fr/uploads/document/document/2186/minilibx_mms_20200219_beta.tgz -o ./lib/mlx.tgz && \
	tar -xzf ./lib/mlx.tgz --strip-components=1 -C $(MLXFL) ;fi
	@rm -f ./lib/mlx.tgz
	@printf "$(GR)+++ Compiling mlx $(MLX)$(RC)\n"
	@$(MAKE) -C $(MLXFL) ${QUIET}
	@cp $(MLX) ./$(notdir $(MLX))
endif

mlx_cln :
	@printf "$(RE)--- Removing $(MLXFL)$(RC)\n"
	@$(MAKE) -C $(MLXFL) clean ${QUIET}

mlx_re :
	@printf "$(YE)--- Recreating all files in $(MLXFL)$(RC)\n"
ifeq ($(OS), Linux)
	@$(MAKE) -C $(MLXFL) re ${QUIET}
else
	@$(MAKE) -C $(MLXFL) clean ${QUIET}
endif

#	linking
$(NAME)	: $(OBJS)
	@printf "$(CY)&&& Linking $(OBJ) to $(NAME)$(RC)\n"
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

#	compiling
$(OBJS) : $(SRCS)
	@printf "$(GR)+++ Compiling $(SRC) to $(OBJ)$(RC)\n"
	@mkdir -p $(OBJDIR)
	@$(CC) $(INCDIR) $(CFLAGS) -c $(SRCS)
	@mv $(OBJ) $(OBJDIR)

#	cleaning
clean : mlx_cln
	@printf "$(RE)--- Removing $(OBJ)$(RC)\n"
	@rm -rf $(OBJS) $(OBJDIR)

fclean : clean
	@printf "$(RE)--- Removing $(NAME) AND ./lib Folder$(RC)\n"
	@rm -rf $(NAME) $(OBJDIR)
ifeq ($(OS), Darwin)
	@rm -f $(MLX) $(notdir $(MLX))
endif

rmlib :
	rm -rf ./lib

re : fclean mlx_re all

debug :
	@echo "SRCS $(SRCS)"
	@echo "SRC $(SRC)"
	@echo "OBJS $(OBJS)"
	@echo "OBJ $(OBJ)"
	@echo "CSRCS $(CSRCS)"
	@echo "CFLAGS $(CFLAGS)"
	@echo "MLX $(MLX)"
	@echo "MLXFL $(MLXFL)"
	@echo "LDFLAGS $(LDFLAGS)"

norm :
	zsh -c "setopt extendedglob && ~/.norminette/norminette.rb **/**.[ch]~*lib*"

.PHONY	= all run clean fclean re debug mlx_cln mlx_fcln rmlib norm
