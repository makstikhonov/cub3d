/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:28:20 by max               #+#    #+#             */
/*   Updated: 2021/04/25 17:28:35 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	calc_wall_dda_hit(t_info *info, t_wl *wl, int hit)
{
	while (hit == 0)
	{
		if (wl->sideDistX < wl->sideDistY)
		{
			wl->sideDistX += wl->deltaDistX;
			wl->mapX += wl->stepX;
			if (wl->stepX == 1)
				wl->side = 0;
			else if (wl->stepX == -1)
				wl->side = 1;
		}
		else
		{
			wl->sideDistY += wl->deltaDistY;
			wl->mapY += wl->stepY;
			if (wl->stepY == 1)
				wl->side = 2;
			else if (wl->stepY == -1)
				wl->side = 3;
		}
		if (info->worldmap[wl->mapX][wl->mapY] == '1')
			hit = 1;
	}
}

void	calc_wall_dda(t_info *info, t_wl *wl)
{
	int	hit;

	hit = 0;
	calc_wall_dda_hit(info, wl, hit);
	if (wl->side == 0 || wl->side == 1)
		wl->perpWallDist = (wl->mapX - info->posX
				+ (1 - wl->stepX) / 2) / wl->rayDirX;
	else
		wl->perpWallDist = (wl->mapY - info->posY
				+ (1 - wl->stepY) / 2) / wl->rayDirY;
}
