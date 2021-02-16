/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:36:39 by rribera           #+#    #+#             */
/*   Updated: 2021/02/16 16:47:07 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		parse(char *str, t_struct *s)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '%')
			i += handle_flags(str + i, s);
		else
			ft_putchar_fd_s(str[i], 1, s);
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
	s->size_print = 0;
}

int		ft_printf(char *str, ...)
{
	t_struct s;

	if (!str)
		return (-1);
	va_start(str, s.next);
	init_struct(&s);
	parse(str, &s);
	va_end(s.next);
	return (s.size_print);
}
