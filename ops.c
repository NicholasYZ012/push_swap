/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:09:54 by nilim             #+#    #+#             */
/*   Updated: 2026/10/23 18:25:44 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

// runs op on both stacks (ss/rr/rrr); counts if at least one stack moved
static int	both(t_vars *bank, int op)
{
	int	moved_a;
	int	moved_b;

	if (op == SS)
	{
		moved_a = s(bank->a);
		moved_b = s(bank->b);
	}
	else if (op == RR)
	{
		moved_a = r(&bank->a);
		moved_b = r(&bank->b);
	}
	else
	{
		moved_a = rr(&bank->a);
		moved_b = rr(&bank->b);
	}
	return (moved_a || moved_b);
}

// can add error message in when printf is done evaluating
void	ops(t_vars *bank, int op)
{
	if (bank == NULL)
		return ;
	if (op == SA && s(bank->a) && ++bank->opctr->sa)
		ft_putstr_fd("sa\n", 1);
	else if (op == SB && s(bank->b) && ++bank->opctr->sb)
		ft_putstr_fd("sb\n", 1);
	else if (op == PA && p(&bank->a, &bank->b) && ++bank->opctr->pa)
		ft_putstr_fd("pa\n", 1);
	else if (op == PB && p(&bank->b, &bank->a) && ++bank->opctr->pb)
		ft_putstr_fd("pb\n", 1);
	else if (op == RA && r(&bank->a) && ++bank->opctr->ra)
		ft_putstr_fd("ra\n", 1);
	else if (op == RB && r(&bank->b) && ++bank->opctr->rb)
		ft_putstr_fd("rb\n", 1);
	else if (op == RRA && rr(&bank->a) && ++bank->opctr->rra)
		ft_putstr_fd("rra\n", 1);
	else if (op == RRB && rr(&bank->b) && ++bank->opctr->rrb)
		ft_putstr_fd("rrb\n", 1);
	else if (op == SS && both(bank, op) && ++bank->opctr->ss)
		ft_putstr_fd("ss\n", 1);
	else if (op == RR && both(bank, op) && ++bank->opctr->rr)
		ft_putstr_fd("rr\n", 1);
	else if (op == RRR && both(bank, op) && ++bank->opctr->rrr)
		ft_putstr_fd("rrr\n", 1);
}
