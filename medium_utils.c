/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:00:00 by juho              #+#    #+#             */
/*   Updated: 2026/10/16 12:00:00 by juho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// signed steps to bring the nearest rank < limit in a to the top:
// > 0 means that many ra, < 0 means that many rra (whichever is shorter)
// a must hold at least one rank < limit
int	cheapest(t_stack *a, int limit)
{
	int	i;
	int	first;
	int	last;

	i = 0;
	first = -1;
	last = -1;
	while (a != NULL)
	{
		if (a->content < limit)
		{
			if (first < 0)
				first = i;
			last = i;
		}
		i++;
		a = a->next;
	}
	if (first <= i - last)
		return (first);
	return (last - i);
}

// steps > 0 runs op up that many times, steps < 0 runs op down
void	rotate_by(t_vars *bank, int steps, int up, int down)
{
	while (steps > 0)
	{
		ops(bank, up);
		steps--;
	}
	while (steps < 0)
	{
		ops(bank, down);
		steps++;
	}
}

// rotate b the cheapest way (rb or rrb) until rank is on top
void	bring_to_top_b(t_vars *bank, int rank)
{
	int	size;
	int	pos;

	size = (int)stack_size(&bank->b);
	pos = find_pos(&bank->b, rank);
	if (pos < 0)
		return ;
	if (pos > size / 2)
		pos -= size;
	rotate_by(bank, pos, RB, RRB);
}
