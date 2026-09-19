/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:06:44 by nilim             #+#    #+#             */
/*   Updated: 2026/08/12 22:45:58 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strnlen(const char *str, size_t n)
{
	size_t	c;

	c = 0;
	while (str[c] && c < n)
		c++;
	return (c);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	dsize;
	size_t	orilength;

	n = 0;
	dsize = ft_strnlen(dst, size);
	orilength = dsize + ft_strlen(src);
	if (dsize >= size || !size)
		return (orilength);
	n = dsize;
	while (n < size - 1 && *src)
	{
		dst[n] = *src;
		n++;
		src++;
	}
	dst[n] = '\0';
	return (orilength);
}
