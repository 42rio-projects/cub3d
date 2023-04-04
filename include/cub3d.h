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

/* __________Includes__________ */

# include "libft.h"
# include "mlx.h"

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

/* __________Defines__________ */

# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 700

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

/* __________Functions__________ */

// hooks
int		hook(void *param);
int		key_pressed(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);

// init
bool	data_init(t_data *data, char const *file);
bool	elements_init(t_data *data, char **file_content);
bool	map_init(t_scene *scene, char **file_content);
bool	player_init(t_player *player, t_scene *scene);

// render
void	put_pixel(t_data *data, int x, int y, uint32_t color);

// utils
bool	check_extension(char const *file, char const *extension);
void	free_matrix(char **matrix);
void	free_scene(t_scene *scene);
bool	is_map_line(char const *line);
char	*read_file(int fd);
int		throw_error(char *error_str);

// validations
bool	validate_colors(char *colors);
bool	validate_content(char const *file_content);
bool	validate_grid(char **grid);

#endif
