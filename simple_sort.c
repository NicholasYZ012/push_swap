/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 23:44:50 by juho              #+#    #+#             */
/*   Updated: 2026/09/29 00:24:03 by juho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
Count the stack: Write a function that returns how many items are in a stack. You'll need the size.
Find the position: Write a function that takes a stack and a rank and returns how many steps down from the top that rank is. The top is position 0.
Bring it to the top: If the item is in the top half, use ra that many times. If it's in the bottom half, rra is shorter. Think about how to work out how many rra moves you need.
Push it away: Once it's on top, do pb and move on to the next rank.
Bring everything back: When a is empty, do pa until b is empty.
*/
size_t	stack_size(t_stack **stacka)
{
	
}
int	find_pos(t_stack **stack, int rank)
{
	//stack size / 2 to find middle point and if the rank is <= the middle point do normal rotate, else reverse rotate
}