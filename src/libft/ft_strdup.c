/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:19:51 by rribera           #+#    #+#             */
/*   Updated: 2021/01/07 12:43:53 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		len_s;
	size_t		i;
	char		*cpy;

	len_s = ft_strlen(s);
	if (!(cpy = (char *)malloc(sizeof(char) * (len_s + 1))))
		return (NULL);
	i = 0;
	while (i < len_s + 1)
	{
		cpy[i] = s[i];
		++i;
	}
	return (cpy);
}
