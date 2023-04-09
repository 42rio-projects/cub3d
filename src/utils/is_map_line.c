/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:30:57 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/08 22:47:34 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_line(const char *line)
{
	while (*line && ft_strchr(" 012NSWE", *line))
		line++;
	if (*line == '\0' || *line == '\n')
		return (true);
	return (false);
}
