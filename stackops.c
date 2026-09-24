/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 09:22:50 by nilim             #+#    #+#             */
/*   Updated: 2026/09/24 10:17:49 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

int	isEmpty(t_stack **stack)
{
	if (stack == NULL)
		return (-1);
	if (*stack == NULL)
		return (1);
	return (0);
}

void	push(t_stack **stack, int n)
{
	if (stack == NULL)
		return ;
	ps_lstadd_front(stack, ps_lstnew(n));
}

int	pop(t_stack **stack)
{
	int		n;
	t_stack	*temp;

	if (stack == NULL || *stack == NULL)
		return (-1);
	temp = *stack;
	*stack = temp->next;
	n = temp->content;
	free(temp);
	return (n);
}

int	peek(t_stack **stack)
{
	if (stack != NULL && *stack != NULL)
		return ((*stack)->content);
	return (-1);
}
