/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:37:22 by nilim             #+#    #+#             */
/*   Updated: 2026/10/01 18:01:46 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

// Currently assuming that there will be no algorithm specifier
int	main(int argc, char **argv)
{
	static t_vars	bank;

	if (argc < 2)
		return (0);
	bank.ncount = argc - 1;
	if (parser(&bank, argv))
		ft_putstr_fd("nice\n", 1);
	printf("disorder: %f\n", bank.disorder);
	printf("peek A: %d\n", peek(bank.a));
	free(bank.nums);
	free(bank.rank);
	free_stack(&bank.a);
	free_stack(&bank.b);
	return (0);
}
