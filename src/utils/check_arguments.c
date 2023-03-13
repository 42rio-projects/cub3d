/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:48:05 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/13 18:35:31 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_argc(int argc)
{
	if (argc != 2)
		return (1);
	return (0);
}

int	check_extention(char *filename, char *ext)
{
	char	*ptr;

	if (filename == NULL || ext == NULL)
		return (1);
	ptr = ft_strrchr(filename, '.');
	if (ptr == NULL)
		return (1);
	if (!ft_strncmp(ptr, ext, -1))
		return (0);
	return (1);
}
