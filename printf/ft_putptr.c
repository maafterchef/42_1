/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 12:16:47 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/19 14:13:26 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_putptr(unsigned long l)
{
	unsigned long	tmp;

	if (l > 15)
	{
		ft_putptr(l / 16);
		tmp = l / 16;
		tmp = tmp * 16;
		ft_puthex(l - tmp);
	}
	else
		ft_puthex(l);
}
