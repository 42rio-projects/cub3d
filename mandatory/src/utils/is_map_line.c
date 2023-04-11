/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:30:57 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/10 19:22:29 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_line(const char *line)
{
	while (*line && ft_strchr(" 012FNSWE", *line))
		line++;
	if (*line == '\0' || *line == '\n')
		return (true);
	return (false);
}
