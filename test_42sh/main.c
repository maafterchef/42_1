/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 23:52:15 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/05 06:40:49 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char			*ft_add_input(char *c, char *buff, int pos)
{
	char			*new;
	size_t			len;

	len = ft_strlen(buff);
	new = (char *)malloc(sizeof(char) * (len + 2));
	if (new)
	{
		(void)ft_strncpy(new, buff, pos);
		new[pos] = *c;
		(void)ft_strncpy(&new[pos + 1], &buff[pos], len - pos);
		new[len + 1] = 0;
	}
	return (new);
}

static void			ft_get_input(char *c, char **buff, t_pos *pos, t_hist **his)
{
	int				i;
	static t_func	list[] =
	{
		{UP, &ft_up},
		{DOWN, &ft_down},
		{RIGHT, &ft_right},
		{LEFT, &ft_left},
		{DEL, &ft_del},
		{BCKSPCE, &ft_del},
	};

	i = 0;
	while (i < 6)
	{
		if (*(unsigned int *)c == list[i].name)
		{
			list[i].ptr(pos, buff, his);
			return ;
		}
		i++;
	}
	*buff = ft_add_input(c, *buff, pos->pos_x);
	pos->cmd_len++;
	ft_print_str(*buff, pos);
}

static char 		*ft_read_cmd(t_pos *pos, t_hist **his)
{
	char			*buff;
	char			*c;

	c = ft_strnew(5);
	ft_bzero(c, 5);
	buff = NULL;
	while (*(unsigned int *)c != 10)
	{
		if (c[0])
			ft_get_input(c, &buff, pos, his);
		ft_bzero(c, 5);
		read(0, c, 5);
	}
	ft_putchar('\n');
	ft_add_to_hist(buff, his);
	return (buff);
}

int					main(void)
{
	char			*ret;
	struct termios	term;
	char			term_buff[2048];
	t_pos			*pos;
	t_hist			*his;

	his = ft_create_elem(NULL);
	pos = (t_pos *)malloc(sizeof(t_pos));
	tgetent(term_buff, getenv("TERM"));
	tcgetattr(0, &term);
	ft_set_term(&term);
	ret = NULL;
	while (ft_strcmp(ret, "exit") != 0)
	{
		if (ret)
			free(ret);
		pos->pos_x = 0;
		pos->cmd_len = 0;
		pos->ptr = NULL;
		ft_print_prompt();
		ret = ft_read_cmd(pos, &his);
	}
	ft_unset_term(&term);
	return (0);
}
