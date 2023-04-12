# Variables declarations

EXE		=	cub3d
EXE_BONUS		=	cub3d_bonus

SRCS		=	$(addprefix mandatory/src/, main.c \
				$(addprefix hooks/, hook.c key_pressed.c key_released.c) \
				$(addprefix init/, data_init.c elements_init.c image_init.c map_init.c player_init.c) \
				$(addprefix cast/,  raycast.c) \
				$(addprefix render/, draw_ceil_wall_floor.c put_pixel.c set_draw_info.c) \
				$(addprefix utils/, check_extension.c free_matrix.c free_scene.c is_map_line.c is_wall_at.c read_file.c throw_error.c) \
				$(addprefix validations/, validate_colors.c validate_content.c validate_grid.c) \
				)

SRCS_BONUS		=	$(addprefix bonus/src/, main_bonus.c \
				$(addprefix hooks/, hook_bonus.c key_pressed_bonus.c key_released_bonus.c mouse_hook_bonus.c) \
				$(addprefix init/, data_init_bonus.c elements_init_bonus.c image_init_bonus.c map_init_bonus.c player_init_bonus.c sprites_init_bonus.c) \
				$(addprefix cast/,  raycast_bonus.c spritecast_bonus.c) \
				$(addprefix render/, draw_animation_bonus.c draw_ceil_wall_floor_bonus.c draw_image_bonus.c draw_sprite_bonus.c put_pixel_bonus.c render_tile_bonus.c set_draw_info_bonus.c) \
				$(addprefix utils/, check_extension_bonus.c free_matrix_bonus.c free_scene_bonus.c is_map_line_bonus.c is_wall_at_bonus.c read_file_bonus.c throw_error_bonus.c) \
				$(addprefix validations/, validate_colors_bonus.c validate_content_bonus.c validate_grid_bonus.c) \
				)

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

LIBFT_DIR	=	./libft

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

INCLUDE		=	-I./mandatory/include -I$(LIBFT_DIR) -I$(MLX_DIR)

INCLUDE_BONUS		=	-I./bonus/include -I$(LIBFT_DIR) -I$(MLX_DIR)

# Compile Rules

%_bonus.o: %_bonus.c ./bonus/include/cub3d_bonus.h
	@$(CC) $(CFLAGS) $(INCLUDE_BONUS) -c $< -o $@

%.o: %.c ./mandatory/include/cub3d.h
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(EXE)

bonus: $(EXE_BONUS)

$(MLX):
	@make -s -C $(MLX_DIR)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(EXE): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $@
	@echo "\033[32m 💯 | cub3d mandatory created."

$(EXE_BONUS): $(OBJS_BONUS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(INCLUDE_BONUS) $(OBJS_BONUS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $@
	@echo "\033[32m ✨ | cub3d bonus created."

clean:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MLX_DIR) clean
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "\033[33m 🧹  | cub3d cleaned."

fclean:
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(MLX_DIR) clean
	@$(RM) $(OBJS) $(OBJS_BONUS) $(EXE) $(EXE_BONUS)
	@echo "\033[33m 🌪️  | cub3d all cleaned."

re: fclean all

.PHONY:	all clean fclean re bonus
