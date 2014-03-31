/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 19:28:50 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/26 19:58:33 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_valid_pt(t_dim *size, char **map, t_dim *pt)
{
	int	i;

	if ((size->col + pt->col) >= (int)ft_strlen(map[pt->line]))
		return (0);
	i = pt->line;
	while (i < size->line)
	{
		if (map[i] == 0)
			return (0);
		i++;
	}
	return (1);
}
