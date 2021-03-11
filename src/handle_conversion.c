/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:15:00 by rribera           #+#    #+#             */
/*   Updated: 2021/03/11 13:07:13 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa(t_struct *s, char *base)
{
	unsigned int	i;
	int				len;
	char			*tmp;

	i = va_arg(s->next, int);
	tmp = ft_itoa_base(i, base);
	len = ft_strlen(tmp);
	free(tmp);
	if (i == 0 && s->zero_precision == 1)
	{
		p_conv(s, 0, 0);
		if (s->dash == 1)
			print_space(s, s->width);
		return ;
	}
	p_conv(s, len, 0);
	ft_putnbr_base_fd(i, 1, base, s);
	if (s->dash == 1 && s->precision <= len)
		print_space(s, s->width - len);
	else if (s->dash == 1 && s->precision > len)
		print_space(s, s->width - s->precision);
}

void	print_u(t_struct *s)
{
	unsigned int	i;
	int				len;
	char			*tmp;

	i = va_arg(s->next, unsigned int);
	tmp = ft_itoa((long long)i);
	len = ft_strlen(tmp);
	free(tmp);
	if (i == 0 && s->zero_precision)
	{
		p_conv(s, 0, 0);
		if (s->dash == 1)
			print_space(s, s->width);
		return ;
	}
	p_conv(s, len, 0);
	ft_putnbr_fd_u(i, 1, s);
	if (s->dash == 1 && s->precision <= len)
		print_space(s, s->width - len);
	else if (s->dash == 1 && s->precision > len)
		print_space(s, s->width - s->precision);
}

void	print_d(t_struct *s)
{
	int		i;
	int		len;
	char	*tmp;

	i = va_arg(s->next, int);
	tmp = ft_itoa((long long)i);
	len = ft_strlen(tmp);
	free(tmp);
	if (i == 0 && s->zero_precision == 1)
	{
		p_conv(s, 0, 0);
		if (s->dash == 1)
			print_space(s, s->width);
		return ;
	}
	p_conv(s, len, i < 0 ? 1 : 0);
	ft_putnbr_fd(i < 0 ? -i : i, 1, s);
	if (s->dash == 1 && s->precision == len && i < 0)
		print_space(s, s->width - len - 1);
	else if (s->dash == 1 && s->precision <= len)
		print_space(s, s->width - len);
	else if (s->dash == 1 && s->precision > len)
		print_space(s, s->width - s->precision - (i < 0 ? 1 : 0));
}

int		handle_conversion(const char *str, t_struct *s)
{
	if (*str == 'd')
		print_d(s);
	else if (*str == 'u')
		print_u(s);
	else if (*str == 'x')
		print_hexa(s, "0123456789abcdef");
	else if (*str == 'X')
		print_hexa(s, "0123456789ABCDEF");
	else if (*str == 's')
		print_s(s);
	else if (*str == 'c')
		print_c(s, str);
	else if (*str == 'p')
		print_p(s);
	else if (*str == 'i')
		print_d(s);
	else if (*str == '%')
		print_c(s, str);
	else
		return (0);
	return (1);
}
