/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:06:04 by nilim             #+#    #+#             */
/*   Updated: 2026/10/06 21:29:08 by nilim            ###   ########.fr       */
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

// Check for duplicates
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

static float	calc_disorder(t_stack *stack)
{
	t_stack	*left;
	t_stack	*right;
	float	pairs;
	float	mistakes;

	left = stack;
	pairs = 0;
	mistakes = 0;
	while (left != NULL && left->next != NULL)
	{
		right = left->next;
		pairs++;
		while (right->next != NULL)
		{
			if (left->content > right->content)
				mistakes++;
			right = right->next;
			pairs++;
		}
		left = left->next;
	}
	return (mistakes / pairs);
}

// Function: check for options inputted by user
// checked: amount of arguments that are checked
static int	strat_checker(t_vars *bank, char **argv)
{
	if (ft_strnstr(argv[1], "--bench", 7) && bank->strat == 0)
	{
		bank->strat |= BCH;
		return (1);
	}
	else if (bank->strat == 0 || bank->strat == BCH)
	{
		if (ft_strnstr(argv[1], "--simple", 8) && argv++ && bank->ncount--)
			bank->strat |= SMP;
		else if (ft_strnstr(argv[1], "--medium", 8) && argv++ && bank->ncount--)
			bank->strat |= MED;
		else if (ft_strnstr(argv[1], "--complex", 9) && argv++ && bank->ncount--)
			bank->strat |= CPX;
		else if (ft_strnstr(argv[1], "--adaptive", 10) && argv++ && bank->ncount--)
			bank->strat |= ADP;
		else
			return (0);
		return (1);
	}
	return (0);
}

// argv: user input
// ncount: total amount of numbers in the list inputted
// strat checker is ran twice to check for the first 2 arguments
int	parser(t_vars *bank, char **argv)
{
	int ncount;

	argv += strat_checker(bank, argv);
	argv += strat_checker(bank, argv);
	ncount = bank->ncount;
	bank->nums = malloc(sizeof(int) * (ncount));
	bank->rank = malloc(sizeof(int) * (ncount));
	if (bank->nums && bank->rank && fill_nums(ncount, argv, bank->nums)
		&& !has_duplicates(bank->nums, ncount))
	{
		ranking(bank->nums, bank->rank, ncount);
		while (ncount-- > 0)
			push(&bank->a, bank->rank[ncount]);
		bank->disorder = calc_disorder(bank->a);
		return (1);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
