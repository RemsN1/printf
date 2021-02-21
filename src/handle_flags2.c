/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:46:21 by rribera           #+#    #+#             */
/*   Updated: 2021/02/21 16:06:13 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		handle_dot(char *str, t_struct *s)
{
	int i;
	int tmp;

	i = 0;
	if (*str == '*')
		handle_asterisk(s, 1);
	else if (*str >= '0' || *str <= '9')
	{
		s->precision = ft_atoi(str);
		tmp = s->precision;
		while (tmp / 10 != 0)
		{
			tmp /= 10;
			++i;
		}
	}
	if (s->zero == 1)
		s->zero = 0;
	if (s->precision == 0)
		s->zero_precision = 1;
	return (i);
}
