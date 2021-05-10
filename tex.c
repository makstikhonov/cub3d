/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:24:54 by max               #+#    #+#             */
/*   Updated: 2021/04/26 13:26:18 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	ft_load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	img->img = mlx_xpm_file_to_image(info->mlx, path,
			&img->img_width, &img->img_height);
	if (!img->img)
		ft_errors(-11, NULL, 0);
	img->data = (int *)mlx_get_data_addr(img->img,
			&img->bpp, &img->size_l, &img->endian);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

int	ft_load_texture(t_info *info)
{
	t_img	img;
	int		i;

	i = 0;
	info->texture = (int **)malloc(sizeof(int *) * 5);
	if (!info->texture)
		ft_errors(-1, NULL, 0);
	while (i < 5)
	{
		info->texture[i] = (int *)malloc(sizeof(int)
				* (info->texHeight * info->texWidth));
		if (!info->texture[i])
			ft_errors(-1, NULL, 0);
		ft_bzero(info->texture[i], info->texHeight * info->texWidth);
		ft_load_image(info, info->texture[i], info->path[i], &img);
		i++;
	}
	return (1);
}
