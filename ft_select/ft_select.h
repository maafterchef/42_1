/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 16:56:41 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/05 05:23:13 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <termcap.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <libft.h>
# include <signal.h>

# define CM tgetstr("cm", NULL)
# define UP 4283163
# define LEFT 4479771
# define RIGHT 4414235
# define DOWN 4348699
# define SPACE 32
# define DEL 127
# define BACKSPACE 2117294875

typedef struct	s_dim
{
	int			col;
	int			nb;
	int			line;
}				t_dim;

typedef struct	s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	char			*arg;
	int				set;
	int				curs;
}				t_list;

typedef struct	s_func
{
	unsigned int	name;
	void			(*ptr)(t_list **, t_list **);
}				t_func;

t_list 			**g_list;
struct termios	*g_term;

int		tputs_putchar(int c);

t_list	*ft_get_list(int ac, char **av);
void	ft_print_list(t_list **li, t_dim *size);
void	ft_print_choice(t_list *tmp);

void	ft_read_choices(t_list **arg_list);
int		ft_continue(char *buff);
void	ft_print_arg(char *str);
int		ft_is_end(char *buff, t_list **start);

t_dim	*ft_get_size(t_list **li);

void	ft_return_term(struct termios *term);
void	ft_restore_term(int sig);
void	ft_reprint_list(int sig);
void	ft_clear_term(void);
void	ft_repos_cursor(t_list **start, t_dim *size);

void	ft_up(t_list **start, t_list **tmp);
void	ft_down(t_list **start, t_list **tmp);
void	ft_left(t_list **start, t_list **tmp);
void	ft_right(t_list **start, t_list **tmp);

void	ft_del(t_list **start, t_list **tmp);
void	ft_space(t_list **start, t_list **tmp);

void	ft_stop(int sig);
void	ft_continue_program(int sig);

void	ft_free(t_dim *size, t_list **start);

#endif /* !FT_SELECT_H */
