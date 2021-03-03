/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:29:24 by rribera           #+#    #+#             */
/*   Updated: 2021/03/03 17:14:01 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	handle_dash(t_struct *s)
{
	s->dash = 1;
	return (1);
}

int		handle_zero(t_struct *s, char c)
{
	if (s->dash == 0)
		s->zero = 1;
	if (c == '-')
	{
		s->zero = 0;
		s->dash = 1;
		return (2);
	}
	return (1);
}

int 	handle_width(const char *str, t_struct *s)
{
	int		tmp;
	int		i;

	i = 1;
	s->width = ft_atoi(str);
	tmp = s->width;
	while (tmp / 10)
	{
		tmp /= 10;
		++i;
	}
	if (s->width < 0)
	{
		s->width = -(s->width);
		s->dash = 1;
	}
	return (i);
}

int		handle_asterisk(t_struct *s, int a)
{
	if (a == 0)
		s->width = va_arg(s->next, int);
	else
		s->precision = va_arg(s->next, int);
	return (1);
}

int		handle_flags(const char *str, t_struct *s)
{
	int		i;

	i = 1;
	if (str[i] && str[i] == '-')
		i += handle_dash(s);
	if (str[i] && str[i] == '0')
		i += handle_zero(s, str[i + 1]);
	if (str[i] && str[i] >= '0' && str[i] <= '9')
		i += handle_width(str + i, s);	
	if (str[i] && str[i] == '*')
		i += handle_asterisk(s, 0);	
	if (str[i] && str[i] == '.')
		i += handle_dot(str + i, s);
	return (i);
}
