/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:30:57 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/12 23:38:16 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(char *line)
{
	if (line == NULL || *line == '\n')
		return (0);
	while (*line)
	{
		if (ft_strchr("01NSEW \n", *line) == NULL)
			return (0);
		line++;
	}
	return (1);
}
