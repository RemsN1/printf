/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:46:21 by rribera           #+#    #+#             */
/*   Updated: 2021/03/03 17:22:48 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_dot(const char *str, t_struct *s)
{
	int i;
	int tmp;

	i = 1;
	if (str[i] == '*')
		i +=  handle_asterisk(s, 1);
	else if (str[i] >= '0' && str[i] <= '9')
	{
		s->precision = ft_atoi(str + i);
		tmp = s->precision;
		if (str[i] == '0' && str[i + 1] > 0 && str[i + 1] <= '9')
			++i;
		++i;
		while (tmp / 10)
		{
			tmp /= 10;
			++i;
		}
	}
	if (s->zero == 1)
		s->zero = 0;
	if (s->precision == 0)
		s->zero_precision = 1;
	if (s->precision < 0)
		s->precision = 0;
	return (i);
}
