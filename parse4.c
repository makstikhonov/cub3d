/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:45:38 by max               #+#    #+#             */
/*   Updated: 2021/05/04 16:29:20 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	res_condition(t_info *info, int x, int y)
{
	if (info->w_width == -2 && info->w_height == -2)
	{
		info->w_width = x;
		info->w_height = y;
	}	
	else
		ft_errors(-7, NULL, 0);
}

int	extract_resolution(char *line, t_info *info)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (is_space(line[i]))
		i++;
	while (ft_isdigit(line[i]))
		x = (x * 10) + (line[i++] - '0');
	while (is_space(line[i]))
		i++;
	while (ft_isdigit(line[i]))
		y = (y * 10) + (line[i++] - '0');
	while (is_space(line[i]))
		i++;
	if (line[i] != '\0')
		ft_errors(-7, NULL, 0);
	else
		res_condition(info, x, y);
	return (1);
}

void	list_condition(t_list **head, char *line, int i, char c)
{
	if (ft_lstsize(*head) > 0 && line[i] == c)
		ft_errors(-6, NULL, 0);
}

void	while_is_space(int *i, char *line)
{
	while (is_space(line[*i]))
		(*i)++;
}

void	parse_line(char **ln, t_info *info, t_list **head, int i)
{
	char	*line;

	line = *ln;
	while_is_space(&i, line);
	list_condition(head, line, i, '\0');
	while (line[i] != '\0')
	{
		list_condition(head, line, i, '\n');
		while_is_space(&i, line);
		if (is_type(info, line[i], line[i + 1], &line[i]))
		{
			if (ft_lstsize(*head) > 0)
				ft_errors(-6, NULL, 0);
			else
				break ;
		}
		else if (is_map_character(line[i]))
		{
			ft_lstadd_back(head, ft_lstnew(ft_strdup(line)));
			break ;
		}
		else
			ft_errors(-6, NULL, 0);
		i++;
	}
}
