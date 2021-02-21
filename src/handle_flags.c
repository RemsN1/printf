/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:29:24 by rribera           #+#    #+#             */
/*   Updated: 2021/02/21 15:56:36 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int 	handle_dash(t_struct *s)
{
	s->dash = 1;
	return (1);
}

int		handle_zero(t_struct *s)
{
	if (s->dash == 0)
		s->zero = 1;
	return (1);
}

int 	handle_width(char *str, t_struct *s)
{
	int		tmp;
	int		i;

	i = 0;
	s->width = ft_atoi(str);
	tmp = s->width;
	while (tmp / 10 != 0)
	{
		tmp /= 10;
		++i;
	}
	if (i < 0)
	{
		i = -i;
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

int		handle_flags(char *str, t_struct *s)
{
	int		i;

	i = 0;
	while (str[i] == '*' || str[i] == '-' || str[i] == '.' || (str[i] >= '0'
			&& str[i] <= '9'))
	{
		if (str[i] && str[i] == '-')
			i += handle_dash(s);
		if (str[i] && str[i] == '0')
			i += handle_zero(s);
		if (str[i] && str[i] > '0' && str[i] <= '9')
			i += handle_width(str + i, s);	
		if (str[i] && str[i] == '*')
			i += handle_asterisk(s, 0);	
		if (str[i] && str[i] == '.')
			i += handle_dot(str + i, s);
	}
	if (s->precision < 0)
		s->precision = 0;
	if (s->precision >= s->width)
		s->width = 0;
	return (i);
}
