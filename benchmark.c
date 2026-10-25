/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 09:46:19 by nilim             #+#    #+#             */
/*   Updated: 2026/10/23 15:24:33 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	printadpt(t_vars *bank)
{
	ft_putstr_fd("Adaptive / ", 2);
	if (bank->disorder < 0.2)
		ft_putstr_fd("O(n²)\n", 2);
	else if ((bank->disorder >= 0.2) && (bank->disorder < 0.5))
		ft_putstr_fd("O(n√n)\n", 2);
	else
		ft_putstr_fd("O(n log n)\n", 2);
}

static void	put_totops(t_opctr *opctr)
{
	int	tot_ops;

	tot_ops = opctr->sa + opctr->sb + opctr->ss + opctr->pa + opctr->pb;
	tot_ops += opctr->ra + opctr->rb + opctr->rr + opctr->rra + opctr->rrb;
	tot_ops += opctr->rrr;
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(tot_ops, 2);
	ft_putstr_fd("\n", 2);
}

static void	put_ops(t_opctr *opctr)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(opctr->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(opctr->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(opctr->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(opctr->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(opctr->pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(opctr->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(opctr->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(opctr->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(opctr->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(opctr->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(opctr->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	benchmark(t_vars *bank)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(bank->disorder * 100), 2);
	ft_putstr_fd(".", 2);
	if ((int)(bank->disorder * 10000) % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(((int)(bank->disorder * 10000) % 100), 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	if ((bank->strat & SMP) != 0)
		ft_putstr_fd("Simple / O(n²)\n", 2);
	else if ((bank->strat & MED) != 0)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if ((bank->strat & CPX) != 0)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
		printadpt(bank);
	put_totops(bank->opctr);
	put_ops(bank->opctr);
}
