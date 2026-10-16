/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:56:41 by juho              #+#    #+#             */
/*   Updated: 2026/10/16 12:00:00 by juho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// up to this many numbers simple_sort is used (sort_three, 2 moves max)
#define SMALL_N 3

// phase 1 for one bucket (ranks lo..hi-1): pb each of them, nearest first
// numbers from the lower half of the bucket also get rb, so inside b the
// bucket ends up roughly ordered and its biggest numbers stay near the top
static void	push_bucket(t_vars *bank, int lo, int hi)
{
	int	left;
	int	rank;
	int	steps;
	int	pending;

	left = hi - lo;
	pending = 0;
	while (left-- > 0)
	{
		steps = cheapest(bank->a, hi);
		if (pending && steps > 0)
		{
			ops(bank, RR);
			steps--;
		}
		else if (pending)
			ops(bank, RB);
		rotate_by(bank, steps, RA, RRA);
		rank = bank->a->content;
		ops(bank, PB);
		pending = (rank < lo + (hi - lo) / 2);
	}
	if (pending)
		ops(bank, RB);
}

// phase 2: biggest rank still in b goes to the top, then pa
// a is built ascending because every pa lands on something bigger
// if the next biggest is clearly closer, pa it first, then the biggest
// and sa to swap them back into order
static void	pull_back(t_vars *bank, int rank)
{
	while (rank >= 0)
	{
		if (rank > 0 && dist_b(bank, rank - 1) + 1 < dist_b(bank, rank))
		{
			bring_to_top_b(bank, rank - 1);
			ops(bank, PA);
			bring_to_top_b(bank, rank);
			ops(bank, PA);
			ops(bank, SA);
			rank--;
		}
		else
		{
			bring_to_top_b(bank, rank);
			ops(bank, PA);
		}
		rank--;
	}
}

// bucket sort, stack a must hold ranks (0..n-1)
// buckets go to b smallest first, the 3 biggest ranks stay in a
void	medium_sort(t_vars *bank)
{
	int	n;
	int	lo;
	int	hi;

	n = (int)stack_size(&bank->a);
	if (is_sorted(&bank->a))
		return ;
	if (n <= SMALL_N)
	{
		simple_sort(bank);
		return ;
	}
	lo = 0;
	while (lo < n - 3)
	{
		hi = lo + ft_sqrt(n) * 11 / 4;
		if (hi > n - 3)
			hi = n - 3;
		push_bucket(bank, lo, hi);
		lo = hi;
	}
	if (!is_sorted(&bank->a))
		sort_three(bank);
	pull_back(bank, n - 4);
}
