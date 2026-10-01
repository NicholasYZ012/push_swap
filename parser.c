/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:06:04 by nilim             #+#    #+#             */
/*   Updated: 2026/10/01 15:29:53 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

// parse argv[1..n] into nums, 0 if any argument is not a valid int
static int	fill_nums(int n, char **argv, int *nums)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < n)
	{
		nums[i] = (int)ft_atoi_push_swap(argv[i + 1], &error);
		if (error)
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(int *nums, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parser(t_vars *bank, char **argv, int ncount)
{
	bank->nums = malloc(sizeof(int) * (ncount));
	bank->rank = malloc(sizeof(int) * (ncount));
	if (bank->nums && bank->rank && fill_nums(ncount, argv, bank->nums) && !has_duplicates(bank->nums, ncount))
	{
		ranking(bank->nums, bank->rank, ncount);
		while (ncount-- > 0)
			push(&bank->a, bank->rank[ncount]);
		return (1);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
