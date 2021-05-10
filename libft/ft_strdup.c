/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 13:37:47 by wlakita           #+#    #+#             */
/*   Updated: 2021/04/25 15:25:05 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
