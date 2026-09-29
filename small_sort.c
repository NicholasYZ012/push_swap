/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 23:44:50 by juho              #+#    #+#             */
/*   Updated: 2026/09/29 23:35:18 by juho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1 if a is in ascending order from the top (or has fewer than 2 nodes)
int	is_sorted(t_stack **stack)
{
	t_stack	*curr;

	if (stack == NULL)
		return (1);
	curr = *stack;
	while (curr != NULL && curr->next != NULL)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

// hardcoded moves for the 6 orderings of 3 nodes in a, max 2 moves
void	sort_three(t_vars *bank)
{
	int	x;
	int	y;
	int	z;

	x = bank->a->content;
	y = bank->a->next->content;
	z = bank->a->next->next->content;
	if (x > y && y < z && x < z)
		ops(bank, SA);
	else if (x > y && y > z)
	{
		ops(bank, SA);
		ops(bank, RRA);
	}
	else if (x > y)
		ops(bank, RA);
	else if (y > z && x < z)
	{
		ops(bank, SA);
		ops(bank, RA);
	}
	else if (y > z)
		ops(bank, RRA);
}

// selection sort for any size >= 3: pb ranks 0..size-4 in order,
// sort_three the last 3 left in a, then pa everything back
// b ends up descending, so pa restores ascending order on top of a
void	sort_small(t_vars *bank, int size)
{
	int	rank;

	rank = 0;
	while (rank < size - 3)
	{
		bring_to_top(bank, rank);
		ops(bank, PB);
		rank++;
	}
	if (!is_sorted(&bank->a))
		sort_three(bank);
	while (!isEmpty(&bank->b))
		ops(bank, PA);
}
