/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:43:22 by rribera           #+#    #+#             */
/*   Updated: 2021/02/21 14:32:18 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*fill_result(int compt, long long  n, char *result)
{
	unsigned long long	tmp;
	unsigned long long	nbr;
	int					index;

	index = 0;
	if (n < 0)
	{
		result[0] = '-';
		result[++compt] = '\0';
		index = 1;
		nbr = -n;
	}
	else
	{
		result[compt] = '\0';
		nbr = n;
	}
	while (compt > index)
	{
		tmp = nbr % 10;
		nbr /= 10;
		result[--compt] = tmp + 48;
	}
	return (result);
}

static char	*allocate(int compt, long long n)
{
	char *result;

	if (n > 0)
	{
		if (!(result = (char*)malloc(sizeof(char) * compt)))
			return (NULL);
	}
	else if (n < 0)
	{
		if (!(result = (char*)malloc(sizeof(char) * compt + 1)))
			return (NULL);
	}
	else
	{
		if (!(result = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
	}
	return (result);
}

char		*ft_itoa(long long n)
{
	int					compt;
	char				*result;
	unsigned long long	nbr;

	compt = 0;
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	while (nbr / 10 != 0)
	{
		nbr /= 10;
		++compt;
	}
	++compt;
	if (!(result = allocate(compt + 1, n)))
		return (NULL);
	if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	result = fill_result(compt, n, result);
	return (result);
}
