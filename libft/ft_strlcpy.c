/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:49:05 by max               #+#    #+#             */
/*   Updated: 2021/04/25 15:23:59 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
