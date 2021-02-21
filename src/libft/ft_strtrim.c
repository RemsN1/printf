/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:58:48 by rribera           #+#    #+#             */
/*   Updated: 2021/01/07 12:49:52 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		in_charset(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		++i;
	}
	return (0);
}

static	size_t	big_len(char const *s1, char const *set, size_t i)
{
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	while (len_s1 > 0 && in_charset(s1[len_s1 - 1], set))
		--len_s1;
	if (len_s1 > i)
		return (len_s1 - i);
	else if (i > len_s1)
		return (0);
	else
		return (1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;
	size_t	total;
	char	*result;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (in_charset(s1[i], set) && s1[i])
		++i;
	total = big_len(s1, set, i);
	if (!(result = (char*)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	j = 0;
	while (j < total)
	{
		result[j] = s1[i];
		++j;
		++i;
	}
	result[j] = '\0';
	return (result);
}
