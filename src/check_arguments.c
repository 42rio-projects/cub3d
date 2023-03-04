/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:05 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/04 17:38:46 by mpinna-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_argc(int argc)
{
	if (argc != 2)
		return (1);
	return (0);
}

int	check_extention(char *filename, char *ext)
{
	if (!filename || !ext || !ft_strrchr(filename, '.'))
		return (0);
	if (!ft_strncmp(ft_strrchr(filename, '.'), ext, ft_strlen(ext) + 1))
		return (1);
	return (0);
}
