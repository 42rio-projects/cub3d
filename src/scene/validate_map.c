/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:02:31 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/03 16:48:00 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_mid_lines(char **map)
{
	int	i;
	int	toplen;
	int	botlen;

	if (ft_strchr("1 ", map[0][0]) == NULL)
		return (throw_error("Map border must be composed by walls\n"));
	i = 1;
	toplen = ft_strlen(map[-1]);
	botlen = ft_strlen(map[1]);
	while (map[0][i])
	{
		if (ft_strchr("1 \n", map[0][i]) == NULL)
		{
			if ((ft_strchr(" ", map[0][i - 1])
				|| ft_strchr(" \n\0", map[0][i + 1]))
				|| (toplen < i || botlen < i)
				|| (ft_strchr(" \n", map[-1][i]) || ft_strchr(" \n", map[1][i])))
				return (throw_error("Map border not surrounded by walls\n"));
		}
		i++;
	}
	return (0);
}

static int	check_first_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("1 \n", line[i]) == NULL)
			return (throw_error("Map border not surrounded by walls\n"));
		i++;
	}
	return (0);
}

int	validate_map(char **map)
{
	if (check_first_last_line(*map))
		return (1);
	map++;
	while (*(map + 1))
	{
		if (check_mid_lines(map))
			return (1);
		map++;
	}
	if (check_first_last_line(*map))
		return (1);
	return (0);
}
