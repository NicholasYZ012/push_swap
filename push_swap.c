/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:37:22 by nilim             #+#    #+#             */
/*   Updated: 2026/10/23 18:32:57 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	adaptive_sort(t_vars *bank)
{
	if (bank->disorder < 0.2)
		simple_sort(bank);
	else if ((bank->disorder >= 0.2) && (bank->disorder < 0.5))
		medium_sort(bank);
	else
		complex_sort(bank);
}

static void	pushswap(t_vars *bank)
{
	if ((bank->strat & SMP) != 0)
		simple_sort(bank);
	else if ((bank->strat & MED) != 0)
		medium_sort(bank);
	else if ((bank->strat & CPX) != 0)
		complex_sort(bank);
	else
		adaptive_sort(bank);
}

// Currently assuming that there will be no algorithm specifier
int	main(int argc, char **argv)
{
	static t_vars	bank;
	t_opctr			*opcounter;

	if (argc < 2)
		return (0);
	bank.ncount = argc - 1;
	if (parser(&bank, argv))
		ft_putstr_fd("nice\n", 1);
	opcounter = malloc(sizeof(t_opctr));
	bank.opctr = opcounter;
	pushswap(&bank);
	if ((bank.strat & BCH) != 0)
		benchmark(&bank);
	free(bank.nums);
	free(bank.rank);
	free(opcounter);
	free_stack(&bank.a);
	free_stack(&bank.b);
	return (0);
}
