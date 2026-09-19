/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:37:22 by nilim             #+#    #+#             */
/*   Updated: 2026/09/19 12:08:04 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	main()
{
	static t_list	*stackA;
	// static t_list	*stackB;

	push(&stackA, 3);
	printf("peek:%d\n", peek(&stackA));
	printf("pop:%d\n", pop(&stackA));
	printf("peek:%d\n", peek(&stackA));
}
