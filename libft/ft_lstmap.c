/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:16:01 by htakayam          #+#    #+#             */
/*   Updated: 2024/04/27 21:44:08 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*save;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(lst);
	save = new_lst;
	while (lst)
	{
		save->content = f((lst)->content);
		if (!(lst->next))
			break ;
		lst = lst->next;
		save->next = ft_lstnew(lst);
		if (!(save->next))
			ft_lstclear(&new_lst, del);
		save = save->next;
	}
	return (new_lst);
}
