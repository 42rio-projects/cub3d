/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:15:06 by vsergio           #+#    #+#             */
/*   Updated: 2023/04/03 13:30:26 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
