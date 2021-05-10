/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:28:52 by max               #+#    #+#             */
/*   Updated: 2021/04/25 18:02:41 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	calc_floor(t_info *info)
{
	int	y;
	int	x;

	y = info->w_height / 2 + 1;
	while (y < info->w_height)
	{
		x = 0;
		while (x < info->w_width)
		{
			info->buf[y][x] = info->floor_color;
			info->buf[info->w_height - y - 1][x] = info->ceiling_color;
			x++;
		}
		y++;
	}
}
