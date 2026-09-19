/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:06:10 by nilim             #+#    #+#             */
/*   Updated: 2026/07/30 12:18:14 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tgt;

	i = 0;
	tgt = (unsigned char *)s;
	while (i < n)
	{
		tgt[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
