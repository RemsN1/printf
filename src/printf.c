/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:36:39 by rribera           #+#    #+#             */
/*   Updated: 2021/03/05 14:03:49 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse(const char *str, t_struct *s)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += handle_flags(str + i, s);
			handle_conversion(str + i, s);
			++i;
			init_struct(s);
		}
		else if (str[i])
		{
			ft_putchar_fd(str[i], 1, s);
			++i;
		}
	}
}

void	init_struct(t_struct *s)
{
	s->dot = 0;
	s->dash = 0;
	s->zero = 0;
	s->asterisk = 0;
	s->width = 0;
	s->precision = 0;
	s->zero_precision = 0;
}

int		ft_printf(const char *str, ...)
{
	t_struct s;

	if (!str)
		return (-1);
	va_start(s.next, str);
	init_struct(&s);
	s.size_print = 0;
	parse(str, &s);
	va_end(s.next);
	return (s.size_print);
}
