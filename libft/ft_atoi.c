/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:51:36 by rribera           #+#    #+#             */
/*   Updated: 2021/01/07 12:10:29 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	test_len_nbr(const char *nptr)
{
	int i;

	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
		++i;
	if (i > 19)
		return (0);
	return (1);
}

int			ft_atoi(const char *nptr)
{
	int sign;
	int i;
	int nbr;

	sign = 1;
	nbr = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		++i;
	}
	if (!test_len_nbr(nptr + i))
		return (sign > 0 ? -1 : 0);
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - 48;
		++i;
	}
	return (nbr * sign);
}
