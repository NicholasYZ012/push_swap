/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 15:53:22 by nilim             #+#    #+#             */
/*   Updated: 2026/08/19 10:01:57 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tgt;
	size_t			i;

	tgt = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tgt[i] == (unsigned char)c)
			return ((void *)&(tgt[i]));
		i++;
	}
	return (NULL);
}
