/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:17:45 by rribera           #+#    #+#             */
/*   Updated: 2021/02/21 15:32:01 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_space(t_struct *s, int nb)
{
	while (nb)
	{
		ft_putchar_fd(1, ' ', s);
		--nb;
	}
}

void	print_zero(t_struct *s, int nb)
{
	while (nb)
	{
		ft_putchar_fd(1, '0', s);
		--nb;
	}
}

void	p_conv(t_struct *s, int len)
{
	if (s->width != 0 && s->dash == 0 && s->precision < s->width)
	{
		if (s->zero == 0)
			print_space(s, s->width - s->precision - len);
		else
			print_zero(s, s->width - len);
	}
	if (s->precision != 0)
		print_zero(s, s->precision - len);
}
