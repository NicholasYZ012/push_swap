/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 09:22:50 by nilim             #+#    #+#             */
/*   Updated: 2026/09/21 21:58:45 by juho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

int	isEmpty(t_list **stack)
{
	if (stack == NULL)
		return (-1);
	if (*stack == NULL)
		return (1);
	return (0);
}

void	push(t_list **stack, int n)
{
	if (stack == NULL)
		return ;
	ft_lstadd_front(stack, ft_lstnew(ft_itoa(n)));
}

int	pop(t_list **stack)
{
	int		n;
	t_list	*temp;

	if (stack != NULL && *stack != NULL)
		temp = *stack;
		*stack = (*stack)->next;
		n = ft_atoi(temp->content);
		ft_lstdelone(temp, free);
		return (n);
	return (-1);
}

int	peek(t_list **stack)
{
	if (stack != NULL && *stack != NULL)
		return (ft_atoi((*stack)->content));
	return (-1);
}
