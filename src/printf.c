/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:36:39 by rribera           #+#    #+#             */
/*   Updated: 2021/02/21 15:54:05 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parse(char *str, t_struct *s)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '%')
		{
			i += handle_flags(str + i, s);
			handle_conversion(str + i, s);
			if (str[i + 1] == 'd' || str[i + 1] == 'c' || str[i + 1] == 's'
					|| str[i + 1] == 'p' || str[i + 1] == 'i'
					|| str[i + 1] == 'x' || str[i + 1] == 'X'
					|| str[i + 1] == '%')
				++i;
			init_struct(s);
		}	
		else
			ft_putchar_fd(str[i], 1, s);
		++i;
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

int		ft_printf(char *str, ...)
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
