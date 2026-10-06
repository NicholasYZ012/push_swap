/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:11:50 by nilim             #+#    #+#             */
/*   Updated: 2026/10/05 11:06:06 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	merge(t_vars *bank)
{
	while (!isempty(&bank->b))
	{
		ops(bank, PB);
		ops(bank, RA);
	}
}

// digcount: number of digit
// ncount: total number of entries
void	complex_sort(t_vars *bank)
{
	int		digcount;
	int		ncount;
	t_stack	*curr;

	ncount = bank->ncount;
	digcount = 0;
	while (ncount != 0)
	{
		while (curr != NULL)
		{
			curr = bank->a;
			if ((bank->a->content & (1 << digcount)) != 0)
				ops(bank, PA);
		}
		merge(bank);
		ncount /= 2;
		digcount++;
	}
}
/*
Bugs (Unsure)
i think using ncount /= 2 until ncount = 0 to calculate the number of digits has a blind spot
maybe in some cases, 1 digit will be skipped
*/