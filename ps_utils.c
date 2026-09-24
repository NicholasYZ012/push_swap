/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:31:11 by juho              #+#    #+#             */
/*   Updated: 2026/09/24 22:13:21 by nilim            ###   ########.fr       */
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
		value = (value * 10) + (*nptr - '0');
		if (value * neg > INT_MAX || value * neg < INT_MIN)
			return (*error = 1, 0);
		nptr++;
	}
	if (*nptr != '\0')
		return (*error = 1, 0);
	return (value * neg);
}

// nums: array of inputted number values
// rank: array that stores the rank of each number according to their index values
// number_of_el: total number of inputted number values OR size of nums 
void	ranking(int *nums, int *rank, int number_of_el)
{
	int	i;
	int	j;

	i = 0;
	// Initialising the elements in rank array
	while (i < number_of_el)
		rank[i++] = 0;
	i = 0;
	while (i < number_of_el)
	{
		j = i + 1;
		while (j < number_of_el)
		{
			if (nums[j] < nums[i])
				rank[i]++;
			else
				rank[j]++;
			j++;
		}
		i++;
	}
}
