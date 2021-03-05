/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:21:34 by rribera           #+#    #+#             */
/*   Updated: 2021/03/05 15:44:11 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_struct *s, const char *str)
{
	unsigned char	c;
	
	if (str[0] == '%')
	{
		c = '%';
		s->precision = 0;
		s->zero_precision = 0;
	}
	else	
		c = (unsigned int)va_arg(s->next, int);
	if (s->zero_precision == 1 && c == 0)
	{
		p_conv(s, 0, 0);
		if (s->dash == 1)
			print_space(s, s->width - 1);
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

void	utils_p(t_struct *s)
{
	ft_putchar_fd('0', 1, s);
	ft_putchar_fd('x', 1, s);
}

void	print_p(t_struct *s)
{
	void	*ptr;
	int		len;
	char	*tmp;

	ptr = va_arg(s->next, void*);
	if (!ptr && s->zero_precision == 1)
	{
		p_conv(s, 2, 0);
		utils_p(s);
		if (s->dash == 1)
			print_space(s, s->width - 2);
		return ;
	}
	tmp = ft_itoa_base((long long)ptr, "0123456789abcdef");
	len = ft_strlen(tmp) + 2;
	free(tmp);
	p_conv(s, len, 0);
	utils_p(s);
	ft_putnbr_base_fd_long((long long)ptr, 1, "0123456789abcdef", s);
	if (s->dash == 1 && s->precision <= len)
		print_space(s, s->width - len);
	else if (s->dash == 1 && s->precision > len)
		print_space(s, s->width - s->precision);
}
