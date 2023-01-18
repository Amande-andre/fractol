/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:28:38 by anmande           #+#    #+#             */
/*   Updated: 2022/06/02 13:27:50 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*modified;
	t_list	*tmp;

	modified = ft_lstnew((*f)(lst->content));
	if (modified == NULL)
		return (NULL);
	lst = lst->next;
	tmp = modified;
	while (lst != NULL)
	{
		ft_lstadd_back(&tmp, ft_lstnew((*f)(lst->content)));
		if (tmp->next == NULL)
		{
			ft_lstclear(&modified, del);
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	return (modified);
}
