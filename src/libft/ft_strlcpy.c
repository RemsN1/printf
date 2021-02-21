/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:12:04 by rribera           #+#    #+#             */
/*   Updated: 2021/01/07 12:47:27 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	if (!src)
		return (0);
	len_src = ft_strlen(src);
	if (size == 0 || !dst)
		return (len_src);
	if (len_src + 1 < size)
	{
		i = -1;
		while (++i < len_src + 1)
			dst[i] = src[i];
	}
	else
	{
		i = -1;
		while (++i < size)
			dst[i] = src[i];
		dst[size - 1] = '\0';
	}
	return (len_src);
}
