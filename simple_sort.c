/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 23:44:50 by juho              #+#    #+#             */
/*   Updated: 2026/09/29 15:58:40 by juho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// number of nodes in the stack
size_t	stack_size(t_stack **stack)
{
	size_t	size;
	t_stack	*curr;

	size = 0;
	if (stack == NULL)
		return (0);
	curr = *stack;
	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

// steps down from the top where rank sits (top = 0), -1 if not found
int	find_pos(t_stack **stack, int rank)
{
	int		pos;
	t_stack	*curr;

	pos = 0;
	if (stack == NULL)
		return (-1);
	curr = *stack;
	while (curr != NULL)
	{
		if (curr->content == rank)
			return (pos);
		pos++;
		curr = curr->next;
	}
	return (-1);
}

// rotate a the cheapest way (ra or rra) until rank is on top
static void	bring_to_top(t_vars *bank, int rank)
{
	int	size;
	int	pos;

	size = (int)stack_size(&bank->a);
	pos = find_pos(&bank->a, rank);
	if (pos < 0)
		return ;
	if (pos <= size / 2)
		while (pos-- > 0)
			ops(bank, RA);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			ops(bank, RRA);
	}
}

// selection sort: pb ranks 0..n-1 in order, then pa everything back
// stack a must hold ranks (0..n-1), not raw values
void	simple_sort(t_vars *bank)
{
	int	size;
	int	rank;

	if (bank == NULL)
		return ;
	size = (int)stack_size(&bank->a);
	rank = 0;
	while (rank < size)
	{
		bring_to_top(bank, rank);
		ops(bank, PB);
		rank++;
	}
	while (!isEmpty(&bank->b))
		ops(bank, PA);
}
