/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:53:27 by nilim             #+#    #+#             */
/*   Updated: 2026/08/12 22:06:44 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	begin;
	int				end;

	if (s1[0] == '\0')
		return (ft_calloc(1, sizeof(char)));
	begin = 0;
	end = ft_strlen(s1) - 1;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	if (s1[begin] == '\0')
		return (ft_calloc(1, sizeof(char)));
	while (ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, begin, end - begin + 1));
}
