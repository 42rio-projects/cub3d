/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:11 by vsergio           #+#    #+#             */
/*   Updated: 2023/02/14 23:40:37 by vsergio          ###   ########.fr       */
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

/* _______________________Window___________________ */
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
int			check_argc(int argc);
void		init_data(t_data *info);
int			key_event(int keycode, t_data *info);
int			close_win(t_data *info);

#endif
