/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 13:54:01 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/26 20:49:21 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

static t_list	*ft_create_elem(char *ptr, char c)
{
	t_list		*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new->tab = ft_strsplit(ptr);
		if (ptr)
			free(ptr);
		new->next = NULL;
		if (c == '|')
			new->pipe = 1;
		else
			new->pipe = 0;
		return (new);
	}
	return (NULL);
}

static void		ft_add_elem(t_list **start, char *ptr, char c)
{
	t_list		*tmp;
	t_list		*new;

	tmp = *start;
	while (tmp->next)
		tmp = tmp->next;
	new = ft_create_elem(ptr, c);
	if (new)
		tmp->next = new;
}

static void		ft_split_str(t_list **start, char *str)
{
	int			i;
	char		*ptr;

	i = 0;
	while (str[i] != ';' && str[i] != '\0' && str[i] != '|')
		i++;
	ptr = ft_strsub(str, 0, i);
	ft_add_elem(start, ptr, str[i]);
	if (str[i])
		ft_split_str(start, &str[i + 1]);
}

t_list			*ft_split_cmds(char *str)
{
	t_list		*start;
	int			i;
	char		*ptr;

	i = 0;
	while (str[i] != ';' && str[i] != '\0' && str[i] != '|')
		i++;
	ptr = ft_strsub(str, 0, i);
	start = ft_create_elem(ptr, str[i]);
	if (str[i])
		ft_split_str(&start, &str[i + 1]);
	return (start);
}

void			ft_run_list(t_list **start, char **env, char *path)
{
	t_list		*tmp;

	tmp = *start;
	while (tmp)
	{
		if (!ft_check_builtin(tmp->tab, env))
		{
			if (ft_check_cmd(tmp, path))
				ft_run(&tmp, env);
			else
			{
				ft_putstr_fd(tmp->tab[0], 2);
				ft_putendl_fd(": command not found.", 2);
			}
		}
		tmp = tmp->next;
	}
}
