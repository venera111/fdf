# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 11:29:44 by qestefan          #+#    #+#              #
#    Updated: 2021/12/09 19:07:16 by qestefan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS := $(shell uname)
adds =
FLAGS = -Wall -Wextra -Werror

ifeq ($(OS), Linux)
	MINILIBX_DIR = minilibx/minilbx_linux
	LIB_MLX = ./minilibx/minilbx_linux
	OPENGL = -lm -lbsd -lX11 -lXext
	MLX_A = libmlx_Linux.a
	FLAGS += -D LINUX=1
	adds = sudo apt-get install gcc make xorg libxext-dev libbsd-dev
endif

ifeq ($(OS), Darwin)
	MINILIBX_DIR = minilibx/minilibx_macos
	LIB_MLX = ./minilibx/minilibx_macos
	OPENGL = -lz -framework OpenGL -framework AppKit
	MLX_A = libmlx.a
	FLAGS += -D DARWIN=1
endif

NAME_PROJECT = fdf
LIB_DIR = ./libft/
LIB_NAME =	libft/libft.a
LIB_HEADER = libft
MINILIBX_A_DIR = $(MINILIBX_DIR)/$(MLX_A)
LIBFT = libft.a
CC = gcc
HEADER = includes
OBJS = $(SRCS:.c=.o)
DIR = ./source/
SRCS = $(DIR)colors.c $(DIR)draw.c $(DIR)error.c $(DIR)get_next_line.c $(DIR)get_next_line_utils.c $(DIR)hooks.c\
		$(DIR)main.c $(DIR)point.c $(DIR)read_file.c $(DIR)rotation.c $(DIR)utils.c $(DIR)window.c
AR = ar rc

.c.o:
	$(CC) $(FLAGS) -c -I$(HEADER) -I$(LIB_HEADER) $< -o $(<:.c=.o)

all: $(LIBFT) $(MLX_A) $(NAME_PROJECT)

bonus : $(LIBFT) $(MLX_A) $(NAME_PROJECT)
$(MLX_A):
		$(adds)
		make  -C $(LIB_MLX)
		cp $(MINILIBX_A_DIR) $(MLX_A)
$(LIBFT):
		@$(MAKE) -C $(LIB_DIR)
$(NAME_PROJECT): $(OBJS)
		$(CC) $(FLAGS) -I$(HEADER) $(OBJS) -L. $(LIB_NAME) $(MINILIBX_A_DIR) $(OPENGL) -o $(NAME_PROJECT)

clean:
	make clean -C $(LIB_DIR)
	make clean -C $(LIB_MLX)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME_PROJECT)
	rm -rf $(MLX_A)
re: fclean all

norm:
	norminette *.c *.h

.PHONY: all clean fclean re code bonus norm
