/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:23:02 by rribera           #+#    #+#             */
/*   Updated: 2021/02/21 16:04:27 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
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
	int		zero_precision;
	va_list	next;
}				t_struct;

int		handle_dot(char *str, t_struct *s);
int		handle_flags(char *str, t_struct *s);
void	ft_putchar_fd(char c, int fd, t_struct *s);
int		handle_conversion(char *str, t_struct *s);
void	init_struct(t_struct *s);
void	print_space(t_struct *s, int nb);
void	print_zero(t_struct *s, int nb);
void	p_conv(t_struct *s, int len);
void	print_c(t_struct *s);
void	print_s(t_struct *s);
void	print_p(t_struct *s);
int		handle_asterisk(t_struct *s, int a);

# endif
