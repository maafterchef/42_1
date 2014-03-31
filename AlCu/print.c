/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:22:32 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/07 21:44:15 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void			ft_print_first_line(int col)
{
	int			margin;

	margin = 0;
	while (margin < col)
	{
		ft_putnbr(margin % 10);
		if (margin != (col - 1))
			ft_putstr("   ");
		margin++;
	}
	ft_putchar('\n');
}
