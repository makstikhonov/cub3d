/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:29:04 by max               #+#    #+#             */
/*   Updated: 2020/11/10 11:39:32 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*elem;

	elem = lst;
	if (elem)
	{
		while (elem->next)
			elem = elem->next;
		if (elem->next == NULL)
			return (elem);
	}
	return (0);
}
