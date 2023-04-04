/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:11 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/04 17:25:20 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Minilib X funtions
# if defined(__linux__)
#  include "../mlx_linux/mlx.h"
# else
#  include "../mlx/mlx.h"
# endif

//bool
# include <stdbool.h>

// Set of utility
# include "libft/libft.h"

// exit, malloc, free
# include <stdlib.h>

// printf
# include <stdio.h>

// write, read, close
# include <unistd.h>

// open
# include <fcntl.h>

// strerror, perror
# include <errno.h>

// all functions from this lib
# include <math.h>

/* _______________________Window___________________________ */

# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 700
/* ________________________Structs_________________________ */

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
	t_ray		rays;
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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_scene	scene;
	t_player player;
}	t_data;

/* _______________________Functions_________________________ */

// hook functions
int		key_event(int keycode, t_data *info);
void	my_mlx_pixel_put(t_data *info, int x, int y, int color);
// int		key_pressed(int keycode, t_data *data);
// int		key_released(int keycode, t_data *data);

// scene functions
bool	is_map_line(char const *line);
char	*read_file(int fd);

//init functions
bool	data_init(t_data *data, char const *file);
bool  elements_init(t_data *data, char **file_content);
bool	map_init(t_scene *scene, char **file_content);
bool	player_init(t_player *player, t_scene *scene);

//utils functions
void	free_matrix(char **matrix);
bool	check_extension(char const *file, char const *extension);
int		throw_error(char *error_str);
void	free_scene(t_scene *scene);

//validate functions
bool	validate_content(char const *file_content);
bool	validate_grid(char **grid);
bool	validate_colors(char *colors);

#endif
