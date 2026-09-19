/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:16:56 by nilim             #+#    #+#             */
/*   Updated: 2026/08/12 17:13:43 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	if (start >= ft_strlen(s))
		return (ft_calloc(len, sizeof(char)));
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (i < len && s[j])
	{
		substr[i] = s[j];
		i++;
		j++;
	}
	while (i < len)
	{
		substr[i] = '\0';
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
