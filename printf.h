/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:23:02 by rribera           #+#    #+#             */
/*   Updated: 2021/02/16 17:16:33 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "includes/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_struct
{
	int		dot;
	int		dash;
	int		zero;
	int 	asterisk;
	int		width;
	int		precision;
	int		size_print;
	va_list	next;
}				t_struct;


# endif
