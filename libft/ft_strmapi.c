/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:30:09 by max               #+#    #+#             */
/*   Updated: 2021/04/25 15:23:47 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;

	if (!s || !f)
		return (NULL);
	i = 0;
	p = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (p == NULL)
		return (NULL);
	while ((char)s[i])
	{
		p[i] = (*f)(i, (char)s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
