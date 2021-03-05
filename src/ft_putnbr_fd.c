/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:36:11 by rribera           #+#    #+#             */
/*   Updated: 2021/03/04 11:35:24 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd, t_struct *s)
{
	unsigned int nb;

	nb = n;
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd, s);
	ft_putchar_fd(nb % 10 + 48, fd, s);
}
