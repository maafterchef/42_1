/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:30:52 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/09 13:11:19 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int			main(int ac, char **av)
{
	t_grid	*game;

	if (ac != 3)
	{
		ft_error(0);
		return (0);
	}
	game = (t_grid *)malloc(sizeof(t_grid));
	if (!game)
	{
		ft_error(1);
		return (0);
	}
	game->lines = ft_atoi(av[1]);
	game->cols = ft_atoi(av[2]);
	if (game->lines < 6 || game->cols < 7)
	{
		ft_error(2);
		return (0);
	}
	game->tokens = game->lines * game->cols;
	ft_play_puissance4(game);
	return (0);
}
