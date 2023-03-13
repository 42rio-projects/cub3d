/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:27:10 by vsergio           #+#    #+#             */
/*   Updated: 2023/03/13 11:12:29 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix == NULL)
		return ;
	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

