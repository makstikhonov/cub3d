/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:24:29 by max               #+#    #+#             */
/*   Updated: 2021/05/01 21:41:02 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	ft_free_tempmap(t_info *info)
{
	int	i;

	i = 0;
	while (info->tempmap[i])
	{
		free(info->tempmap[i]);
		i++;
	}
	free(info->tempmap);
}

void	ft_check_map_is_enclosed(t_info *info, int x, int y)
{	
	if (x > info->end - 1)
		ft_errors(-6, info, 0);
	else if (x < 0 || y < 0 || info->tempmap[x][y] == ' '
		|| y > (int)ft_strlen(info->tempmap[x]) - 1)
		ft_errors(-6, info, 0);
	if (info->tempmap[x][y] == '1' || info->tempmap[x][y] == '.')
		return ;
	info->tempmap[x][y] = '.';
	ft_check_map_is_enclosed(info, x + 1, y);
	ft_check_map_is_enclosed(info, x - 1, y);
	ft_check_map_is_enclosed(info, x, y + 1);
	ft_check_map_is_enclosed(info, x, y - 1);
	ft_check_map_is_enclosed(info, x - 1, y - 1);
	ft_check_map_is_enclosed(info, x + 1, y + 1);
	ft_check_map_is_enclosed(info, x - 1, y + 1);
	ft_check_map_is_enclosed(info, x + 1, y - 1);
}

void	ft_set_parameters(t_info *info, double dirX, double dirY, double planeY)
{
	info->dirX = dirX;
	info->dirY = dirY;
	info->planeY = planeY;
}

void	ft_if_news(t_info *info, char c, int *i, int *j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (info->posX == -2.0 || info->posY == -2.0)
		{
			info->posX = (double)*i + 0.5;
			info->posY = (double)*j + 0.5;
			info->worldmap[*i][*j] = '0';
		}
		else
			ft_errors(-8, NULL, 0);
		if (c == 'S')
			ft_set_parameters(info, 1, 0, -1);
		else if (c == 'N')
			ft_set_parameters(info, -1, 0, 1);
		else if (c == 'W')
		{
			ft_set_parameters(info, 0, -1, 0);
			info->planeX = -0.66;
		}
		else if (c == 'E')
		{
			ft_set_parameters(info, 0, 1, 0);
			info->planeX = 0.66;
		}
	}
}

int	ft_init_map(t_info *info)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (info->worldmap[i])
	{
		j = 0;
		while (info->worldmap[i][j] != '\0')
		{
			c = info->worldmap[i][j];
			if (!is_map_character(c) && c != ' ')
				ft_errors(-6, NULL, 0);
			ft_if_news(info, c, &i, &j);
			j++;
		}
		i++;
	}
	if (info->posX <= 0.0 || info->posY <= 0.0)
		ft_errors(-12, NULL, 0);
	info->end = i;
	return (1);
}
