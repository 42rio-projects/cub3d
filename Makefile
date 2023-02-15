# Variables declarations

NAME = cub3D

BUILD = unitTests/build

FLAGS = -Wall -Wextra -Werror -g

CC = cc

FILES = cub3d.c check_arguments.c hooks.c

SRCS = $(addprefix src/, $(FILES))

RM = rm -rf

INCLUDES = -I ./includes

LIBFT = ./includes/libft/libft.a

# Change MLX to match OS

ifeq ($(shell uname), Linux)
LIBS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz includes/libft/libft.a
MLX_O	= -I/usr/include -lmlx_Linux -O3
MLX_DIR	= mlx_linux
MLX = ./mlx_linux/libmlx.a
else
LIBS	= -Lmlx -lmlx -framework OpenGL -framework AppKit includes/libft/libft.a
MLX_DIR		= mlx
MLX = ./mlx/libmlx.a
endif

# Compile Rules

all:		$(NAME)

$(NAME):	$(SRCS) $(LIBFT) $(MLX)
					$(CC) $(FLAGS) $(SRCS) $(LIBS) $(INCLUDES) -o $(NAME)
					@echo "\033[32m 💯 | cub3d created."

$(LIBFT):
			make -C ./includes/libft

$(MLX):
			make -C ./${MLX_DIR}

${BUILD}:
			cd unitTests && cmake -S . -B build

test: ${BUILD}
			cd unitTests && cmake --build build
			cd unitTests/build && ctest --output-on-failure

clean:
			@make -C ./includes/libft clean
			@make -C ./$(MLX_DIR) clean
			@${RM} ${NAME}.dSYM
			@echo "\033[33m 🧹  | cub3d cleaned."

fclean: 	clean
			@make -C ./includes/libft fclean
			@$(RM) $(NAME)
			@$(RM) unitTests/build/
			@echo "\033[33m 🌪️  | cub3d all cleaned."

re:			fclean all

.PHONY:		all clean fclean re test
