/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:24:12 by max               #+#    #+#             */
/*   Updated: 2021/05/01 18:33:53 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	ft_init(t_info *info)
{
	int	i;

	info->posX = -2.0;
	info->posY = -2.0;
	info->dirX = 0.0;
	info->dirY = 0.0;
	info->planeX = 0.0;
	info->planeY = 0.66;
	info->num_sprts = 0;
	info->moveSpeed = 0.2;
	info->rotSpeed = 0.1;
	info->texHeight = 64;
	info->texWidth = 64;
	info->num_sprts = 0;
	info->floor_color = -2;
	info->ceiling_color = -2;
	info->w_height = -2;
	info->w_width = -2;
	info->path = (char **)malloc(5 * sizeof(char *));
	if (!info->path)
		ft_errors(-2, NULL, 0);
	i = 0;
	while (i < 5)
		info->path[i++] = NULL;
}

void	ft_init2(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	info->buf = (int **)malloc(sizeof(int *) * info->w_height);
	if (!info->buf)
		ft_errors(-1, NULL, 0);
	while (i < info->w_height)
	{
		info->buf[i] = (int *)malloc(sizeof(int) * info->w_width);
		if (!info->buf[i])
			ft_errors(-1, NULL, 0);
		ft_bzero(info->buf[i], info->w_width);
		i++;
	}
	info->zBuffer = (double *)malloc(sizeof(double ) * info->w_width);
	if (!info->zBuffer)
		ft_errors(-1, NULL, 0);
}

void	ft_free(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->w_height)
		free(info->buf[i++]);
	free(info->buf);
	free(info->zBuffer);
	i = 0;
	while (i < 5)
		free(info->path[i++]);
	free(info->path);
	i = 0;
	while (i < info->end)
		free(info->worldmap[i++]);
	free(info->worldmap);
	i = 0;
	while (i < info->num_sprts)
		free(info->sprt[i++]);
	free(info->sprt);
	i = 0;
	while (i < 5)
		free(info->texture[i++]);
	free(info->texture);
}

void	ft_init3(int save, char *filename)
{
	t_info	info;

	info.save = save;
	ft_init(&info);
	ft_parse_file(&info, filename);
	ft_init_map(&info);
	ft_check_map_is_enclosed(&info, (int)info.posX, (int)info.posY);
	ft_free_tempmap(&info);
	if (ft_count_sprites(&info) > 0)
		info.sprt = ft_init_sprites(&info);
	ft_init2(&info);
	info.mlx = mlx_init();
	ft_load_texture(&info);
	if (!info.save)
		info.win = mlx_new_window(info.mlx,
				info.w_width, info.w_height, "cub3d");
	main_loop(&info);
	mlx_hook(info.win, 2, (1L << 0), &key_pressed, &info);
	mlx_hook(info.win, 17, (1L << 5), &quit, &info);
	mlx_loop(info.mlx);
}
