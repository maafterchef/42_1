/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 13:26:49 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/09 14:19:19 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int			ft_find_value_row(t_grid *game, int col)
{
	int		i;
	int		value;
	int		tmp;

	i = game->lines - 1;
	while (i >= 0 && GRID[i][col] != '.')
		i--;
	if (i < 0)
		return (0);
	GRID[i][col] = 'X';
	value = ft_get_ver_value(game, i, col);
	tmp = ft_get_hor_value(game, i, col);
	value = (value > tmp ? value : tmp);
	tmp = ft_get_diag_value(game, i, col);
	value = (value > tmp ? value : tmp);
	GRID[i][col] = 'O';
	tmp = ft_get_ver_value(game, i, col);
	value = (value > tmp ? value : tmp);
	tmp = ft_get_hor_value(game, i, col);
	value = (value > tmp ? value : tmp);
	tmp = ft_get_diag_value(game, i, col);
	value = (value > tmp ? value : tmp);
	GRID[i][col] = '.';
	return (value);
}
