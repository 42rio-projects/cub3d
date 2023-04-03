/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:11 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/03 16:53:07 by vsergio          ###   ########.fr       */
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

typedef struct t_textureure
{
	void	*text;
	int		*addr;
	int		width;
	int		height;
	int		bpp;
	int		size_len;
	int		endian;
}				t_texture;

typedef struct s_scene
{
	t_texture	no_texture;
	t_texture	so_texture;
	t_texture	we_texture;
	t_texture	ea_texture;
	long	floor_color;
	long	ceil_color;
	char			**map;
}						t_scene;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win;
	void		*img;
	void		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_scene	scene;
}					t_data;

/* _______________________Functions_________________________ */

// hook functions
int		key_event(int keycode, t_data *info);
void	my_mlx_pixel_put(t_data *info, int x, int y, int color);

// scene functions
bool	is_map_line(char const* line);
char	*read_file(int fd);
bool	validate_colors(char *colors);
int		set_map(t_scene *scene, char **raw_content);
int		validate_map(char **map);

//init functions
bool	data_init(t_data *data, char const *file);
bool	elements_init(t_data* data, char** file_content);

//utils functions
void	free_matrix(char **matrix);
bool	check_extension(char const* file, char const* extension);
int		throw_error(char *error_str);
void	free_scene(t_scene* scene);

//validate functions
bool validate_content(char const* file_content);

#endif
