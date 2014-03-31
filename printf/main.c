/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 11:14:57 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/22 20:14:25 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>

int		main(void)
{
	int i;

	i = printf("%#u\n", 1);
	printf("Printf : %d\n", i);
	i = ft_printf("%#x\n", -1);
	ft_putstr("Ft_printf : ");
	ft_putnbr(i);
	ft_putstr("\n");
	return (0);
}
