/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:11:50 by nilim             #+#    #+#             */
/*   Updated: 2026/10/27 21:53:48 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	merge(t_vars *bank)
{
	while (!isempty(&bank->b))
		ops(bank, PA);
}

static void	linesaver(t_vars *bank, int digcount, int max)
{
	int		ncountcpy;
	t_stack	*curr;

	while (max != 0)
	{
		ncountcpy = bank->ncount;
		while (curr != NULL && ncountcpy)
		{
			curr = bank->a;
			if ((bank->a->content & (1 << digcount)) == 0)
				ops(bank, PB);
			else
				ops(bank, RA);
			ncountcpy--;
		}
		merge(bank);
		digcount++;
		max /= 2;
	}
}

// digcount: number of digit
// ncount: total number of entries
void	complex_sort(t_vars *bank)
{
	int	digcount;
	int	max;
	int	size;

	if (bank == NULL || is_sorted(&bank->a))
		return ;
	size = (int)stack_size(&bank->a);
	if (size <= SMALL_N)
	{
		simple_sort(bank);
		return ;
	}
	max = bank->ncount;
	digcount = 0;
	linesaver(bank, digcount, max);
}
