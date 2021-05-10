/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:05:00 by wlakita           #+#    #+#             */
/*   Updated: 2020/11/09 14:32:26 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*p;

	p = (char *)str;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (p[i] == c)
			return (&p[i]);
		i--;
	}
	if (p[i] == c)
		return (&p[i]);
	return (0);
}
