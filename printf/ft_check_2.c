/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 11:34:26 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/22 20:13:38 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int	ft_hex(va_list ap, int length, t_opt *opt)
{
	unsigned int	d;
	int				count;
	unsigned int	i;

	count = 1;
	d = va_arg(ap, unsigned int);
	i = d;
	while (i > 15)
	{
		i /= 16;
		count++;
	}
	ft_check_opt(&count, opt, &length, d);
	ft_spaces(count, &length);
	if (opt->pref == 1)
	{
		ft_putstr("0x");
		count += 2;
	}
	ft_puthex(d);
	ft_rev_spaces(count, &length);
	return (length);
}

int	ft_ptr(va_list ap, int length, t_opt *opt)
{
	unsigned long	l;
	int				count;
	unsigned long	i;

	(void)opt;
	l = va_arg(ap, unsigned long);
	ft_putstr("0x");
	count = 3;
	i = l;
	while (i > 15)
	{
		count++;
		i /= 16;
	}
	ft_spaces(count, &length);
	ft_putptr(l);
	ft_rev_spaces(count, &length);
	return (length);
}

void	ft_check_char(const char **str, int *length, va_list ap, t_opt *opt)
{
	if ((**str) == ' ')
	{
		while ((**str) == ' ')
			(*str)++;
		opt->space = 1;
	}
	if ((**str) == '#')
	{
		opt->pref = 1;
		(*str)++;
	}
	if ((**str) == '*')
	{
		*length = va_arg(ap, int);
		(*str)++;
	}
	else if (**str == '-' || **str == '+' || ft_is_digit(**str) || **str == '.')
		ft_atoi(str, length, opt);
}

void	ft_spaces(int i, int *length)
{
	if (*length > 0)
	{
		while (i < *length)
		{
			i++;
			ft_putchar(' ');
		}
		if (*length < i)
			*length = i;
	}
}

void	ft_rev_spaces(int i, int *length)
{
	if (*length <= 0)
	{
		*length = -*length;
		while (i < *length)
		{
			i++;
			ft_putchar(' ');
		}
		if (*length < i)
			*length = i;
	}
}
