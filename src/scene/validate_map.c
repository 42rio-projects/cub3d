/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:37:01 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/13 12:55:07 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_map(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (ft_strchr("1 \n", map[0][i]) == NULL)
			return (print_error("Error\nInvalid map\n", 1));
		i++;
	}
	map++;
	while (map[1])
	{
		if (ft_strchr("1 ", map[0][0]) == NULL)
			return (print_error("Error\nInvalid map\n", 1));
		i = 1;
		while (map[0][i])
		{
			if (ft_strchr("1 \n", map[0][i]) == NULL)
			{
				if (ft_strchr(" ", map[0][i - 1]) || ft_strchr(" \n\0", map[0][i + 1]))
					return (print_error("Error\nInvalid map1\n", 1));
				if (ft_strlen(map[-1]) < (size_t)i || ft_strlen(map[1]) < (size_t)i)
					return (print_error("Error\nInvalid map2\n", 1));
				else if (ft_strchr(" \n", map[-1][i]) || ft_strchr(" \n", map[1][i]))
					return (print_error("Error\nInvalid map3\n", 1));
			}
			i++;
		}
		map++;
	}
	while (map[0][i])
	{
		if (ft_strchr("1 \n", map[0][i]) == NULL)
			return (print_error("Error\nInvalid map\n", 1));
		i++;
	}
	return (0);
}
