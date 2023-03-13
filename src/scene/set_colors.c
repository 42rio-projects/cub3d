/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:15:06 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/13 18:21:26 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	invalid_colors(char *colors)
{
	int	commas;

	commas = 0;
	if (*colors == ',')
		return (1);
	while (*colors)
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

static int	get_rgb_value(char *colors)
{
	unsigned long	to_int;
	int				rgb;

	rgb = 0;
	to_int = ft_atoi(colors);
	if (to_int < 0 || to_int > 255 || to_int == 2147483650)
		return (print_error("Colors must have value between 0 and 255!\n", -1));
	rgb = to_int << 16;
	while (*colors && ft_isdigit(*colors))
		colors++;
	to_int = ft_atoi(++colors);
	if (to_int < 0 || to_int > 255 || to_int == 2147483650)
		return (print_error("Colors must have value between 0 and 255!\n", -1));
	rgb |= to_int << 8;
	while (*colors && ft_isdigit(*colors))
		colors++;
	to_int = ft_atoi(++colors);
	if (to_int < 0 || to_int > 255 || to_int == 2147483650)
		return (print_error("Colors must have value between 0 and 255!\n", -1));
	rgb |= to_int;
	return (rgb);
}

int	set_colors(t_scene *scene)
{
	if (invalid_colors(scene->floor_content)
		|| invalid_colors(scene->ceiling_content))
		return (print_error("Invalid set of colors!\n", 1));
	scene->floor_rgb = get_rgb_value(scene->floor_content);
	scene->ceiling_rgb = get_rgb_value(scene->ceiling_content);
	if (scene->floor_rgb == -1 || scene->ceiling_rgb == -1)
		return (1);
	return (0);
}
