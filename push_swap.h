/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:38:56 by nilim             #+#    #+#             */
/*   Updated: 2026/10/27 21:34:57 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

// push swap operations
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

// strategy selection
# define ADP 0b00001
# define SMP 0b00010
# define MED 0b00100
# define CPX 0b01000
# define BCH 0b10000

#define SMALL_N 3

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_opctr
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_opctr;

// ncount:	total amount of numbers in the list
// nums:	array of inputted number values
// rank:	array that stores the rank of each number according
// 			to their index values
typedef struct s_vars
{
	t_stack	*a;
	t_stack	*b;
	int		strat;
	int		ncount;
	int		*nums;
	int		*rank;
	float	disorder;
	t_opctr	*opctr;
}	t_vars;

// stackops
int		isempty(t_stack **stack);
void	push(t_stack **stack, int n);
int		pop(t_stack **stack);
int		peek(t_stack *stack);

// sortops
int		s(t_stack *stack);
int		p(t_stack **stacka, t_stack **stackb);
int		r(t_stack **stack);
int		rr(t_stack **stack);

// ops
void	ops(t_vars *bank, int op);

// parser
int		parser(t_vars *bank, char **argv);

// benchmark
void	benchmark(t_vars *bank);

// simple_sort
size_t	stack_size(t_stack **stack);
int		find_pos(t_stack **stack, int rank);
void	bring_to_top(t_vars *bank, int rank);
void	simple_sort(t_vars *bank);

// small_sort
int		is_sorted(t_stack **stack);
void	sort_three(t_vars *bank);
void	sort_small(t_vars *bank, int size);

// complex_sort
void	complex_sort(t_vars *bank);

// medium_sort
void	medium_sort(t_vars *bank);
int		cheapest(t_stack *a, int limit);
void	rotate_by(t_vars *bank, int steps, int up, int down);
void	bring_to_top_b(t_vars *bank, int rank);

// ps_utils
int		ft_sqrt(int nb);
long	ft_atoi_push_swap(const char *nptr, int *error);
void	ranking(int *nums, int *rank, int size);
void	free_stack(t_stack **stack);

#endif