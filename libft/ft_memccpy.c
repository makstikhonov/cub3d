/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:27:44 by max               #+#    #+#             */
/*   Updated: 2020/11/11 16:34:40 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	dst_tmp = dst;
	src_tmp = (unsigned char *)src;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		if (src_tmp[i] == (unsigned char)c)
			return (&dst_tmp[i + 1]);
		i++;
	}
	return (NULL);
}
