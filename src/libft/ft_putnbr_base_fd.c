/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:34:26 by rribera           #+#    #+#             */
/*   Updated: 2021/02/21 16:01:14 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	check_base(char *base)
{
	long long	i;
	long long	j;

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

void				ft_putnbr_base_fd(long long nb, int fd, char *base)
{
	long long	len;

	len = check_base(base);
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (n > 9)
		ft_putnbr_base_fd(n / len, fd);
	ft_putchar_fd(base[n % len], fd);
}
