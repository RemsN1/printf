/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:17:45 by rribera           #+#    #+#             */
/*   Updated: 2021/03/11 14:13:32 by rribera          ###   ########.fr       */
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
	if (s->precision >= s->width && s->zero_precision == 0)
		s->width = 0;
	if (s->width != 0 && s->dash == 0 && s->precision < s->width)
	{
		if (s->zero == 0 && s->precision == len && neg)
			print_space(s, s->width - len - neg);
		else if (s->zero == 0 && s->precision <= len)
			print_space(s, s->width - len);
		if (s->zero == 0 && s->precision > len)
			print_space(s, s->width - s->precision - neg);
		if (s->zero == 1 && neg)
			ft_putchar_fd('-', 1, s);
		if (s->zero == 1)
			print_zero(s, s->width - len);
	}
	else if (s->zero == 1 && neg)
		ft_putchar_fd('-', 1, s);
	if (neg && s->zero == 0)
	{
		ft_putchar_fd('-', 1, s);
		--len;
	}
	if (s->precision != 0)
		print_zero(s, s->precision - len);
}

void	p_str(t_struct *s, int len, char *str)
{
	int	tmp;

	tmp = 0;
	if (s->precision < len && s->precision != 0)
		len = s->precision;
	if (s->width != 0 && s->dash == 0)
		print_space(s, s->width - len);
	if (s->precision > 0)
	{
		tmp = s->precision;
		while (*str && tmp)
		{
			ft_putchar_fd(*str, 1, s);
			++str;
			--tmp;
		}
	}
	else
	{
		while (*str)
		{
			ft_putchar_fd(*str, 1, s);
			++str;
		}
	}
}

void	p_str_minus(t_struct *s, int len)
{
	if (s->precision < len && s->precision != 0)
		len = s->precision;
	if (s->dash == 1)
		print_space(s, s->width - len);
}
