/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:24:22 by max               #+#    #+#             */
/*   Updated: 2021/05/01 12:42:59 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	calc(t_info *info)
{
	calc_floor(info);
	calc_wall(info);
	if (info->num_sprts > 0)
		calc_sprite(info);
}

void	draw(t_info *info, t_img *image)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < info->w_height)
	{
		x = 0;
		while (x < info->w_width)
		{
			image->data[y * info->w_width + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
}

int	main_loop(t_info *info)
{
	t_img	image;

	image.img = mlx_new_image(info->mlx, info->w_width, info->w_height);
	image.data = (int *)mlx_get_data_addr(image.img,
			&image.bpp, &image.size_l, &image.endian);
	calc(info);
	draw(info, &image);
	if (info->save == 1)
	{
		ft_bmp(info, &image);
		mlx_destroy_image(info->mlx, image.img);
		quit(info);
	}
	else
		mlx_put_image_to_window(info->mlx, info->win, image.img, 0, 0);
	mlx_destroy_image(info->mlx, image.img);
	return (0);
}

int	quit(t_info *info)
{
	ft_free(info);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	int	save;

	save = 0;
	if (argc >= 2)
	{	
		if (!file_exists(argv[1]) || !check_map_file_name(argv[1]))
			ft_errors(-2, NULL, 0 );
	}
	if (argc == 3)
	{
		while (is_space(*argv[2]))
			argv[2]++;
		if (ft_strncmp("--save", argv[2], ft_strlen(argv[2])))
			ft_errors(-3, NULL, 0);
		save = 1;
	}
	if (argc > 3 || argc == 1)
		ft_errors(-3, NULL, 0);
	ft_init3(save, argv[1]);
	return (0);
}
