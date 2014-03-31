/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 16:44:10 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/26 20:46:28 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BUFF_SIZE 4096

# include <libft.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_dim
{
	int				line;
	int				col;
}					t_dim;

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

int		get_next_line(int fd, char **line);
void	ft_play_filler(int player);
char	**ft_read_map(void);
void	ft_place_piece(char **piece, t_dim *size, char **map, int player);
void	ft_read_piece(char **map, int player);
t_dim	*find_up_spot(char **map, t_dim *size, int player);
int		ft_is_mine(char c, int player);
int		ft_is_opp(char c, int player);
void	ft_putanswer(t_dim **pt);
int		ft_valid_pt(t_dim *size, char **map, t_dim *pt);
int		ft_try_spot(char **map, t_dim *pt, char **piece, int player);
void	ft_free_tab(char ***tmp);

#endif /* !FILLER_H */
