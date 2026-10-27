/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:56:41 by juho              #+#    #+#             */
/*   Updated: 2026/10/27 21:34:43 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// phase 1 for one bucket (ranks lo..hi-1): pb each of them, nearest first
static void	push_bucket(t_vars *bank, int lo, int hi)
{
	int	left;

	left = hi - lo;
	while (left-- > 0)
	{
		rotate_by(bank, cheapest(bank->a, hi), RA, RRA);
		ops(bank, PB);
	}
}

// phase 2: biggest rank still in b goes to the top, then pa
// a is built ascending because every pa lands on something bigger
static void	pull_back(t_vars *bank, int rank)
{
	while (rank >= 0)
	{
		bring_to_top_b(bank, rank);
		ops(bank, PA);
		rank--;
	}
}

// bucket sort, stack a must hold ranks (0..n-1)
// buckets go to b smallest first, the 3 biggest ranks stay in a
void	medium_sort(t_vars *bank)
{
	int	size;
	int	lo;
	int	hi;

	size = (int)stack_size(&bank->a);
	if (is_sorted(&bank->a))
		return ;
	if (size <= SMALL_N)
	{
		simple_sort(bank);
		return ;
	}
	lo = 0;
	while (lo < size - 3)
	{
		hi = lo + ft_sqrt(size) * 2;
		if (hi > size - 3)
			hi = size - 3;
		push_bucket(bank, lo, hi);
		lo = hi;
	}
	if (!is_sorted(&bank->a))
		sort_three(bank);
	pull_back(bank, size - 4);
}
