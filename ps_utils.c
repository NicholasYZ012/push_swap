/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:31:11 by juho              #+#    #+#             */
/*   Updated: 2026/09/23 21:41:50 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

long	ft_atoi_push_swap(const char *nptr, int *error)
{
	long	neg;
	long	value;
	int		digit;

	neg = 1;
	value = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	if (!ft_isdigit(*nptr))
		return (*error = 1, 0);
	while (ft_isdigit(*nptr))
	{
		digit = *nptr - '0';
		
		if (value > (LONG_MAX - digit) / 10)
			return (*error = 1, 0);

		value = (value * 10) + digit;

		if ((neg == 1 && value > INT_MAX) 
			|| (neg == -1 && (-value) < INT_MIN))
			return (*error = 1, 0);

		nptr++;
	}
	if (*nptr != '\0')
		return (*error = 1, 0);
	return (value * neg);
}

void	ranking(int *nums, int *rank, int size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < size)
	{
		count = 0;
		j = 0;
		while (j < size)
		{
			if (nums[j] < nums[i])
				count++;
			j++;
		}
		rank[i] = count;
		i++;
	}
}
