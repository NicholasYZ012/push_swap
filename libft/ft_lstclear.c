/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:01:40 by nilim             #+#    #+#             */
/*   Updated: 2026/08/12 16:59:05 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*succ;

	if (lst == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		succ = curr->next;
		del(curr->content);
		free(curr);
		curr = succ;
	}
	*lst = NULL;
}
