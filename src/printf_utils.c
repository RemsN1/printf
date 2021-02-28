/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:17:45 by rribera           #+#    #+#             */
/*   Updated: 2021/02/28 17:16:13 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space(t_struct *s, int nb)
{
	while (nb > 0)
	{
		ft_putchar_fd(' ', 1, s);
		--nb;
	}
}

void	print_zero(t_struct *s, int nb)
{
	while (nb > 0)
	{
		ft_putchar_fd('0', 1, s);
		--nb;
	}
}

void	p_conv(t_struct *s, int len, int neg)
{
	if (s->width != 0 && s->dash == 0 && s->precision < s->width)
	{
		if (s->zero == 0 && s->precision <= len)
			print_space(s, s->width - len);
		if (s->zero == 0 && s->precision > len)
			print_space(s, s->width - s->precision - neg);
		if (s->zero == 1 && neg)
			ft_putchar_fd('-', 1, s);
		if (s->zero == 1)
			print_zero(s, s->width - len);
	}
	if (neg && s->zero == 0)
	{
		ft_putchar_fd('-', 1, s);
		--len;
	}
	if (s->precision != 0)
		print_zero(s, s->precision - len);
}
