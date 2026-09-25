/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 08:37:22 by nilim             #+#    #+#             */
/*   Updated: 2026/09/25 12:29:30 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	main()
{
	static t_vars	bank;

	push(&(bank.a), 1);
	push(&(bank.a), 3);
	push(&(bank.a), 5);
	push(&(bank.a), 20);
	printf("peek a:%d\n", peek(&(bank.a)));
	r(&(bank.a));
	printf("peek a:%d\n", peek(&(bank.a)));
	rr(&(bank.a));
	printf("peek a:%d\n", peek(&(bank.a)));
	rr(&(bank.a));
	printf("pop a:%d\n", pop(&(bank.a)));
	r(&(bank.a));
	r(&(bank.a));
	printf("peek a:%d\n", peek(&(bank.a)));
}
