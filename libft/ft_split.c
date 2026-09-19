/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:27:28 by nilim             #+#    #+#             */
/*   Updated: 2026/08/19 10:33:54 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_insert(char **arr, char *tgt, char c, int count)
{
	int		i;
	char	*temp;

	temp = tgt;
	i = 0;
	while (i < count)
	{
		arr[i] = tgt;
		while (*tgt != c && tgt[1])
			tgt++;
		while (*tgt == c && tgt[1])
			tgt++;
		i++;
	}
	arr[i] = NULL;
	while (*temp)
	{
		if (*temp == c)
			*temp = '\0';
		temp++;
	}
	return (arr);
}

static int	ft_wordcounter(char *str, char c)
{
	int	w;
	int	i;

	i = 0;
	w = 0;
	if (str[0] && str[0] != c)
		w++;
	while (str[0] && str[i + 1])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1])
			w++;
		i++;
	}
	return (w);
}

char	**ft_conv(char **arr, int w)
{
	int		i;
	char	**real;

	i = 0;
	real = malloc((w + 1) * sizeof(char *));
	if (real == NULL)
		return (NULL);
	while (arr[i])
	{
		real[i] = ft_strdup(arr[i]);
		i++;
	}
	real[i] = NULL;
	free(arr);
	return (real);
}

char	**ft_split(const char *s1, char c)
{
	char	*clean;
	char	**arr;
	int		w;

	if (s1[0] == '\0')
		return (ft_calloc(1, sizeof(char *)));
	clean = ft_strtrim(s1, &c);
	if (clean == NULL)
		return (NULL);
	w = ft_wordcounter(clean, c);
	arr = malloc((w + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr = ft_conv(ft_insert(arr, clean, c, w), w);
	free(clean);
	return (arr);
}
