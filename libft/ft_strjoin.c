/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:17:23 by rribera           #+#    #+#             */
/*   Updated: 2021/01/08 10:44:36 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len_s1;
	int		len_s2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		++i;
	}
	i = 0;
	while (s2[i])
	{
		result[len_s1 + i] = s2[i];
		++i;
	}
	result[len_s1 + len_s2] = '\0';
	return (result);
}
