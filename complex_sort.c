/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:11:50 by nilim             #+#    #+#             */
/*   Updated: 2026/10/23 18:31:06 by nilim            ###   ########.fr       */
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
	int		ncount;
	int		orincount;
	t_stack	*curr;

	ncount = bank->ncount;
	orincount = bank->ncount;
	digcount = 0;
	while (ncount != 0)
	{
		while (curr != NULL && bank->ncount)
		{
			curr = bank->a;
			if ((bank->a->content & (1 << digcount)) == 0)
				ops(bank, PB);
			else
				ops(bank, RA);
			bank->ncount--;
		}
		merge(bank);
		bank->ncount = orincount;
		ncount /= 2;
		digcount++;
	}
}
