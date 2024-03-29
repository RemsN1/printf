/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:11:34 by rribera           #+#    #+#             */
/*   Updated: 2021/03/11 13:28:27 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr_fd_u(unsigned int n, int fd, t_struct *s)
{
	if (n > 9)
		ft_putnbr_fd_u(n / 10, fd, s);
	ft_putchar_fd(n % 10 + 48, fd, s);
}
