/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:15:00 by rribera           #+#    #+#             */
/*   Updated: 2021/02/21 16:02:12 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
		p_conv(s, 0);
		return ;
	}
	p_conv(s, len);
	ft_putnbr_base_fd((long long)i, 1, "0123456789ABCDEF");
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
	if (i == 0 && s->zero_precision)
	{
		p_conv(s, 0);
		return ;
	}
	p_conv(s, len);
	ft_putnbr_base_fd((long long)i, 1, "0123456789abcdef");
	if (s->dash == 1)
		print_space(s, s->width - len);
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
		p_conv(s, 0);
		return ;
	}
	p_conv(s, len);
	ft_putnbr_fd_u(i, 1);
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
	if (i == 0 && s->zero_precision)
	{
		p_conv(s, 0);
		return ;
	}
	p_conv(s, len);
	ft_putnbr_fd(1, i);
	if (s->dash == 1)
		print_space(s, s->width - len);
}

int		handle_conversion(char *str, t_struct *s)
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
