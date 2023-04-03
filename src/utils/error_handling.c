/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:12:47 by mpinna-l          #+#    #+#             */
/*   Updated: 2023/04/03 13:22:06 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *error_str, int return_value)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_str, STDERR_FILENO);
	return (return_value);
}
