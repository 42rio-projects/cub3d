# Variables declarations

NAME		=	cub3d

SRCS		=	$(addprefix src/, main.c \
				$(addprefix hooks/, hook.c key_pressed.c key_released.c) \
				$(addprefix init/, data_init.c elements_init.c image_init.c map_init.c player_init.c) \
				$(addprefix rays/, cast.c raycast.c) \
				$(addprefix render/, render_line.c draw_image.c put_pixel.c render_tile.c) \
				$(addprefix utils/, check_extension.c free_matrix.c free_scene.c is_map_line.c is_wall_at.c read_file.c throw_error.c) \
				$(addprefix validations/, validate_colors.c validate_content.c validate_grid.c) \
				)

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror -g

RM			=	rm -rf

LIBFT_DIR	=	./include/libft

LIBFT		=	$(LIBFT_DIR)/libft.a

LIBFT_FLAGS	=	-L$(LIBFT_DIR) -lft

# Change MLX to match OS

ifeq ($(shell uname), Linux)
	MLX_DIR		=	./mlx_linux
	MLX_FLAGS	=	-L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
else
	MLX_DIR		=	./mlx
	MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

MLX			=	$(MLX_DIR)/libmlx.a

INCLUDE		=	-I./include -I$(LIBFT_DIR) -I$(MLX_DIR)

# Compile Rules

%.o: %.c ./include/cub3d.h
	@$(CC) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(INCLUDE) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "\033[32m 💯 | cub3d created."

$(MLX):
	@make -s -C $(MLX_DIR)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(LIBFT_DIR) bonus

clean:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MLX_DIR) clean
	@$(RM) $(NAME).dSYM $(OBJS)
	@echo "\033[33m 🧹  | cub3d cleaned."

fclean:
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(MLX_DIR) clean
	@$(RM) $(NAME).dSYM $(OBJS) $(NAME)
	@echo "\033[33m 🌪️  | cub3d all cleaned."

re: fclean all

.PHONY:	all clean fclean re test
