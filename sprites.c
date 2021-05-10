/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:24:51 by max               #+#    #+#             */
/*   Updated: 2021/04/26 12:07:21 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	ft_count_sprites(t_info *info)
{
	int			x;
	int			y;

	y = -1;
	while (info->worldmap[++y])
	{
		x = -1;
		while (info->worldmap[y][++x])
		{
			if (info->worldmap[y][x] == '2')
				info->num_sprts++;
		}
	}
	return (info->num_sprts);
}

t_sprite	*ft_init_cycle(t_info *info, int *x, int *y)
{
	t_sprite	*item;

	item = (t_sprite *)malloc(sizeof(t_sprite));
	if (!item)
		ft_errors(-1, NULL, 0);
	item->x = *y + 0.5;
	item->y = *x + 0.5;
	info->worldmap[*y][*x] = '0';
	return (item);
}

t_sprite	**ft_init_sprites(t_info *info)
{
	int			x;
	int			y;
	t_sprite	**items;
	int			i;

	i = 0;
	items = (t_sprite **)malloc(sizeof(t_sprite *) * (info->num_sprts));
	if (!items)
		ft_errors(-1, NULL, 0);
	y = -1;
	while (info->worldmap[++y])
	{
		x = -1;
		while (info->worldmap[y][++x])
		{
			if (info->worldmap[y][x] == '2')
			{
				items[i] = ft_init_cycle(info, &x, &y);
				i++;
			}
		}
	}
	return (items);
}

void	ft_sprites_distance_sort(t_sprite **sprites, int length)
{
	t_sprite	*tmp;
	int			i;

	i = -1;
	while (--length)
	{
		i = 0;
		while (i < length)
		{
			if (sprites[i]->dist < sprites[i + 1]->dist)
			{
				tmp = sprites[i];
				sprites[i] = sprites[i + 1];
				sprites[i + 1] = tmp;
			}
			i++;
		}
	}
}
