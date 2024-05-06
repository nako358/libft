/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:57:34 by htakayam          #+#    #+#             */
/*   Updated: 2024/04/28 16:17:33 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*alst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		alst = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = alst;
	}
}
