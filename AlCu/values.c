/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 13:43:06 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/09 14:11:34 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int	ft_get_diag2_value(t_grid *game, int line, int col)
{
	int		i;
	int		j;
	int		ret;

	ret = 1;
	j = col + 1;
	i = line - 1;
	while (i >= 0 && j < game->cols && GRID[i][j] == GRID[line][col])
	{
		i--;
		j++;
		ret++;
	}
	i = line + 1;
	j = col - 1;
	while (i < game->lines && j >= 0  && GRID[i][j] == GRID[line][col])
	{
		i++;
		j--;
		ret++;
	}
	return (ret);
}

int			ft_get_diag_value(t_grid *game, int line, int col)
{
	int		i;
	int		j;
	int		ret;
	int		tmp;

	ret = 1;
	j = col + 1;
	i = line + 1;
	while (i < game->lines && j < game->cols && GRID[i][j] == GRID[line][col])
	{
		i++;
		j++;
		ret++;
	}
	i = line - 1;
	j = col - 1;
	while (i >= 0 && j >= 0 && GRID[i][j] == GRID[line][col])
	{
		i--;
		j--;
		ret++;
	}
	tmp = ft_get_diag2_value(game, line, col);
	ret = (ret > tmp ? ret : tmp);
	return (ret);
}

int			ft_get_ver_value(t_grid *game, int line, int col)
{
	int		i;
	int		ret;

	ret = 1;
	i = line + 1;
	while (i < game->lines && GRID[i][col] == GRID[line][col])
	{
		i++;
		ret++;
	}
	i = line - 1;
	while (i >= 0 && GRID[i][col] == GRID[line][col])
	{
		i--;
		ret++;
	}
	return (ret);
}

int			ft_get_hor_value(t_grid *game, int line, int col)
{
	int		j;
	int		ret;

	ret = 1;
	j = col + 1;
	while (j < game->cols && GRID[line][j] == GRID[line][col])
	{
		j++;
		ret++;
	}
	j = col - 1;
	while (j >= 0 && GRID[line][j] == GRID[line][col])
	{
		j--;
		ret++;
	}
	return (ret);
}
