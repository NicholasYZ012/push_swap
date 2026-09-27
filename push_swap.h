/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:38:56 by nilim             #+#    #+#             */
/*   Updated: 2026/09/27 19:39:59 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_vars
{
	t_stack	*a;
	t_stack	*b;
}	t_vars;

// stackops
int		isEmpty(t_stack **stack);
void	push(t_stack **stack, int n);
int		pop(t_stack **stack);
int		peek(t_stack **stack);

// sortops
int		s(t_stack *stack);
int		p(t_stack **stacka, t_stack **stackb);
int		r(t_stack **stack);
int		rr(t_stack **stack);

// ps_utils
int		ft_sqrt(int nb);
long	ft_atoi_push_swap(const char *nptr, int *error);
void	ranking(int *nums, int *rank, int size);

#endif