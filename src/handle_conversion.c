/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:15:00 by rribera           #+#    #+#             */
/*   Updated: 2021/02/28 17:20:27 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_X(t_struct *s)
{
	unsigned int	i;
	int				len;
	char			*tmp;

	i = va_arg(s->next, int);
	tmp = ft_itoa_base((long long)i, "0123456789ABCDEF");
	len = ft_strlen(tmp);
	free(tmp);
	if (i == 0 && s->zero_precision)
	{
		p_conv(s, 0, i < 0 ? 1 : 0);
		return ;
	}
	p_conv(s, len, i < 0 ? 1 : 0);
	ft_putnbr_base_fd((long long)i, 1, "0123456789ABCDEF", s);
	if (s->dash == 1)
		print_space(s, s->width - len);
}

void	print_x(t_struct *s)
{
	unsigned int	i;
	int				len;
	char			*tmp;

	i = va_arg(s->next, int);
	tmp = ft_itoa_base((long long)i, "0123456789abcdef");
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
	ft_putnbr_base_fd(i, 1, "0123456789abcdef", s);
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
		p_conv(s, 0, i < 0 ? 1 : 0);
		return ;
	}
	p_conv(s, len, i < 0 ? 1 : 0);
	ft_putnbr_fd_u(i, 1, s);
	if (s->dash == 1)
		print_space(s, s->width - len);
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
	if (s->dash == 1 && s->precision <= len)
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
		print_x(s);
	else if (*str == 'X')
		print_X(s);
	else if (*str == 's')
		print_s(s);
	else if (*str == 'c')
		print_c(s);
	else if (*str == 'p')
		print_p(s);
	else if (*str == 'i')
		print_d(s);
	else if (*str == '%')
		print_c(s);
	else
		return (0);
	return (1);
}
