/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:24:35 by max               #+#    #+#             */
/*   Updated: 2021/04/28 13:45:21 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

unsigned long	createRGB(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	ft_color(char *line, int *i)
{
	int	r;

	r = 0;
	while (is_space(line[*i]))
		(*i)++;
	if (!ft_isdigit(line[*i]))
		ft_errors(-10, NULL, 0);
	while (line[*i] && ft_isdigit(line[*i]))
		r = r * 10 + (line[(*i)++] - '0');
	while (is_space(line[*i]))
		(*i)++;
	return (r);
}

void	color_check(t_info *info, char location)
{
	int	color;

	if (((info->r >=0 && info->r <=255) && (info->g >=0
				&& info->g <=255) && (info->b >=0 && info->b <=255)))
		color = createRGB(info->r, info->g, info->b);
	else
		color = -1;
	if (location == 'F' && info->floor_color == -2)
		info->floor_color = color;
	else if (location == 'C' && info->ceiling_color == -2)
		info->ceiling_color = color;
	else
		ft_errors(-10, NULL, 0);
}

void	extract_color(t_info *info, char location, char *line)
{
	int	i;

	info->r = -1;
	info->g = -1;
	info->b = -1;
	i = 0;
	info->r = ft_color(line, &i);
	if (line[i] != ',')
		ft_errors(-10, NULL, 0);
	i++;
	info->g = ft_color(line, &i);
	if (line[i] != ',')
		ft_errors(-10, NULL, 0);
	i++;
	info->b = ft_color(line, &i);
	if (line[i] != '\0')
		ft_errors(-10, NULL, 0);
	color_check(info, location);
}
