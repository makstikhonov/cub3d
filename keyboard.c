/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:24:18 by max               #+#    #+#             */
/*   Updated: 2021/04/26 14:09:51 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	move_forward(t_info *info)
{
	if (info->key == 13 || info->key == 126)
	{
		if (!(info->worldmap[(int)(info->posX + info->dirX
					* info->moveSpeed)][(int)(info->posY)] - '0'))
			info->posX += info->dirX * info->moveSpeed;
		if (!(info->worldmap[(int)(info->posX)][(int)(info->posY
			+ info->dirY * info->moveSpeed)] - '0'))
			info->posY += info->dirY * info->moveSpeed;
	}
}

void	move_backward(t_info *info)
{
	if (info->key == 1 || info->key == 125)
	{
		if (!(info->worldmap[(int)(info->posX - info->dirX
					* info->moveSpeed)][(int)(info->posY)] - '0'))
			info->posX -= info->dirX * info->moveSpeed;
		if (!(info->worldmap[(int)(info->posX)][(int)(info->posY
			- info->dirY * info->moveSpeed)] - '0'))
			info->posY -= info->dirY * info->moveSpeed;
	}
}

void	rotate_right(t_info *info)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = 0;
	oldPlaneX = 0;
	if (info->key == 2 || info->key == 124)
	{
		oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed)
			- info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed)
			+ info->dirY * cos(-info->rotSpeed);
		oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed)
			- info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed)
			+ info->planeY * cos(-info->rotSpeed);
	}
}

void	rotate_left(t_info *info)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = 0;
	oldPlaneX = 0;
	if (info->key == 0 || info->key == 123)
	{
		oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed)
			- info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed)
			+ info->dirY * cos(info->rotSpeed);
		oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed)
			- info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed)
			+ info->planeY * cos(info->rotSpeed);
	}
}	

int	key_pressed(int key, t_info *info)
{
	mlx_clear_window(info->mlx, info->win);
	info->key = key;
	move_forward(info);
	move_backward(info);
	rotate_right(info);
	rotate_left(info);
	if (info->key == 53)
		quit(info);
	main_loop(info);
	return (1);
}
