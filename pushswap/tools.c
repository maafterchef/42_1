/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:39:31 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/27 16:00:21 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_putnbr(n / -10);
		n = n % 10;
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(const char *str)
{
	int	neg;
	int	ret;

	ret = 0;
	neg = 1;
	while (ft_is_schar(*str))
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (ft_is_digit(*str))
	{
		ret = ret * 10 + *str - '0';
		str++;
	}
	ret *= neg;
	return (ret);
}

int		ft_is_digit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int		ft_is_schar(char c)
{
	if (c == '\n' || c == '\v' || c == '\t' || c == '\r' || c == '\f')
		return (1);
	if (c == '+' || c == '-' || c == ' ')
		return (1);
	return (0);
}
