/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 11:05:37 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/19 14:11:33 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_putoct(unsigned int d)
{
	if (d > 7)
	{
		ft_putoct(d / 8);
		ft_putnbr(d % 8);
	}
	else
		ft_putnbr(d);
}
