/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 13:13:24 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/09 14:42:41 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static void	ft_put_token(t_grid *game, int col)
{
	int		i;

	i = game->lines - 1;
	while (i >= 0 && GRID[i][col] != '.')
		i--;
	if (i >= 0)
		GRID[i][col] = 'O';
}

static int	ft_find_highest_val(int *tab, int size)
{
	int		ret;
	int		i;

	i = 1;
	ret = 0;
	while (i < size)
	{
		if (tab[i] > tab[ret])
			ret = i;
		i++;
	}
	return (ret);
}

static int	ft_find_best_move(t_grid *game)
{
	int		*tab;
	int		i;

	tab = (int *)malloc(sizeof(int) * game->cols);
	if (tab)
	{
		i = 0;
		while (i < game->cols)
		{
			tab[i] = ft_find_value_row(game, i);
			i++;
		}
		i = ft_find_highest_val(tab, game->cols);
		free(tab);
		return (i);
	}
	return (0);
}

void		ft_play_computer(t_grid *game)
{
	if (game->tokens == (game->lines * game->cols))
		ft_put_token(game, (game->cols / 2));
	else
		ft_put_token(game, ft_find_best_move(game));
	game->tokens--;
}
