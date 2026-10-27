/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:11:50 by nilim             #+#    #+#             */
/*   Updated: 2026/10/27 11:44:16 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	merge(t_vars *bank)
{
	while (!isempty(&bank->b))
	{
		ops(bank, PA);
	}
}

// digcount: number of digit
// ncount: total number of entries
void	complex_sort(t_vars *bank)
{
	int		digcount;
	int		max;
	int		ncountcpy;
	t_stack	*curr;

	if (bank == NULL || is_sorted(&bank->a))
		return ;
	max = bank->ncount;
	digcount = 0;
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
