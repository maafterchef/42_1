/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 16:45:24 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/05 10:27:06 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_list			**g_list;
extern struct termios	*g_term;

int	tputs_putchar(int c)
{
	static int	fd;

	if (!fd)
		fd = open("/dev/tty", O_WRONLY);
	write(fd, &c, 1);
	return (1);
}

static void	ft_read_cmd(char *buff, t_list **tmp, t_list **start)
{
	int				i;
	static t_func	list[] =
	{
		{UP, &ft_up},
		{LEFT, &ft_left},
		{RIGHT, &ft_right},
		{DOWN, &ft_down},
		{SPACE, &ft_space},
		{DEL, &ft_del},
		{BACKSPACE, &ft_del},
	};

	i = 0;
	while (i < 7)
	{
		if (*(unsigned int *)buff == list[i].name)
			list[i].ptr(start, tmp);
		i++;
	}
}

static int	ft_read_input(t_list **start, struct termios *term, t_dim *size)
{
	char	*buff;
	t_list	*tmp;

	tmp = *start;
	buff = ft_strnew(5);
	while (ft_continue(buff))
	{
		ft_bzero(buff, 5);
		read(0, buff, 5);
		ft_read_cmd(buff, &tmp, start);
		if (ft_is_end(buff, start))
		{
			ft_free(size, start);
			return (0);
		}
		ft_print_list(start, size);
		ft_repos_cursor(start, size);
	}
	//free(buff);
	ft_return_term(term);
	return (1);
}

static void	ft_select(int ac, char **av)
{
	t_list			*start;
	struct termios	term;
	char			term_buff[2048];
	t_dim			*size;

	size = NULL;
	start = ft_get_list(ac, av);
	g_list = &start;
	tgetent(term_buff, getenv("TERM"));
	tcgetattr(0, &term);
	g_term = &term;
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term);
	start->curs = 1;
	while (!size)
		size = ft_get_size(&start);
	ft_print_list(&start, size);
	tputs(tgetstr("ho", NULL), 1, tputs_putchar);
	if (ft_read_input(&start, &term, size))
		ft_read_choices(&start);
	ft_free(size, &start);
}

int	main(int ac, char **av)
{
	signal(SIGINT, &ft_restore_term);
	signal(SIGWINCH, &ft_reprint_list);
	signal(SIGTERM, &ft_restore_term);
	signal(SIGTSTP, &ft_stop);
	signal(SIGCONT, &ft_continue_program);
	if (!getenv("TERM"))
	{
		ft_putendl_fd("ft_select : No valid environnement found", 2);
		exit(0);
	}
	if (ac < 2)
		ft_putendl_fd("Error : invalid arguments", 2);
	else
		ft_select(ac, av);
	return (0);
}
