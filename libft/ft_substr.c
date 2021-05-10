/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:48:56 by max               #+#    #+#             */
/*   Updated: 2021/04/25 15:22:32 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	length;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!ft_strlen(s))
		return (NULL);
	length = ft_strlen(s) - start;
	if (length > len)
		length = len;
	if (start >= ft_strlen(s))
		length = 0;
	p = malloc(sizeof(char) * (length + 1));
	if (p == NULL)
		return (NULL);
	while (i < length)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
