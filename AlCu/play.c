/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:13:06 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/11 17:07:26 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void		ft_play_puissance4(t_grid *game)
{
	int		first_player;

	srand(time(NULL));
	if (ft_create_grid(game))
	{
		ft_putendl("LANCEMENT DE LA PARTIE");
		ft_putendl("Joueur 1 : X\nOrdinateur : O");
		first_player = rand() % 2;
		if (first_player == 0)
			ft_putendl("VOUS COMMENCEZ");
		else
			ft_putendl("L'ORDINATEUR COMMENCE");
		while (ft_valid_game(game))
			ft_get_player(&first_player, game);
		ft_free(game);
	}
}

int			ft_invalid_col(t_grid *game, int col)
{
	int		i;

	if (col < 0 || col >= game->cols)
		return (1);
	i = game->lines - 1;
	while (i >= 0 && GRID[i][col] != '.')
		i--;
	if (i >= 0)
	{
		GRID[i][col] = 'X';
		return (0);
	}
	else
	{
		ft_putendl("Sortie du plateau invalide. Veuillez recommencer");
		return (1);
	}
}

void		ft_play_player(t_grid *game)
{
	int		col;
	char	*ptr;
	int		ret;

	ptr = ft_strnew(5);
	ft_bzero(ptr, 5);
	col = -1;
	ft_putendl("Entrez la colonne sur laquelle vous voulez jouer");
	while (ft_invalid_col(game, col))
	{
		if (ptr[0] != 0 && (ptr[0] > '9' || ptr[0] < '0'))
			ft_putendl("Colonne non valide. Veuillez rentrer un nombre");
		ft_bzero(ptr, 5);
		ret = get_next_line(0, &ptr);
		if (ret <= 0)
			ft_putendl("Erreur lors du read, veuillez recommencer");
		else
			col = ft_atoi(ptr);
		if (col > game->lines)
			ft_putendl("Colonne non valide. Veuillez respecter les dimensions");
	}
	if (*ptr)
		free(ptr);
	game->tokens--;
}

void		ft_get_player(int *player, t_grid *game)
{
	ft_print_grid(game);
	if (*player == 0)
	{
		ft_play_player(game);
		*player = 1;
	}
	else
	{
		ft_play_computer(game);
		*player = 0;
	}
}

int			ft_valid_game(t_grid *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->lines)
	{
		j = 0;
		while (j < game->cols)
		{
			if (GRID[i][j] != '.')
			{
				if (ft_winner(game, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	if (game->tokens == 0)
	{
		ft_putendl("Plus de jetons disponibles. Fin de la partie.");
		return (0);
	}
	return (1);
}
