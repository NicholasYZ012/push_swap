/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:04:09 by nilim             #+#    #+#             */
/*   Updated: 2026/08/12 22:12:52 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_power(int r, int n)
{
	int	i;
	int	value;

	i = 0;
	value = r;
	if (n == 0)
		return (1);
	while (i < n - 1)
	{
		value *= r;
		i++;
	}
	return (value);
}

static int	ft_calctens(long n)
{
	int	tens;

	tens = 0;
	while (n > 9)
	{
		n /= 10;
		tens++;
	}
	return (tens);
}

char	*ft_itoa(int n)
{
	int		i;
	int		tens;
	long	n2;
	char	str[12];

	i = 0;
	n2 = (long)n;
	if (n2 < 0)
	{
		str[i] = '-';
		i++;
		n2 *= -1;
	}
	tens = ft_calctens(n2);
	while (tens >= 0)
	{
		str[i] = '0' + ((n2 / ft_power(10, tens)) % 10);
		i++;
		tens--;
	}
	str[i] = '\0';
	return (ft_strdup(str));
}
