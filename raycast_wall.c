/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:28:42 by max               #+#    #+#             */
/*   Updated: 2021/04/25 17:29:23 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	calc_wall_side2(t_info *info, t_wl *wl)
{
	if (wl->rayDirX < 0)
	{
		wl->stepX = -1;
		wl->sideDistX = (info->posX - wl->mapX) * wl->deltaDistX;
	}
	else
	{
		wl->stepX = 1;
		wl->sideDistX = (wl->mapX + 1.0 - info->posX) * wl->deltaDistX;
	}
	if (wl->rayDirY < 0)
	{
		wl->stepY = -1;
		wl->sideDistY = (info->posY - wl->mapY) * wl->deltaDistY;
	}
	else
	{
		wl->stepY = 1;
		wl->sideDistY = (wl->mapY + 1.0 - info->posY) * wl->deltaDistY;
	}
}

void	calc_wall_side(t_info *info, t_wl *wl)
{
	wl->rayDirX = info->dirX + info->planeX * wl->cameraX;
	wl->rayDirY = info->dirY + info->planeY * wl->cameraX;
	wl->mapX = (int)info->posX;
	wl->mapY = (int)info->posY;
	wl->deltaDistX = fabs(1 / wl->rayDirX);
	wl->deltaDistY = fabs(1 / wl->rayDirY);
	calc_wall_side2(info, wl);
	calc_wall_dda(info, wl);
}

void	calc_wall_lineheight(t_info *info, t_wl *wl)
{
	double	wallX;

	wl->lineHeight = (int)(info->w_height / wl->perpWallDist);
	wl->drawStart = -wl->lineHeight / 2 + info->w_height / 2;
	if (wl->drawStart < 0)
		wl->drawStart = 0;
	wl->drawEnd = wl->lineHeight / 2 + info->w_height / 2;
	if (wl->drawEnd >= info->w_height)
		wl->drawEnd = info->w_height - 1;
	wl->texNum = info->worldmap[wl->mapX][wl->mapY] - 1 - '0';
	if (wl->side == 0 || wl->side == 1)
		wallX = info->posY + wl->perpWallDist * wl->rayDirY;
	else
		wallX = info->posX + wl->perpWallDist * wl->rayDirX;
	wallX -= floor((wallX));
	wl->texX = (int)(wallX * (double)info->texWidth);
	if ((wl->side == 0 || wl->side == 1 ) && wl->rayDirX > 0)
		wl->texX = info->texWidth - wl->texX - 1;
	if ((wl->side == 2 || wl->side == 3) && wl->rayDirY < 0)
		wl->texX = info->texWidth - wl->texX - 1;
}

void	calc_wall_texnum(t_info *info, t_wl *wl, int *x)
{
	double	step;
	double	texPos;
	int		y;
	int		color;

	step = 1.0 * info->texWidth / wl->lineHeight;
	texPos = (wl->drawStart - info->w_height / 2 + wl->lineHeight / 2) * step;
	y = wl->drawStart;
	while (y < wl->drawEnd)
	{
		wl->texY = (int)texPos & (info->texHeight - 1);
		texPos += step;
		color = info->texture[wl->texNum]
		[info->texHeight * wl->texY + wl->texX];
		if (wl->side == 0)
			wl->texNum = 0;
		if (wl->side == 1)
			wl->texNum = 1;
		if (wl->side == 2)
			wl->texNum = 2;
		if (wl->side == 3)
			wl->texNum = 3;
		info->buf[y][*x] = color;
		y++;
	}
}

void	calc_wall(t_info *info)
{
	t_wl	wl;
	int		x;

	x = 0;
	while (x < info->w_width)
	{
		wl.cameraX = 2 * x / (double)info->w_width - 1;
		calc_wall_side(info, &wl);
		calc_wall_lineheight(info, &wl);
		calc_wall_texnum(info, &wl, &x);
		info->zBuffer[x] = wl.perpWallDist;
		x++;
	}
}
