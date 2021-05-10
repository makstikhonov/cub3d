/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 09:22:45 by max               #+#    #+#             */
/*   Updated: 2020/11/12 17:29:36 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;

	p = (char *)str;
	i = 0;
	j = 0;
	if (!ft_strlen(to_find))
		return (p);
	while (p[i] != '\0' && i < len)
	{
		while (p[i + j] == (char)to_find[j] && (i + j) < len)
		{
			if ((char)to_find[j + 1] == '\0')
			{
				return (&p[i]);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
