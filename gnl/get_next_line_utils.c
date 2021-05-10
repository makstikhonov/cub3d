/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:44:58 by max               #+#    #+#             */
/*   Updated: 2021/04/28 17:00:13 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while ((char)str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*p;

	p = (char *)str;
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	if (p[i] == c)
		return (&p[i]);
	return (0);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i] != 0)
	{
		str[i] = (char)src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	p = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (p == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i + ft_strlen(s1) < (ft_strlen(s2) + ft_strlen(s1)))
	{
		p[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	p[i + ft_strlen(s1)] = '\0';
	return (p);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while ((char)src[i] != '\0' && i < dstsize - 1)
	{
		dest[i] = (char)src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
