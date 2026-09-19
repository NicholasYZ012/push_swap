/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:18:14 by nilim             #+#    #+#             */
/*   Updated: 2026/08/12 16:53:00 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newhead;
	t_list	*newnode;
	t_list	*curr;
	void	*newcontent;

	newhead = NULL;
	curr = lst;
	while (curr != NULL)
	{
		newcontent = f(curr->content);
		newnode = ft_lstnew(newcontent);
		if (newnode == NULL)
		{
			ft_lstclear(&newhead, del);
			free(newcontent);
			return (NULL);
		}
		ft_lstadd_back(&newhead, newnode);
		curr = curr->next;
	}
	return (newhead);
}
