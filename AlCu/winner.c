/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 13:47:46 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/09 14:32:20 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int			ft_winner_hor(t_grid *game, int i, int j)
{
	if (ft_get_hor_value(game, i, j) == 4)
		return (1);
	return (0);
}

int			ft_winner_ver(t_grid *game, int i, int j)
{
	if (ft_get_ver_value(game, i, j) == 4)
		return (1);
	return (0);
}

int			ft_winner_diag(t_grid *game, int i, int j)
{
	if (ft_get_diag_value(game, i, j) == 4)
		return (1);
	return (0);
}

static void	ft_declare_winner(t_grid *game, int i, int j)
{
	ft_print_grid(game);
	if (GRID[i][j] == 'X')
		ft_putendl("VOUS AVEZ GAGNE ! FELICITATIONS !");
	else
		ft_putendl("L'ORDINATEUR A GAGNE ! DEFAITE HUMILIANTE ?");
}

int			ft_winner(t_grid *game, int i, int j)
{
	if (ft_winner_hor(game, i, j) || ft_winner_ver(game, i, j))
	{
		ft_declare_winner(game, i, j);
		return (1);
	}
	if (ft_winner_diag(game, i, j))
	{
		ft_declare_winner(game, i, j);
		return (1);
	}
	return (0);
}
