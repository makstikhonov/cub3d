/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:35:28 by max               #+#    #+#             */
/*   Updated: 2021/04/25 15:31:50 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*new_list;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (elem)
		{
			ft_lstadd_back(&new_list, elem);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
	}
	return (new_list);
}
