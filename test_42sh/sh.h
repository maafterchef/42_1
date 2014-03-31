/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 23:52:48 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/05 06:41:47 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <unistd.h>
# include <termios.h>
# include <termcap.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <signal.h>
# include <libft.h>

# define CE tgetstr("ce", NULL), 1, tputs_putchar
# define CB tgetstr("cb", NULL), 1, tputs_putchar
# define DEL 127
# define LEFT 4479771
# define RIGHT 4414235
# define UP 4283163
# define DOWN 4348699
# define BCKSPCE 2117294875
# define MOVE_LEFT tgetstr("le", NULL), 1, tputs_putchar
# define MOVE_RIGHT tgetstr("nd", NULL), 1, tputs_putchar
# define PROMPT_SIZE 7

typedef struct		s_hist
{
	char			*cmd;
	struct s_hist	*prev;
	struct s_hist	*next;
}					t_hist;

typedef struct		s_pos
{
	int				pos_x;
	int				cmd_len;
	t_hist			*ptr;
}					t_pos;

typedef struct		s_func
{
	unsigned int	name;
	void			(*ptr)(t_pos *, char **, t_hist **);
}					t_func;

void	ft_left(t_pos *pos, char **buff, t_hist **hist);
void	ft_right(t_pos *pos, char **buff, t_hist **hist);
void	ft_up(t_pos *pos, char **buff, t_hist **hist);
void	ft_down(t_pos *pos, char **buff, t_hist **hist);
void	ft_del(t_pos *pos, char **buff, t_hist **hist);

int		tputs_putchar(int c);

void	ft_print_str(char *str, t_pos *pos);
void	ft_print_prompt(void);

t_hist	*ft_create_elem(char *str);
void	ft_add_to_hist(char *str, t_hist **start);

char	*ft_del_char(int pos, char *str);
void	ft_set_term(struct termios *term);
void	ft_unset_term(struct termios *term);
#endif
