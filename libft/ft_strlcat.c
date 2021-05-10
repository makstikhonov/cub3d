/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:34:19 by max               #+#    #+#             */
/*   Updated: 2021/04/25 15:24:04 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_length;

	i = 0;
	while (dest[i] != '\0' && i < dstsize)
		i++;
	dst_length = i;
	i = 0;
	while ((char)src[i] && (i + dst_length + 1) < dstsize)
	{
		dest[i + dst_length] = (char)src[i];
		i++;
	}
	if (dst_length < dstsize)
		dest[i + dst_length] = '\0';
	return (dst_length + ft_strlen((char *)src));
}
