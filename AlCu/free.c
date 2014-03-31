/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 14:37:07 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/09 14:38:12 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void		ft_free(t_grid *game)
{
	int		i;

	i = 0;
	while (i < game->lines)
	{
		free(GRID[i]);
		GRID[i] = NULL;
		i++;
	}
	free(GRID);
	free(game);
	game = NULL;
}
