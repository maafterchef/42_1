/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 10:46:40 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/19 10:51:52 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_putunbr(unsigned int d)
{
	if (d > 9)
	{
		ft_putunbr(d / 10);
		ft_putnbr(d % 10);
	}
	else
		ft_putnbr(d);
}		
