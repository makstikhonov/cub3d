/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:00:38 by max               #+#    #+#             */
/*   Updated: 2020/11/12 15:38:32 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, char z, size_t bytes)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)buf;
	while (i < bytes)
	{
		p[i] = (unsigned char)z;
		i++;
	}
	return (p);
}
