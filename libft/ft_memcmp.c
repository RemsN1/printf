/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:41:41 by rribera           #+#    #+#             */
/*   Updated: 2021/01/07 12:30:06 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*first;
	unsigned char		*second;

	first = (unsigned char*)s1;
	second = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (first[i] != second[i])
			return (first[i] - second[i]);
		++i;
	}
	return (0);
}
