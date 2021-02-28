/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:43:08 by rribera           #+#    #+#             */
/*   Updated: 2021/02/21 16:31:38 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

static int	check_base(char *base)
{
	int i;
	int j;

	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
				|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = -1;
		while (base[i] && base[++j])
			if (base[i] == base[j] && i != j)
				return (0);
	}
	if (i <= 1)
		return (0);
	return (i);
}

static char	*allocate(long long base_10, int count, char *res)
{
	if (base_10 > 0)
	{
		if (!(res = (char *)malloc(sizeof(char) * count + 1)))
			return (NULL);
	}
	else
	{
		if (!(res = (char *)malloc(sizeof(char) * count + 2)))
			return (NULL);
	}
	return (res);
}

static char	*itoa_base(long long base_10, char *base_to, char *res, int count)
{
	unsigned long long	tmp;
	int					j;
	unsigned long long	cheu;

	if (base_10 < 0)
	{
		cheu = -base_10;
		res[0] = '-';
		++count;
		j = 1;
	}
	else
	{
		j = 0;
		cheu = base_10;
	}
	res[count] = '\0';
	while (count > j)
	{
		tmp = cheu;
		cheu = cheu / check_base(base_to);
		res[--count] = base_to[tmp % check_base(base_to)];
	}
	return (res);
}

char	*ft_itoa_base(long long nbr, char *base_to)
{
	int		len;
	char	*res;
	int		count;

	len = 0;
	count = 0;
	if (!(len = check_base(base_to)))
		return (NULL);
	res = 0;
	if (nbr == 0)
		++count;
	res = allocate(nbr, count, res);
	res = itoa_base(nbr, base_to, res, count);
	if (nbr == 0)
		res[0] = base_to[0];
	return (res);
}
