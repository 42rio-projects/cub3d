/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:11 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/05 21:30:08 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* __________Includes__________ */

# include "libft.h"
# include "mlx.h"

# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

/* __________Defines__________ */

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define WALL_STRIP_WIDTH 1
# define NUM_RAYS WINDOW_WIDTH / WALL_STRIP_WIDTH
# define MINIMAP_WALL_COLOR 0x000000
# define MINIMAP_FLOOR_COLOR 0xffffff
# define MINIMAP_EMPTY_COLOR 0
# define PLAYER_COLOR 0x0000ff
# define RAY_COLOR 0xff0000
# define MINIMAP_SCALE 6
# define MOVE_SPEED 0.04
# define ROTATION_SPEED 0.04

# ifdef __linux__

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define L_ARROW 65361
# define R_ARROW 65363

# else

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define L_ARROW 65361
# define R_ARROW 65363

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
}				t_texture;

typedef struct s_ray {
	double	wall_hit_x;
	double	wall_hit_y;
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	distance;
	bool		wall_hit_horizontal;
} t_ray;

typedef struct t_player {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int			turnDirection;
	int			walkDirection;
	char		current;
	t_ray		rays[NUM_RAYS];
} 				t_player;

typedef struct s_scene
{
	t_texture	no_texture;
	t_texture	so_texture;
	t_texture	we_texture;
	t_texture	ea_texture;
	long			floor_color;
	long			ceil_color;
	uint32_t	map_width;
	uint32_t	map_height;
	char			**map_grid;
}						t_scene;

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bpp;
	int		size_len;
	int		endian;
}	t_image;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win;
	int				close_game;
	void			*img;
	void			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	t_image 	image;
	t_scene		scene;
	t_player	player;
}	t_data;

/* __________Functions__________ */

// hooks
int		hook(void *param);
int		key_pressed(int keycode, t_data *data);
int		key_released(int keycode, t_data *data);

// init
bool	data_init(t_data *data, char const *file);
bool	elements_init(t_data *data, char **file_content);
void	images_init(t_data *data);
bool	map_init(t_scene *scene, char **file_content);
bool	player_init(t_player *player, t_scene *scene);

//rays
void cast(t_player* player, t_scene *scene, t_ray* ray);
void raycast(t_player *player, t_scene *scene);
void rays_init(t_player* player, t_ray* ray, double camera_x);

// render
void	dda(t_data *data, int x0, int y0, int x1, int y1);
void	draw_background(t_image* image, uint32_t floor_color, uint32_t ceil_color);
void	draw_image(t_image* image, t_data* data);
void	put_pixel(t_image *image, int x, int y, uint32_t color);
void	render_tile(t_image *image, uint32_t x_start, uint32_t y_start, uint32_t color);

// utils
bool	check_extension(char const *file, char const *extension);
void	free_matrix(char **matrix);
void	free_scene(t_scene *scene);
bool	is_map_line(char const *line);
bool is_wall_at(t_scene* scene, int x, int y);
char	*read_file(int fd);
int		throw_error(char *error_str);

// validations
bool	validate_colors(char *colors);
bool	validate_content(char const *file_content);
bool	validate_grid(char **grid);

#endif // CUB3D_H
