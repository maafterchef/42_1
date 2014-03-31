/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 10:50:16 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/22 20:01:12 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct	s_opt
{
	int		zero;
	int		plus;
	int		space;
	int		pref;
}				t_opt;

typedef struct	s_func
{
	char	arg;
	int		(*ptr)(va_list, int, t_opt *);
}				t_func;

int		ft_printf(const char *, ...)__attribute__((format(printf, 1, 2)));
void	ft_putchar(const char c);
void	ft_putstr(const char *str);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned int d);
void	ft_putoct(unsigned int d);
void	ft_puthex(unsigned int d);
void	ft_putptr(unsigned long l);
int		ft_strlen(const char *str);
int		ft_check_args(va_list ap, char c, int length, t_opt *opt);
int		ft_digit(int nb);
int		ft_int(va_list ap, int length, t_opt *opt);
int		ft_char(va_list ap, int length, t_opt *opt);
int		ft_str(va_list ap, int length, t_opt *opt);
int		ft_uint(va_list ap, int length, t_opt *opt);
int		ft_oct(va_list ap, int length, t_opt *opt);
int		ft_hex(va_list ap, int length, t_opt *opt);
int		ft_ptr(va_list ap, int length, t_opt *opt);
void	ft_check_char(const char **str, int *length, va_list ap, t_opt *opt);
void	ft_spaces(int i, int *length);
void	ft_rev_spaces(int i, int *length);
void	ft_atoi(const char **str, int *length, t_opt *opt);
int		ft_is_digit(int c);
void	ft_check_opt(int *len, t_opt *opt, int *length, int nb);
void	ft_init_opt(t_opt *opt);
#endif
