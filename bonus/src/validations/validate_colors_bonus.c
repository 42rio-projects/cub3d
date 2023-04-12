/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:15:06 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/11 17:53:56 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	validate_colors(char *colors)
{
	int	commas;

	commas = 0;
	if (*colors == ',')
		return (1);
	while (*colors && commas < 3)
	{
		if (*colors == ',')
		{
			commas++;
			colors++;
		}
		if (!ft_isdigit(*colors))
			return (1);
		colors++;
	}
	if (commas != 2)
		return (1);
	return (0);
}
