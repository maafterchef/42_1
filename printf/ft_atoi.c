/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 10:56:39 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/22 19:49:16 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static void	ft_opt_check(char c, t_opt *opt);
static int	ft_opt_char(char c);

void	ft_atoi(const char **str, int *length, t_opt *opt)
{
	int	neg;

	neg = 1;
	while (ft_opt_char(**str))
	{
		if ((**str) == '-')
			neg = -1;
		ft_opt_check(**str, opt);
		(*str)++;
	}
	while (ft_is_digit((**str)))
	{
		*length = *length * 10 + (**str) - '0';
		(*str)++;
	}
	*length *= neg;
}

static int	ft_opt_char(char c)
{
	if (c == '+' || c == '-' || c == '0' || c == '.' || c == ' ')
		return (1);
	return (0);
}

static void	ft_opt_check(char c, t_opt *opt)
{
	if (c == '+')
		opt->plus = 1;
	else if (c == '0')
		opt->zero = 1;
	else if (c == '.')
		opt->zero = 2;
	else if (c == ' ')
		opt->space = 1;
}

int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
