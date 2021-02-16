/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:06:23 by rribera           #+#    #+#             */
/*   Updated: 2021/01/08 15:35:24 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	len_tf;
	
	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	len_tf = ft_strlen(to_find);
	while (str[i] && i <= len - len_tf)
	{
		if (ft_strncmp(str + i, to_find, len_tf) == 0)
			return ((char *)(str + i));
		++i;
	}
	return (0);
}
