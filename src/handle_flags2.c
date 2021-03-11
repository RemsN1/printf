/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:46:21 by rribera           #+#    #+#             */
/*   Updated: 2021/03/11 14:00:31 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len(int a)
{
	int i;

	i = 0;
	while (a / 10)
	{
		a /= 10;
		++i;
	}
	return (i);
}

int		handle_dot(const char *str, t_struct *s)
{
	int i;

	i = 1;
	if (str[i] == '*' || (str[i] == ' ' && str[i + 1] == '*'))
		i += handle_asterisk(s, 1);
	else if (str[i] >= '0' && str[i] <= '9')
	{
		s->precision = ft_atoi(str + i);
		if (str[i] == '0' && str[i + 1] > '0' && str[i + 1] <= '9')
			++i;
		++i;
		i += len(s->precision);
	}
	if (s->precision == 0)
		s->zero_precision = 1;
	if (s->zero == 1 && s->precision >= 0)
		s->zero = 0;
	if (s->precision < 0)
		s->precision = 0;
	return (i);
}
