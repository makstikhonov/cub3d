/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:45:04 by max               #+#    #+#             */
/*   Updated: 2021/04/23 17:57:53 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_from_fd(char **rmdr, char **p_n, int fd)
{
	char		*buf;
	char		*tmp;
	int			rs;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
	{
		free(*rmdr);
		return (-1);
	}
	rs = 1;
	if (!*p_n && rs >= 0)
	{
		rs = read(fd, buf, BUFFER_SIZE);
		buf[rs] = '\0';
		tmp = *rmdr;
		*rmdr = ft_strjoin(tmp, buf);
		if (!*rmdr)
			return (-1);
		free(tmp);
	}
	free(buf);
	return (rs);
}

int	f_n_find(char **line, char **p_n, char **rmdr)
{
	**p_n = '\0';
	*line = ft_strdup(*rmdr);
	if (!*line)
	{
		free(*rmdr);
		return (-1);
	}
	(*p_n)++;
	ft_strlcpy(*rmdr, *p_n, ft_strlen(*p_n) + 1);
	return (1);
}

int	f_last(char **line, char **rmdr)
{
	*line = ft_strdup(*rmdr);
	if (!*line)
	{
		free(*rmdr);
		return (-1);
	}
	*rmdr[0] = '\0';
	free(*rmdr);
	*rmdr = NULL;
	return (0);
}

int	rmdr_gnl(char **rmdr)
{
	if (!*rmdr)
	{
		*rmdr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (*rmdr == NULL)
			return (-1);
		*rmdr[0] = '\0';
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			rs;
	char		*p_n;
	static char	*rmdr;

	rs = 1;
	if (line == NULL || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	rmdr_gnl(&rmdr);
	p_n = ft_strchr(rmdr, '\n');
	while (rs >= 0)
	{
		rs = read_from_fd(&rmdr, &p_n, fd);
		if (rs < 0)
			return (-1);
		p_n = ft_strchr(rmdr, '\n');
		if (p_n)
			return (f_n_find(line, &p_n, &rmdr));
		if (rs == 0)
			return (f_last(line, &rmdr));
	}
	return (0);
}
