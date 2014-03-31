/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 18:13:05 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/26 20:45:43 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_try_spot(char **map, t_dim *pt, char **piece, int player)
{
	int		x;
	int		y;
	int		sup;

	sup = 0;
	x = 0;
	while (piece[x])
	{
		y = 0;
		while (piece[x][y])
		{
			if (piece[x][y] == '.' && map[x + pt->line][y + pt->col] != '.')
				return (0);
			if (piece[x][y] == '*')
			{
				if (ft_is_opp(map[x + pt->line][y + pt->col], player))
					return (0);
				if (ft_is_mine(map[x + pt->line][y + pt->col], player))
					sup++;
			}
			y++;
		}
		x++;
	}
	return (sup);
}

int			ft_is_opp(char c, int player)
{
	if (player == 1)
		return (ft_is_mine(c, 2));
	else
		return (ft_is_mine(c, 1));
}

int			ft_is_mine(char c, int player)
{
	if (player == 1)
	{
		if (c == 'o' || c == 'O')
			return (1);
	}
	else if (player == 2)
	{
		if (c == 'x' || c == 'X')
			return (1);
	}
	return (0);
}

t_dim		*find_up_spot(char **map, t_dim *size, int player)
{
	t_dim	*pt;

	pt = (t_dim *)malloc(sizeof(t_dim));
	pt->line = 0;
	while (map[pt->line])
	{
		pt->col = 0;
		while (map[pt->line][pt->col])
		{
			if (ft_is_mine(map[pt->line][pt->col], player))
			{
				pt->col = (pt->col >= size->col ? pt->col - size->col : 0);
				pt->line = (pt->line >= size->line ? pt->line - size->line : 0);
				return (pt);
			}
			pt->col++;
		}
		pt->line++;
	}
	pt->line = 0;
	pt->col = 0;
	return (pt);
}

void		ft_putanswer(t_dim **pt)
{
	ft_putnbr((*pt)->line);
	ft_putchar(' ');
	ft_putnbr((*pt)->col);
	ft_putchar('\n');
	free(*pt);
}
