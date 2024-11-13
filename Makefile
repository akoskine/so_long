# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 20:59:29 by akoskine          #+#    #+#              #
#    Updated: 2024/11/13 14:21:45 by akoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c \
utils.c \
map_utils.c \
check_utils.c \
configure_utils.c \
move_utils.c

NAME = so_long
MLX = ./mlx/libmlx.a
LIBFT = ./libft/libft.a
FT_PRINTF = ./libft/ft_printf/libftprintf.a
OPENGL_FLAGS = -framework AppKit -framework OpenGL -L./mlx -lmlx
O_SRC = ${SRC:.c=.o}

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(SRC)
	cc -Wall -Wextra -Werror $(OPENGL_FLAGS) $(LIBFT) $(FT_PRINTF) $(MLX) $(SRC) -o $(NAME)

$(LIBFT) :
	make -C ./libft

$(MLX) :
	make -C ./mlx

clean:
	rm -rf $(O_SRC)
	make clean -C ./libft
	make clean -C ./mlx

fclean:
	rm -rf $(NAME) $(O_SRC)
	make fclean -C ./libft
	make clean -C ./mlx

re: fclean all

.PHONY: all clean fclean re