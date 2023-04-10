/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:11 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/10 14:13:40 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* __________Includes__________ */

# include "../libft/libft.h"
# include "mlx.h"

# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

/* __________Defines__________ */

# define WINDOW_WIDTH 854
# define WINDOW_HEIGHT 480
# define MINIMAP_WALL_COLOR 0x000000
# define MINIMAP_FLOOR_COLOR 0xffffff
# define MINIMAP_EMPTY_COLOR 0
# define PLAYER_COLOR 0x0000ff
# define RAY_COLOR 0xff0000
# define MINIMAP_SCALE 6
# define MOVE_SPEED 0.02
# define ROTATION_SPEED 0.02
# define NUM_SPRITES 3

# ifdef __linux__

#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define L_ARROW 65361
#  define R_ARROW 65363

# else

#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define L_ARROW 123
#  define R_ARROW 124

# endif // __linux__

/* __________Structs__________ */

typedef struct s_texture
{
	void	*text;
	int		*addr;
	int		width;
	int		height;
	int		bpp;
	int		size_len;
	int		endian;
}	t_texture;

typedef struct s_sprite
{
	double		x;
	double		y;
	int			order;
	double		distance;
	double		camera_x;
	double		camera_y;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			draw_start_y;
	int			draw_end_y;
	int			draw_start_x;
	int			draw_end_x;
	double		inv_det;
	int			height;
	int			width;
	int			texture_x;
	uint32_t	frames;
	t_texture	textures;
}	t_sprite;

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bpp;
	int		size_len;
	int		endian;
}	t_image;

typedef struct s_draw_info
{
	uint32_t	line_height;
	uint32_t	wall_start;
	uint32_t	wall_end;
	int			texture_x;
	double		wall_x;
	double		texture_pos;
	double		step;
	t_texture	*texture;
}	t_draw_info;

typedef struct s_scene
{
	t_texture	no_texture;
	t_texture	so_texture;
	t_texture	we_texture;
	t_texture	ea_texture;
	long		ceil_color;
	long		floor_color;
	uint32_t	map_width;
	uint32_t	map_height;
	char		**map_grid;
}	t_scene;

typedef struct s_ray
{
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	double	dir_x;
	double	dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	char	hit_direction;
}	t_ray;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		turn_direction;
	int		walk_direction;
}	t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win;
	t_image		image;
	t_scene		scene;
	t_player	player;
	t_sprite	sprites[NUM_SPRITES];
	double		wall_distances[WINDOW_WIDTH];
}	t_data;

/* __________Functions__________ */

// hooks
int		hook(void *param);
int		key_pressed(int keycode, t_data *data);
int		key_released(int keycode, t_data *data);

// init
bool	data_init(t_data *data, const char *file);
bool	elements_init(t_data *data, char **file_content);
void	image_init(t_data *data);
bool	map_init(t_scene *scene, char **file_content);
bool	player_init(t_player *player, t_scene *scene);
void	sprites_init(t_data *data);

//cast
void	raycast(t_player *player, t_scene *scene, t_ray *ray);
void	spritecast(t_sprite *sprite, t_player *player);

// render
void	draw_ceil_wall_floor(t_data *data, t_player *player, t_scene *scene);
void	draw_image(t_data *data);
void	draw_sprite(t_data *data, t_sprite *sprites);
void	put_pixel(t_image *image, int x, int y, uint32_t color);
void	render_tile(t_image *image,
			uint32_t x_start, uint32_t y_start, uint32_t color);
void	set_draw_info(t_data *data, t_player *player,
			t_ray *ray, t_draw_info *info);

// utils
bool	check_extension(const char *file, const char *extension);
void	free_matrix(char **matrix);
void	free_scene(t_scene *scene);
bool	is_map_line(const char *line);
bool	is_wall_at(t_scene *scene, int x, int y);
char	*read_file(int fd);
int		throw_error(char *error_str);
bool	load_texture(t_data *data, t_texture *texture,
			char *path, char *error_str);

// validations
bool	validate_colors(char *colors);
bool	validate_content(const char *file_content);
bool	validate_grid(char **grid);

#endif // CUB3D_H
