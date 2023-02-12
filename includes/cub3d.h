/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:11 by vsergio           #+#    #+#             */
/*   Updated: 2023/02/12 17:48:12 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//#include "mlx/mlx.h"
// Minilib X funtions

//#include "libft/libft.h"
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

/* _______________________Color Section___________________ */

# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define FUCHSIA 0xFF00FF
# define CYAN 0x00FFFF
# define WHITE 0xFFFFFF

/* ________________________Structs_________________________ */

/* _______________________Functions_________________________ */
int	check_argc(int argc);
#endif
