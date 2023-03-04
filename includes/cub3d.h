/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:11 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/04 17:11:59 by mpinna-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# if defined(__linux__)
#  include "../mlx_linux/mlx.h"
# else
#  include "../mlx/mlx.h"
# endif
// Minilib X funtions

# include "libft/libft.h"
// Set of utility

# include <stdlib.h>
// exit, malloc, free

# include <stdio.h>
// printf

# include <unistd.h>
// write, read, close

# include <fcntl.h>
// open

# include <errno.h>
// strerror, perror

# include <math.h>
// all functions from this lib

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

#define ARG_ERROR "Wrong number of arguments!\nUsage: ./cub3d <map.cub>\n"
#define EXT ".cub"
#define EXT_ERROR "Wrong file extension! It needs to be a .cub\n"

/* _______________________Window___________________________ */

# define WIDTH 700
# define HEIGHT 700

/* ________________________Structs_________________________ */

typedef struct s_data
{
	void	*init;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

/* _______________________Functions_________________________ */

// error handling
int			print_error(char *error_str, int return_value);

// argument checking
int			check_argc(int argc);
int			check_extension(char *filename, char *extension);


void		init_data(t_data *info);
t_data  square_img(int width, int height, int color, void *mlx);
int			key_event(int keycode, t_data *info);
int			close_win(t_data *info);
void		my_mlx_pixel_put(t_data *info, int x, int y, int color);
void		render_background(t_data *info);

#endif
