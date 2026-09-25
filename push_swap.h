/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:38:56 by nilim             #+#    #+#             */
/*   Updated: 2026/09/25 10:00:36 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

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
void	s(char c);
void	p(char c);
void	r(char c);
void	rr(char c);

// ps_utils
int		ft_sqrt(int nb);
long	ft_atoi_push_swap(const char *nptr, int *error);
void	ranking(int *nums, int *rank, int size);

#endif