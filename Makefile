# Variables declarations

NAME = cub3D

BUILD = unitTests/build

FLAGS = -Wall -Wextra -Werror -g

CC = cc

SRC = check_arguments.c create_image.c  cub3d.c hooks.c  mlx_utils.c error_handling.c
SRCS = $(addprefix src/, $(SRC))

OBJS = $(SRCS:.c=.o)

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

MLX = ./$(MLX_DIR)/libmlx.a

LIBFT = ./includes/libft/libft.a

# Compile Rules 

%.o: %.c
			@${CC} -c ${FLAGS} ${INCLUDES} ${MLX_O} $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX)	
			$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)
			@echo "\033[32m 💯 | cub3d created."

$(MLX):
			make -C ./${MLX_DIR}

$(LIBFT):
			make -C includes/libft

${BUILD}:
			cd unitTests && cmake -S . -B build

test: ${BUILD}
			cd unitTests && cmake --build build
			cd unitTests/build && ctest --output-on-failure

clean:
			@make -C ./includes/libft clean
			@make -C ./$(MLX_DIR) clean
			@${RM} ${NAME}.dSYM $(OBJS)
			@echo "\033[33m 🧹  | cub3d cleaned."

fclean: 	clean
			@make -C ./includes/libft fclean
			@$(RM) $(NAME)
			@$(RM) ./$(BUILD)
			@echo "\033[33m 🌪️  | cub3d all cleaned."

re:			fclean all

.PHONY:		all clean fclean re test
