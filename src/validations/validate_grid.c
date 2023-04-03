/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:21:43 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/03 18:03:16 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_mid_lines(char** grid)
{
	uint32_t	toplen;
	uint32_t	botlen;
	size_t		i;

	// fist x must be 1 or space
	if (ft_strchr("1 ", grid[0][0]) == NULL)
		return (throw_error("Map border must be composed by walls\n"));
	toplen = ft_strlen(grid[-1]);
	botlen = ft_strlen(grid[1]);
	i = -1;
	while(grid[0][++i])
	{
		if (ft_strchr("1 ", grid[0][i]) == NULL) {
			if ((grid[0][i - 1] == ' ' || ft_strchr(" ", grid[0][i + 1])) // check x - 1 and x + 1 are space or \n
			|| (toplen < i || botlen < i) // safe check for y - 1 and y + 1 lines being smaller than the current line (segfault)
			|| (ft_strchr(" ", grid[-1][i]) || ft_strchr(" ", grid[1][i]))) // check y - 1 and y + 1 are space or \n
				return (throw_error("Map border not surrounded by walls\n"));
		}
	}
	return (0);
}

static bool	check_first_last_line(char* line)
{
	size_t	i;

	i = -1;
	while(line[++i])
	{
		if (ft_strchr("1 ", line[i]) == NULL)
			return (throw_error("Map border not surrounded by walls\n"));
	}
	return (0);
}

bool validate_grid(char** grid)
{
	if (check_first_last_line(*grid))
		return (1);
	grid++;
	while ((grid[1])) {
		if (check_mid_lines(grid))
			return (1);
		grid++;
	}
	if (check_first_last_line(*grid))
		return (1);
	return (0);
}
