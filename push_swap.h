/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:38:56 by nilim             #+#    #+#             */
/*   Updated: 2026/09/19 13:17:42 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

// stackops
int		isEmpty(t_list **stack);
void	push(t_list **stack, int n);
int		pop(t_list **stack);
int		peek(t_list **stack);

// sortops
void	s(char c);
void	p(char c);
void	r(char c);
void	rr(char c);

#endif