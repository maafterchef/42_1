/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:40:31 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/09 14:38:43 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# define GRID game->grid
# define BUFF_SIZE 8

# include <libft.h>
# include <stdlib.h>
# include <time.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

typedef struct		s_grid
{
	int				lines;
	int				cols;
	char			**grid;
	int				tokens;
}					t_grid;

int		get_next_line(int fd, char **ptr);

/* ERRORS.C */
void	ft_error(int err);

/* PLAY.C */
void	ft_play_puissance4(t_grid *game);
void	ft_get_player(int *player, t_grid *game);
int		ft_invalid_col(t_grid *game, int col);
void	ft_play_player(t_grid *game);
int		ft_valid_game(t_grid *game);

/* GRID.C */
int		ft_create_grid(t_grid *game);
void	ft_print_grid(t_grid *game);

/* PRINT.C */
void	ft_print_first_line(int col);

/* WINNER.C */
int		ft_winner_hor(t_grid *game, int i, int j);
int		ft_winner_ver(t_grid *game, int i, int j);
int		ft_winner_diag(t_grid *game, int i, int j);
int		ft_winner(t_grid *game, int i, int j);

/* COMPUTER.C */
void	ft_play_computer(t_grid *game);

/* VALUE.C */
int		ft_find_value_row(t_grid *game, int col);

/* VALUES.C */
int		ft_get_ver_value(t_grid *game, int line, int col);
int		ft_get_hor_value(t_grid *game, int line, int col);
int		ft_get_diag_value(t_grid *game, int line, int col);

/* FREE.C */
void	ft_free(t_grid *game);

#endif /* !PUISSANCE4_H */
