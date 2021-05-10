/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:24:02 by max               #+#    #+#             */
/*   Updated: 2021/04/27 09:18:16 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	ft_write_bmp(char *bmp, int size)
{
	int	rs;

	rs = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (!rs)
		ft_errors(-5, NULL, 0);
	write(rs, bmp, size);
	free(bmp);
	close(rs);
}

void	ft_bmp(t_info *info, t_img *image)
{
	char	*bmp;
	int		size;
	int		num;

	size = info->w_height * info->w_width * (image->bpp >> 3) + 54;
	bmp = (char *)malloc(sizeof(char) * size);
	if (!bmp)
		ft_errors(-1, info, 1);
	ft_memset(bmp, 0, size);
	ft_memmove(&bmp[0], "BM", 2);
	ft_memmove(&bmp[2], &size, 4);
	num = 54;
	ft_memmove(&bmp[10], &num, 4);
	num = 40;
	ft_memmove(&bmp[14], &num, 4);
	ft_memmove(&bmp[18], &info->w_width, 4);
	num = -info->w_height;
	ft_memmove(&bmp[22], &num, 4);
	num = 1;
	ft_memmove(&bmp[26], &num, 2);
	ft_memmove(&bmp[28], &image->bpp, 2);
	ft_memmove(&bmp[54], image->data, (size - 54));
	ft_write_bmp(bmp, size);
	quit(info);
}
