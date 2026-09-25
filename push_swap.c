/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:37:22 by nilim             #+#    #+#             */
/*   Updated: 2026/09/25 09:52:50 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	main()
{
	static t_vars	bank;

	push(&(bank.a), 3);
	printf("peek:%d\n", peek(&(bank.a)));
	printf("pop:%d\n", pop(&(bank.a)));
	printf("peek:%d\n", peek(&(bank.a)));
}
