/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:55:13 by max               #+#    #+#             */
/*   Updated: 2021/05/01 21:38:17 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	ft_errors2(char error)
{
	if (error == -10)
		ft_putstr_fd("Error\ninvalid color", 2);
	if (error == -11)
		ft_putstr_fd("Error\ninvalid texture path", 2);
	if (error == -12)
		ft_putstr_fd("Error\nno player position", 2);
}

void	ft_errors(char error, t_info *info, int free)
{
	if (error == -1)
		ft_putstr_fd("Error\nbad malloc", 2);
	if (error == -2 || error == -9)
		ft_putstr_fd("Error\nno file", 2);
	if (error == -3)
		ft_putstr_fd("Error\ninvalid arguments", 2);
	if (error == -4)
		ft_putstr_fd("Error\nmap is not enclosed", 2);
	if (error == -5)
		ft_putstr_fd("Error\ncant open file", 2);
	if (error == -6)
		ft_putstr_fd("Error\ninvalid config file", 2);
	if (error == -7)
		ft_putstr_fd("Error\ninvalid resolution", 2);
	if (error == -8)
		ft_putstr_fd("Error\nmultiple player position", 2);
	ft_errors2(error);
	if (free == 1 )
		quit(info);
	exit(0);
}
