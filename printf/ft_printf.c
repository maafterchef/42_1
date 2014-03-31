/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 10:07:37 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/22 18:56:43 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		nb;
	int		length;
	t_opt	opt;

	nb = 0;
	va_start(ap, str);
	while (*str)
	{
		ft_init_opt(&opt);
		length = 0;
		if (*str == '%')
		{
			str++;
			ft_check_char(&str, &length, ap, &opt);
			nb += ft_check_args(ap, *str, length, &opt);
		}
		else
		{
			ft_putchar(*str);
			nb++;
		}
		str++;
	}
	va_end(ap);
	return (nb);
}

int		ft_check_args(va_list ap, char c, int length, t_opt *opt)
{
	int				i;
	static t_func	list[] =
	{
		{'d', &ft_int},
		{'i', &ft_int},
		{'s', &ft_str},
		{'c', &ft_char},
		{'u', &ft_uint},
		{'o', &ft_oct},
		{'x', &ft_hex},
		{'p', &ft_ptr},
	};

	i = 0;
	while (i < 8)
	{
		if (c == list[i].arg)
			return (list[i].ptr(ap, length, opt));
		i++;
	}
	ft_putchar(c);
	return (1);
}

int		ft_digit(int nb)
{
	int	ret;

	ret = 1;
	if (nb < 0)
	{
		ret++;
		if (nb < -9)
		{
			nb = nb / -10;
			ret++;
		}
	}
	while (nb > 9)
	{
		ret++;
		nb/=10;
	}
	return (ret);
}
