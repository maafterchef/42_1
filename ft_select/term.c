/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:36:53 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/12 18:49:44 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_list			**g_list;
extern struct termios	*g_term;

void	ft_return_term(struct termios *term)
{
	ft_clear_term();
	term->c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, term);
}

void	ft_restore_term(int sig)
{
	(void)sig;
	ft_free(NULL, g_list);
	ft_return_term(g_term);
	exit(0);
}

void	ft_reprint_list(int sig)
{
	t_dim	*size;
	int		msg;

	(void)sig;
	msg = 0;
	size = NULL;
	while (!size)
		size = ft_get_size(g_list);
	ft_print_list(g_list, size);
	tputs(tgetstr("ho", NULL), 1, tputs_putchar);
	ft_repos_cursor(g_list, size);
	free(size);
}

void	ft_clear_term(void)
{
	tputs(tgetstr("ho", NULL), 1, tputs_putchar);
	tputs(tgetstr("cd", NULL), 1, tputs_putchar);
}

void	ft_repos_cursor(t_list **start, t_dim *size)
{
	t_list	*tmp;
	int		count;
	int		nb;

	tmp = *start;
	nb = 0;
	count = 0;
	while (tmp->next != *start)
	{
		if (tmp->curs == 1)
			tputs(tgoto(CM, count *size->col, nb), 1, tputs_putchar);
		if (nb++ >= size->line)
		{
			nb = 0;
			count++;
		}
		tmp = tmp->next;
	}
	if (tmp->curs == 1)
		tputs(tgoto(CM, count *size->col, nb), 1, tputs_putchar);
}
