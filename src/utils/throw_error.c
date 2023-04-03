/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:12:47 by mpinna-l          #+#    #+#             */
/*   Updated: 2023/04/03 16:44:35 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	throw_error(char *error_str)
{
	ft_putstr_fd("Error\ncub3d: ", STDERR_FILENO);
	ft_putstr_fd(error_str, STDERR_FILENO);
	return (1);
}
