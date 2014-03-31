/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 16:05:01 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/22 20:12:32 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int	ft_int(va_list ap, int length, t_opt *opt)
{
	int	d;
	int	len;

	d = va_arg(ap, int);
	len = ft_digit(d);
	ft_spaces(len, &length);
	ft_check_opt(&len, opt, &length, d);
	if (d < 0)
		ft_putchar('-');
	ft_putnbr(d);
	ft_rev_spaces(len, &length);
	return (length);
}

int	ft_char(va_list ap, int length, t_opt *opt)
{
	char	c;

	(void)opt;
	c = va_arg(ap, int);
	ft_spaces(1, &length);
	ft_putchar(c);
	ft_rev_spaces(1, &length);
	return (length);
}

int	ft_str(va_list ap, int length, t_opt *opt)
{
	char	*str;
	int		len;

	(void)opt;
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	if (!str)
		ft_spaces(6, &length);
	else
		ft_spaces(len, &length);
	if (!str)
		ft_putstr("(null)");
	else
		ft_putstr(str);
	if (!str)
		ft_rev_spaces(6, &length);
	else
		ft_rev_spaces(len, &length);
	return (length);
}

int	ft_uint(va_list ap, int length, t_opt *opt)
{
	unsigned int	d;
	int				count;
	unsigned int	i;

	count = 1;
	d = va_arg(ap, unsigned int);
	i = d;
	while (d > 9)
	{
		d /= 10;
		count++;
	}
	ft_check_opt(&count, opt, &length, i);
	ft_spaces(count, &length);
	ft_putunbr(i);
	ft_rev_spaces(count, &length);
	return (length);
}

int	ft_oct(va_list ap, int length, t_opt *opt)
{
	unsigned int	d;
	int				count;
	unsigned int	i;

	count = 1;
	d = va_arg(ap, unsigned int);
	i = d;
	while (i > 7)
	{
		i /= 8;
		count++;
	}
	ft_check_opt(&count, opt, &length, d);
	ft_spaces(count, &length);
	if (opt->pref == 1)
	{
		ft_putchar('0');
		count++;
	}
	ft_putoct(d);
	ft_rev_spaces(count, &length);
	return (length);
}
