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

	if (stacka == NULL || stackb == NULL)
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

	// last means previous node
	if (stack == NULL || *stack == NULL)
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
int	rr(t_stack **stack)
{
	t_stack	*last;
	t_stack	*curr;

	// last means previous node
	if (stack == NULL || *stack == NULL)
		return (0);
	curr = *stack;
	while (curr->next != NULL)
	{
		last = curr;
		curr = curr->next;
	}
	last->next = NULL;
	// last now means the last node, curr holds the first node
	last = curr;
	curr = *stack;
	*stack = last;
	last->next = curr;
	return (1);
}

// can add error message in when printf is done evaluating
void	ops(t_vars *bank, int op)
{
	if (bank != NULL && op == SA && s(bank->a))
		ft_putstr_fd("sa\n", 1);
	else if (bank != NULL && op == SB && s(bank->b))
		ft_putstr_fd("sb\n", 1);
	else if (bank != NULL && op == SS && s(bank->a) && s(bank->b))
		ft_putstr_fd("sb\n", 1);
	else if (bank != NULL && op == PA && p(bank->a, bank->b))
		ft_putstr_fd("pa\n", 1);
	else if (bank != NULL && op == PB && p(bank->b, bank->a))
		ft_putstr_fd("pb\n", 1);
	else if (bank != NULL && op == RA && r(bank->a))
		ft_putstr_fd("ra\n", 1);
	else if (bank != NULL && op == RB && r(bank->b))
		ft_putstr_fd("rb\n", 1);
	else if (bank != NULL && op == RR && r(bank->a) && rr(bank->b))
		ft_putstr_fd("rr\n", 1);
	else if (bank != NULL && op == RRA && rr(bank->a))
		ft_putstr_fd("rra\n", 1);
	else if (bank != NULL && op == RRB && rr(bank->b))
		ft_putstr_fd("rrb\n", 1);
	else if (bank != NULL && op == RRR && rr(bank->a) && rr(bank->b))
		ft_putstr_fd("rrr\n", 1);
}
