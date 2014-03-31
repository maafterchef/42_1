/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:01:49 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/12 18:35:22 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern struct termios	*g_term;

void	ft_stop(int sig)
{
	char	cp[2] = {g_term->c_cc[VSUSP], 0};

	(void)sig;
	ft_return_term(g_term);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

void	ft_continue_program(int sig)
{
	struct termios	term;
	char			term_buff[2048];
	t_dim			*size;

	(void)sig;
	size = NULL;
	tgetent(term_buff, getenv("TERM"));
	if (!getenv("TERM"))
	{
		ft_putendl_fd("No valid environnement found", 2);
		exit(0);
	}
	tcgetattr(0, &term);
	g_term = &term;
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term);
	while (!size)
		size = ft_get_size(g_list);
	ft_print_list(g_list, size);
	ft_repos_cursor(g_list, size);
	signal(SIGTSTP, &ft_stop);
}
