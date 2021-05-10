/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:14:13 by max               #+#    #+#             */
/*   Updated: 2020/11/10 11:29:24 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = lst;
	if (elem)
	{
		while (elem->next)
		{
			i++;
			elem = elem->next;
		}
		if (elem->next == NULL)
			i++;
	}
	return (i);
}
