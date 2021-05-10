/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:06:05 by max               #+#    #+#             */
/*   Updated: 2021/04/25 15:24:39 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
