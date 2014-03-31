/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:31:30 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/22 20:09:02 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_check_opt(int *len, t_opt *opt, int *length, int nb)
{
	if (opt->space == 1 && nb >= 0)
	{
		ft_putchar(' ');
		(*len)++;
	}
	if (opt->plus == 1 && nb >= 0)
	{
		ft_putchar('+');
		(*len)++;
	}
	if (opt->zero)
	{
		while (*len != *length)
		{
			ft_putchar('0');
			(*len)++;
		}
		if (opt->zero == 2)
		{
			ft_putchar('0');
			(*len)++;
		}
	}
}

void	ft_init_opt(t_opt *opt)
{
	opt->zero = 0;
	opt->plus = 0;
	opt->space = 0;
	opt->pref = 0;
}
