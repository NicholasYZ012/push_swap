/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:16:18 by nilim             #+#    #+#             */
/*   Updated: 2026/08/04 10:51:59 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big2;

	i = 0;
	big2 = (char *)big;
	if (*little == '\0')
		return (big2);
	while (i < len && *big2)
	{
		j = 0;
		while (big2[j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return (big2);
		}
		big2++;
		i++;
	}
	return (NULL);
}
