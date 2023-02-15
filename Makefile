# Variables declarations

NAME = cub3D

BUILD = unitTests/build

FLAGS = -Wall -Wextra -Werror -g

CC = cc

SRC = cub3d.c check_arguments.c

SRCS = $(addprefix src/, $(SRC))

RM = rm -rf

INCLUDES = -I./includes

# Change MLX to match OS

ifeq ($(shell uname), Linux)
LIBS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz includes/libft/libft.a
MLX_O	= -I/usr/include -lmlx_Linux -O3
MLX_DIR	= mlx_linux
else
LIBS	= -Lmlx -lmlx -framework OpenGL -framework AppKit includes/libft/libft.a
MLX_O	= -Imlx
MLX_DIR		= mlx
endif

MLX = ./mlx/libmlx.a

LIBFT = ./libft/libft.a

$(MLX):
			make -C ./${MLX_DIR}

$(LIBFT):
			make -C includes/libft

# Compile Rules

all:		$(NAME)

$(NAME):	$(SRCS) $(LIBFT) $(MLX)
			$(CC) $(FLAGS) $(SRCS) $(LIBS) $(INCLUDES) -o $(NAME)
			@echo "\033[32m 💯 | cub3d created."

${BUILD}:
			cd unitTests && cmake -S . -B build

test: ${BUILD}
			cd unitTests && cmake --build build
			cd unitTests/build && ctest --output-on-failure

clean:
			@make -C ./includes/libft clean
			@${RM} ${NAME}.dSYM $(OBJS)
			@echo "\033[33m 🧹  | cub3d cleaned."

fclean: 	clean
			@make -C ./includes/libft fclean
			@$(RM) $(NAME)
			@echo "\033[33m 🌪️  | cub3d all cleaned."

re:			fclean all

.PHONY:		all clean fclean re test
