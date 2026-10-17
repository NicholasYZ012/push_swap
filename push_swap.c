/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:37:22 by nilim             #+#    #+#             */
/*   Updated: 2026/10/17 12:37:43 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static void pushswap(t_vars *bank)
{
	printf("sort start\n");
	if ((bank->strat & SMP) != 0)
		simple_sort(bank);
	else if ((bank->strat & MED) != 0)
		medium_sort(bank);
	else if ((bank->strat & CPX) != 0)
		complex_sort(bank);
	else
		complex_sort(bank);
	printf("sort end\n");
}

// Currently assuming that there will be no algorithm specifier
int	main(int argc, char **argv)
{
	static t_vars	bank;

	if (argc < 2)
		return (0);
	bank.ncount = argc - 1;
	if (parser(&bank, argv))
		ft_putstr_fd("nice\n", 1);
	pushswap(&bank);
	printf("disorder: %f\n", bank.disorder);
	free(bank.nums);
	free(bank.rank);
	free_stack(&bank.a);
	free_stack(&bank.b);
	return (0);
}
