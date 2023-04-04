# Variables declarations

NAME		=	cub3d

SRC			=	main.c \
				$(addprefix mlx/, hooks.c mlx_utils.c) \
				$(addprefix scene/, read_file.c) \
				$(addprefix utils/, free_scene.c throw_error.c is_map_line.c check_extension.c free_matrix.c) \
				$(addprefix validations/, validate_grid.c validate_colors.c validate_content.c) \
				$(addprefix init/, map_init.c data_init.c elements_init.c) \

SRCS		=	$(addprefix src/, $(SRC))

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror -g

RM			=	rm -rf

INCLUDES	=	-I./includes

LIBFT		=	./includes/libft/libft.a

# Change MLX to match OS

ifeq ($(shell uname), Linux)
	LIBS	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT)
	MLX_O	=	-I/usr/include -lmlx_Linux -O3
	MLX_DIR	=	mlx_linux
else
	LIBS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBFT)
	MLX_O	=	-Imlx
	MLX_DIR	=	mlx
endif

MLX = ./$(MLX_DIR)/libmlx.a

# Compile Rules

%.o: %.c
			@$(CC) -c $(FLAGS) $(INCLUDES) $(MLX_O) $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)
			@echo "\033[32m 💯 | cub3d created."

$(MLX):
			@make -s -C ./$(MLX_DIR)

$(LIBFT):
			@make -s -C includes/libft
			@make -s -C includes/libft bonus

clean:
			@make -s -C ./includes/libft clean
			@make -s -C ./$(MLX_DIR) clean
			@$(RM) $(NAME).dSYM $(OBJS)
			@echo "\033[33m 🧹  | cub3d cleaned."

fclean:
			@make -s -C ./includes/libft fclean
			@make -s -C ./$(MLX_DIR) clean
			@$(RM) $(NAME).dSYM $(OBJS) $(NAME)
			@$(RM) ./$(BUILD)
			@echo "\033[33m 🌪️  | cub3d all cleaned."

re:			fclean all

.PHONY:		all clean fclean re test
