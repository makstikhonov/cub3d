/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:36:32 by max               #+#    #+#             */
/*   Updated: 2021/05/04 16:30:04 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	ft_parse_file_loop (t_info *info, t_list **head, int fd)
{
	int		rs;
	char	*line;

	line = NULL;
	rs = get_next_line(fd, &line);
	while (rs > 0)
	{
		parse_line(&line, info, head, 0);
		free(line);
		rs = get_next_line(fd, &line);
	}
	if (rs < 0)
		ft_errors(-5, NULL, 0);
	parse_line(&line, info, head, 0);
	free(line);
}

int	ft_parse_file(t_info *info, char *filename)
{
	int		fd;
	t_list	*head;

	head = NULL;
	fd = open(filename, O_RDONLY);
	if (!fd)
		ft_errors(-5, NULL, 0);
	ft_parse_file_loop(info, &head, fd);
	ft_check_parse(info);
	info->worldmap = make_map(&head, ft_lstsize(head));
	info->tempmap = make_map(&head, ft_lstsize(head));
	ft_lst_clear(head);
	close(fd);
	return (1);
}

int	ft_check_parse(t_info *info)
{
	int	sx;
	int	sy;
	int	i;

	i = 0;
	mlx_get_screen_size(info->mlx, &sx, &sy);
	if (!info->w_width || !info->w_height)
		ft_errors(-7, NULL, 0);
	else
	{
		if (info->w_width > sx || info->w_width > INT32_MAX)
			info->w_width = sx;
		if (info->w_height > sy || info->w_width > INT32_MAX)
			info->w_height = sy;
	}
	if (info->ceiling_color < 0 || info->floor_color < 0)
		ft_errors(-10, NULL, 0);
	while (i < 5)
		if (info->path[i++] == NULL)
			ft_errors(-11, NULL, 0);
	return (1);
}
