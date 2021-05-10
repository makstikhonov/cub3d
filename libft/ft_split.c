/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:46:21 by max               #+#    #+#             */
/*   Updated: 2021/04/25 15:39:17 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **p, char *s)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	free(s);
	return (NULL);
}

static size_t	ft_counts_words(char *s, char *c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == *c)
		{
			j++;
			while (s[i] == *c)
				i++;
		}
		i++;
	}
	return (j + 1);
}

static char	**ft_add_to_array(char *s, char **p, char *c)
{
	size_t	i;
	size_t	j;
	size_t	z;

	j = 0;
	i = 0;
	z = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == *c || i == ft_strlen(s))
		{
			p[z] = ft_substr(s, i - j, j);
			if (p[z] == NULL)
				return (ft_free(p, s));
			z++;
		}
		while (s[i++] == *c)
		{
			j = 0;
		}
		i++;
		j++;
	}
	free(s);
	return (p);
}

char	**ft_split(char const *st, char c)
{
	size_t	j;
	char	**p;
	char	*s;

	if (!st)
		return (NULL);
	s = ft_strtrim((char *)st, &c);
	j = ft_counts_words(s, &c);
	p = (char **)malloc(sizeof(char *) * (j + 1));
	if (p == NULL)
		return (NULL);
	p[j] = NULL;
	if (c == '\0')
	{
		p[0] = ft_strdup((char *)st);
		free(s);
		return (p);
	}
	if (ft_strlen(s) == 0)
	{
		p[0] = NULL;
		free(s);
		return (p);
	}
	return (ft_add_to_array(s, p, &c));
}
