/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:28:09 by max               #+#    #+#             */
/*   Updated: 2021/05/04 16:07:27 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	file_exists(char *filename)
{
	int		fd;
	int		len;

	len = ft_strlen(filename);
	if (!filename || !len)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_errors(-5, NULL, 0);
	}
	close(fd);
	return (1);
}

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	ft_lst_clear(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list->next;
		free(list->content);
		free(list);
		list = temp;
	}
}

int	is_map_character(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == ' ')
		return (1);
	return (0);
}
