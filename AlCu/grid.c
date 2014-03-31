/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:58:37 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/08 15:29:19 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static void	ft_fill(t_grid *game, int length, int line)
{
	int		i;

	i = 0;
	while (i < length)
	{
		GRID[line][i] = '.';
		i++;
	}
	GRID[line][i] = 0;
}

int			ft_create_grid(t_grid *game)
{
	int		i;

	GRID = (char **)malloc(sizeof(char *) * (game->lines + 1));
	if (!game->grid)
	{
		ft_error(1);
		return (0);
	}
	i = 0;
	while (i < game->lines)
	{
		GRID[i] = (char *)malloc(sizeof(char) * (game->cols + 1));
		if (!GRID[i])
		{
			ft_error(1);
			return (0);
		}
		ft_fill(game, game->cols, i);
		i++;
	}
	GRID[game->lines] = 0;
	return (1);
}

void		ft_print_grid(t_grid *game)
{
	int		i;
	int		j;

	i = 0;
	ft_print_first_line(game->cols);
	while (i < game->lines)
	{
		j = 0;
		while (j < game->cols)
		{
			ft_putchar(GRID[i][j]);
			if (j != game->cols - 1)
				ft_putstr(" | ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
