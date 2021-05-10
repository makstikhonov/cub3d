/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:54:53 by max               #+#    #+#             */
/*   Updated: 2020/11/11 16:32:05 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*src_tmp;
	unsigned char		*dst_tmp;

	i = 0;
	if (!dst && !src)
		return (NULL);
	src_tmp = (unsigned char *)src;
	dst_tmp = (unsigned char *)dst;
	if (src_tmp < dst_tmp)
	{
		while (len > 0)
		{
			dst_tmp[len - 1] = src_tmp[len - 1];
			len--;
		}
		return (dst_tmp);
	}
	while (i < len)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst_tmp);
}
