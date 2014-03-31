/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 11:35:41 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/19 14:10:51 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_puthex(unsigned int d)
{
	if (d > 15)
	{
		ft_puthex(d / 16);
		ft_puthex(d % 16);
	}
	else if (d < 10)
		ft_putnbr(d);
	else
		ft_putchar(d + 'a' - 10);
}
