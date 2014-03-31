/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 16:42:19 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/26 20:45:02 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

int			main(void)
{
	char	*buff;
	int		player;

	get_next_line(0, &buff);
	player = buff[10] - 48;
	while (1)
		ft_play_filler(player);
	return (0);
}

void		ft_play_filler(int player)
{
	char	**map;

	map = ft_read_map();
	ft_read_piece(map, player);
	ft_free_tab(&map);
}

void		ft_place_piece(char **piece, t_dim *size, char **map, int player)
{
	t_dim	*pt;

	pt = find_up_spot(map, size, player);
	while (map[pt->line])
	{
		while (map[pt->line][pt->col])
		{
			if (ft_valid_pt(size, map, pt))
			{
				if (ft_try_spot(map, pt, piece, player) != 1)
					pt->col++;
				else
				{
					ft_putanswer(&pt);
					return ;
				}
			}
			else
				pt->col++;
		}
		pt->line++;
		pt->col = 0;
	}
	pt->line = 0;
	ft_putanswer(&pt);
}

void		ft_read_piece(char **map, int player)
{
	t_dim	size;
	char	*buff;
	int		i;
	char	**piece;

	get_next_line(0, &buff);
	i = 5;
	size.line = ft_atoi(&buff[i]);
	while (buff[i] != ' ')
		i++;
	size.col = ft_atoi(&buff[i]);
	piece = (char **)malloc(sizeof(char *) * (size.line + 1));
	i = 0;
	while (i < size.line)
	{
		get_next_line(0, &buff);
		piece[i++] = ft_strsub(buff, 0, size.col);
	}
	ft_place_piece(piece, &size, map, player);
	ft_free_tab(&piece);
}

char		**ft_read_map(void)
{
	t_dim	size;
	int		i;
	int		gap;
	char	*buff;
	char	**map;

	get_next_line(0, &buff);
	i = 8;
	size.line = ft_atoi(&buff[i]);
	buff = ft_strchr(&buff[i], ' ');
	size.col = ft_atoi(&buff[1]);
	map = (char **)malloc(sizeof(char *) * (size.line + 1));
	get_next_line(0, &buff);
	i = 0;
	while (buff[i] == ' ')
		i++;
	gap = i;
	i = 0;
	while (i < size.line)
	{
		get_next_line(0, &buff);
		map[i++] = ft_strsub(buff, gap, size.col);
	}
	map[i] = 0;
	return (map);
}
