/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:23:02 by rribera           #+#    #+#             */
/*   Updated: 2021/03/11 14:04:05 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
	int		asterisk;
	int		width;
	int		precision;
	int		size_print;
	int		zero_precision;
	int		zero_char;
	va_list	next;
}				t_struct;

int				handle_dot(const char *str, t_struct *s);
int				handle_flags(const char *str, t_struct *s);
void			ft_putchar_fd(char c, int fd, t_struct *s);
int				handle_conversion(const char *str, t_struct *s);
void			init_struct(t_struct *s);
void			print_space(t_struct *s, int nb);
void			print_zero(t_struct *s, int nb);
void			p_conv(t_struct *s, int len, int neg);
void			print_c(t_struct *s, const char *str);
void			print_s(t_struct *s);
void			print_p(t_struct *s);
int				handle_asterisk(t_struct *s, int a);
int				ft_printf(const char *str, ...);
void			ft_putnbr_fd(int n, int fd, t_struct *s);
void			ft_putnbr_fd_u(unsigned int n, int fd, t_struct *s);
void			ft_putnbr_base_fd(unsigned int nb, int fd, char *base,
				t_struct *s);
void			p_str(t_struct *s, int len, char *str);
void			p_str_minus(t_struct *s, int len);
void			ft_putnbr_base_fd_long(long long nb, int fd, char *base,
				t_struct *s);

#endif
