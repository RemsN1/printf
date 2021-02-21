/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:40:37 by rribera           #+#    #+#             */
/*   Updated: 2021/01/07 12:55:34 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	if (!src && !dest)
		return (0);
	s1 = (char*)dest;
	s2 = (char*)src;
	i = 0;
	if (src < dest)
		while (n--)
			s1[n] = s2[n];
	else
	{
		while (i < n)
		{
			s1[i] = s2[i];
			++i;
		}
	}
	return (dest);
}
