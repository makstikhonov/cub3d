/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:28:46 by max               #+#    #+#             */
/*   Updated: 2021/04/26 12:15:10 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	sort_sprites(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_sprts)
	{
		info->sprt[i]->dist = fabs(((info->posX - info->sprt[i]->x)
					* (info->posX - info->sprt[i]->x) + (info->posY
						- info->sprt[i]->y) * (info->posY - info->sprt[i]->x)));
		i++;
	}
	ft_sprites_distance_sort(info->sprt, info->num_sprts);
}

void	sprite_init(t_info *info, t_sp *sp)
{
	sp->spriteScreenX = (int)((info->w_width / 2)
			* (1 + sp->transformX / sp->transformY));
	sp->vMoveScreen = (int)(64 / sp->transformY);
	sp->spriteHeight = (int)fabs((info->w_height / sp->transformY) / 1);
	sp->drawStartY = -sp->spriteHeight / 2
		+ info->w_height / 2 + sp->vMoveScreen;
	if (sp->drawStartY < 0)
		sp->drawStartY = 0;
	sp->drawEndY = sp->spriteHeight / 2 + info->w_height / 2 + sp->vMoveScreen;
	if (sp->drawEndY >= info->w_height)
		sp->drawEndY = info->w_height - 1;
	sp->spriteWidth = (int)fabs((info->w_height / sp->transformY) / 1);
	sp->drawStartX = -sp->spriteWidth / 2 + sp->spriteScreenX;
	if (sp->drawStartX < 0)
		sp->drawStartX = 0;
	sp->drawEndX = sp->spriteWidth / 2 + sp->spriteScreenX;
	if (sp->drawEndX >= info->w_width)
		sp->drawEndX = info->w_width - 1;
}

void	sprite_loop(t_info *info, t_sp *sp, int texY, int texX)
{
	int	y;
	int	d;
	int	color;

	y = 0;
	d = 0;
	color = 0;
	y = sp->drawStartY;
	while (y < sp->drawEndY)
	{
		d = (y - sp->vMoveScreen) * 256 - info->w_height
			* 128 + sp->spriteHeight * 128;
		texY = ((d * info->texHeight) / sp->spriteHeight) / 256;
		color = info->texture[4][info->texWidth * texY + texX];
		if ((color & 0x00FFFFFF) != 0)
			info->buf[y][sp->drawStartX] = color;
		y++;
	}
}

void	sprite_vertical_loop(t_info *info, t_sp *sp)
{
	int	texY;
	int	texX;

	texY = 0;
	texX = 0;
	while (sp->drawStartX < sp->drawEndX)
	{
		texX = (int)((256 * (sp->drawStartX - (-sp->spriteWidth
							/ 2 + sp->spriteScreenX)) * info->texWidth
					/ sp->spriteWidth) / 256);
		if (sp->transformY > 0 && sp->drawStartX > 0
			&& sp->drawStartX < info->w_width && sp->transformY
			< info->zBuffer[sp->drawStartX])
		{	
			sprite_loop(info, sp, texY, texX);
		}
		sp->drawStartX++;
	}
}

void	calc_sprite(t_info *info)
{
	t_sp	sp;
	int		i;
	double	invDet;

	i = 0;
	invDet = 0;
	sort_sprites(info);
	while (i < info->num_sprts)
	{
		invDet = 1.0 / (info->planeX * info->dirY - info->dirX * info->planeY);
		sp.transformX = invDet * (info->dirY
				* (info->sprt[i]->x - info->posX) - info->dirX
				* (info->sprt[i]->y - info->posY));
		sp.transformY = invDet * (-info->planeY
				* (info->sprt[i]->x - info->posX)
				+ info->planeX * (info->sprt[i]->y - info->posY));
		sprite_init(info, &sp);
		sprite_vertical_loop(info, &sp);
		i++;
	}
}
