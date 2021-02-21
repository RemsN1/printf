/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:20:43 by rribera           #+#    #+#             */
/*   Updated: 2021/01/07 12:42:48 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	cnt_word(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		if (s[i] != c && s[i])
		{
			++count;
			while (s[i] != c && s[i])
				++i;
		}
	}
	return (count);
}

static int	len_word(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i + 1);
}

static char	*alloc_free(char **s, int index, int size)
{
	if (!(s[index] = (char*)malloc(sizeof(char) * size)))
	{
		while (--index >= 0)
			free(s[index]);
		return (NULL);
	}
	return (s[index]);
}

char		**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	i = 0;
	if (!s || !(result = (char **)malloc(sizeof(char*) * (cnt_word(s, c) + 1))))
		return (NULL);
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		k = -1;
		if (s[i] != c && s[i])
		{
			if (!(result[j] = (alloc_free(result, j, len_word(s + i, c)))))
				return (NULL);
			while (s[i] != c && s[i])
				result[j][++k] = s[i++];
			result[j++][k + 1] = '\0';
		}
	}
	result[j] = 0;
	return (result);
}
