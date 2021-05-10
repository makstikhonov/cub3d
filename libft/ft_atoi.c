/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:44:19 by wlakita           #+#    #+#             */
/*   Updated: 2021/04/25 15:19:41 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(char *p, int *i)
{
	int	sign;

	sign = 1;
	if (p[*i] == '-' || p[*i] == '+')
	{
		if (p[(*i)++] == '-')
			sign = -1;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long long		result;
	int				i;
	char			*p;

	p = (char *)str;
	result = 0;
	sign = 1;
	i = 0;
	while (p[i] && (p[i] == '\f' || p[i] == '\t' || p[i] == ' '
			|| p[i] == '\n' || p[i] == '\r' || p[i] == '\v'))
		i++;
	sign = ft_sign(p, &i);
	while (p[i] && p[i] >= '0' && p[i] <= '9')
	{
		result *= 10;
		result += p[i++] - '0';
		if (result * sign > 2147483647)
			return (-1);
		if (result * sign < -2147483648)
			return (0);
	}
	result *= sign;
	return (result);
}
