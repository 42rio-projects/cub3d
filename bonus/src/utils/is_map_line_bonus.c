/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:30:57 by gguedes           #+#    #+#             */
/*   Updated: 2023/04/11 17:51:22 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	is_map_line(const char *line)
{
	while (*line && ft_strchr(" 012FNSWE", *line))
		line++;
	if (*line == '\0' || *line == '\n')
		return (true);
	return (false);
}
