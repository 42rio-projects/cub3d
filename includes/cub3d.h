/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:11 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/14 17:40:02 by gguedes          ###   ########.fr       */
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

/* _______________________Color Section___________________ */

# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define FUCHSIA 0xFF00FF
# define CYAN 0x00FFFF
# define WHITE 0xFFFFFF

/* ___________________String Defines_______________________ */

# define ARG_ERROR "Wrong number of arguments!\nUsage: ./cub3d <map.cub>\n"
# define EXT_ERROR "Wrong file extension! It needs to be a .cub\n"

/* _______________________Window___________________________ */

# define WIDTH 700
# define HEIGHT 700

/* ________________________Structs_________________________ */

typedef struct s_scene
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor_content;
	char	*ceiling_content;
	int		floor_rgb;
	int		ceiling_rgb;
	char	**map;
}			t_scene;

typedef struct s_data
{
	void	*init;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_scene	scene;
}			t_data;

/* _______________________Functions_________________________ */

// main
void	quit_program(t_data *info);

// mlx functions
void	init_data(t_data *info);
t_data	square_img(int width, int height, int color, void *mlx);
int		key_event(int keycode, t_data *info);
int		close_win(t_data *info);
void	my_mlx_pixel_put(t_data *info, int x, int y, int color);
void	render_background(t_data *info);

// scene functions
void	free_scene(t_scene *scene);
int		is_map_line(char *line);
char	*read_file(int fd);
int		build_scene(t_scene *scene, char *filename);
int		set_info(t_scene *scene, char **raw_content);
int		set_colors(t_scene *scene);
int		set_map(t_scene *scene, char **raw_content);
int		validate_map(char **map);

//utils functions
void	free_matrix(char **matrix);
int		check_argc(int argc);
int		check_extention(char *filename, char *ext);
int		print_error(char *error_str, int return_value);
void	print_scene(t_scene *scene);
void	print_matrix(char **matrix);

#endif
