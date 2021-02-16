/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:16:42 by rribera           #+#    #+#             */
/*   Updated: 2021/01/07 12:46:42 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_s;
	size_t	len_d;
	size_t	i;

	len_s = ft_strlen(src);
	len_d = 0;
	i = 0;
	while (dst[len_d] && size > 0)
	{
		++len_d;
		--size;
	}
	while (src[i] && size > 1)
	{
		dst[i + len_d] = src[i];
		++i;
		--size;
	}
	if (size == 1 || src[i] == '\0')
		dst[i + len_d] = '\0';
	return (len_d + len_s);
}
