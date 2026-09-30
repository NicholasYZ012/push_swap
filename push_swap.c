/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:37:22 by nilim             #+#    #+#             */
/*   Updated: 2026/09/28 23:45:26 by juho             ###   ########.fr       */
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

static void	free_stack(t_stack **stack)
{
	while (!isEmpty(stack))
		pop(stack);
}

int	main(int argc, char **argv)
{
	static t_vars	bank;
	int				*nums;
	int				*rank;
	int				i;

	if (argc < 2)
		return (0);
	nums = malloc(sizeof(int) * (argc - 1));
	rank = malloc(sizeof(int) * (argc - 1));
	i = argc - 1;
	if (nums && rank && fill_nums(i, argv, nums) && !has_duplicates(nums, i))
	{
		ranking(nums, rank, i);
		while (i-- > 0)
			push(&bank.a, rank[i]);
		simple_sort(&bank);
	}
	else
		ft_putstr_fd("Error\n", 2);
	free(nums);
	free(rank);
	free_stack(&bank.a);
	free_stack(&bank.b);
	return (0);
}
