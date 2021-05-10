/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:31:51 by max               #+#    #+#             */
/*   Updated: 2021/05/04 15:52:39 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	is_type(t_info *info, char a, char b, char *line)
{
	if ((a == 'R' || a == 'S' || a == 'F' || a == 'C') && is_space(b))
	{
		if (a == 'R')
		{
			line++;
			if (!extract_resolution(line, info))
				ft_errors(-6, NULL, 0);
		}
		else if (a == 'S')
			extract_path(info, 4, line + 1);
		else
			extract_color(info, a, line + 1);
	}
	else if (a == 'N' && b == 'O')
		extract_path(info, 1, line + 2);
	else if (a == 'S' && b == 'O')
		extract_path(info, 0, line + 2);
	else if (a == 'W' && b == 'E')
		extract_path(info, 3, line + 2);
	else if (a == 'E' && b == 'A')
		extract_path(info, 2, line + 2);
	else
		return (0);
	return (1);
}

int	extract_path(t_info *info, int index, char *line)
{
	int		start;
	int		end;
	char	*path;

	start = 0;
	while (is_space(line[start]))
		start++;
	if (line[start] == '\0')
		ft_errors(-11, NULL, 0);
	end = ft_strlen(line);
	while (is_space(line[end - 1]))
		end--;
	path = ft_substr(line, start, end - start);
	if (!file_exists(path))
		ft_errors(-9, NULL, 0);
	else if (info->path[index] == NULL)
		info->path[index] = path;
	else
		ft_errors(-11, NULL, 0);
	return (1);
}

int	check_map_file_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (!filename || len < 4)
		return (0);
	if (filename[len - 1] == 'b' && filename[len - 2] == 'u'
		&&filename[len - 3] == 'c' && filename[len - 4] == '.')
		return (1);
	return (0);
}

char	**make_map(t_list **head, int size)
{
	char	**map;
	int		i;
	t_list	*tmp;

	i = 0;
	map = NULL;
	tmp = *head;
	map = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!map)
		ft_errors(-1, NULL, 0);
	while (tmp)
	{
		map[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (map);
}
