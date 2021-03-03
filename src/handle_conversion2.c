/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:21:34 by rribera           #+#    #+#             */
/*   Updated: 2021/03/03 17:22:54 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_struct *s)
{
	unsigned char	c;

	c = (unsigned char)va_arg(s->next, int);
	if (s->zero_precision == 1 && c == 0)
	{
		p_conv(s, 0, 0);
		return ;
	}
	p_conv(s, 1, 0);
	ft_putchar_fd(c, 1, s);
	if (s->dash == 1)
		print_space(s, s->width - 1);
}

void	print_s(t_struct *s)
{
	char	*str;
	int		len;

	str = va_arg(s->next, char*);
	if (!str || s->zero_precision == 1)
	{
		if (s->zero_precision == 1)
		{
			len = 0;
			p_str(s, len, "");
		}
		else
		{
			len = 6;
			p_str(s, len, "(null)");
		}
		p_str_minus(s, len);
		return ;
	}
	len = ft_strlen(str);
	p_str(s, len, str);
	p_str_minus(s, len);
}

void	print_p(t_struct *s)
{
	void	*ptr;
	int		len;
	char	*tmp;

	ptr = va_arg(s->next, void*);
	tmp = (char*)ptr;
	len = ft_strlen(tmp);
	if (s->width > len && s->dash == 0)
	{
		if (s->zero == 0)
			print_space(s, s->width - len - s->precision);
		else
			print_zero(s, s->width - len);
	}
	ft_putchar_fd(1, '0', s);
	ft_putchar_fd(1, 'x', s);
	if (s->precision != 0)
		print_zero(s, s->precision - len);
	if (s->dash == 1)
		print_space(s, s->width - len);
}
