/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:41:17 by rribera           #+#    #+#             */
/*   Updated: 2021/01/07 12:37:13 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	if (!dest && !src)
		return (0);
	s1 = (char*)dest;
	s2 = (char*)src;
	while (n)
	{
		*s1 = *s2;
		++s1;
		++s2;
		--n;
	}
	return (dest);
}
