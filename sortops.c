/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:09:54 by nilim             #+#    #+#             */
/*   Updated: 2026/09/27 19:51:14 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

// swap first second elements based on inputted stack
int	s(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return (0);
	temp = stack->content;
	stack->content = (stack->next)->content;
	(stack->next)->content = temp;
	return (1);
}

// push first elem from stackb to stacka
int	p(t_stack **stacka, t_stack **stackb)
{
	int	temp;

	if (stacka == NULL || stackb == NULL || *stackb == NULL)
		return (0);
	temp = pop(stackb);
	push(stacka, temp);
	return (1);
}

// Shift up all elements of specified stack by one, first become last
int	r(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*first;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (0);
	first = *stack;
	curr = *stack;
	*stack = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = first;
	first->next = NULL;
	return (1);
}

// Shift down all elements of specified stack by one, last become first
// walks with last one behind curr, then moves curr (the tail) to the top
int	rr(t_stack **stack)
{
	t_stack	*last;
	t_stack	*curr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (0);
	curr = *stack;
	while (curr->next != NULL)
	{
		last = curr;
		curr = curr->next;
	}
	last->next = NULL;
	last = curr;
	curr = *stack;
	*stack = last;
	last->next = curr;
	return (1);
}
