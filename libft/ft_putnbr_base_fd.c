/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:34:26 by rribera           #+#    #+#             */
/*   Updated: 2021/03/11 13:28:01 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	check_base(char *base)
{
	int	i;
	int	j;

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

void		ft_putnbr_base_fd(unsigned int nb, int fd, char *base,
		t_struct *s)
{
	unsigned int	len;

	len = check_base(base);
	if (nb > len)
		ft_putnbr_base_fd(nb / len, fd, base, s);
	ft_putchar_fd(base[nb % len], fd, s);
}
