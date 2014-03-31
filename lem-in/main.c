/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 14:31:03 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/21 15:09:57 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			main(void)
{
	int		ants;
	char	*ptr;
	t_room	*hill;

	get_next_line(0, &ptr);
	ants = ft_atoi(ptr);
	if (ants <= 0)
	{
		ft_putendl_fd("ERROR", 2);
		return (0);
	}
	ft_putnbr(ants);
	ft_putchar('\n');
	hill = ft_read_hill();
	//ft_solve_hill(ants, hill);
	return (0);
}
