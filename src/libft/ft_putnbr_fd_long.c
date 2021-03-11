/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:07:24 by rribera           #+#    #+#             */
/*   Updated: 2021/03/11 13:29:14 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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

void				ft_putnbr_base_fd_long(long long n, int fd, char *base,
					t_struct *s)
{
	long long len;

	len = check_base(base);
	if (n > len)
		ft_putnbr_base_fd_long(n / len, fd, base, s);
	ft_putchar_fd(base[n % len], fd, s);
}
