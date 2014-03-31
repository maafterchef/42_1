/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:05:55 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/29 11:06:53 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh3.h"

static int	ft_count_pipes(t_list *tmp)
{
	int		nb;

	nb = 0;
	while (tmp)
	{
		if (tmp->pipe)
			nb++;
		tmp = tmp->next;
	}
	return (nb);
}

static void	ft_pipe(t_list **tmp, char **env, int nb)
{
	int		pfds[2 * nb];
	int		i;
	int		j;
	pid_t	pid;

	i = 0;
	while (i++ < nb)
		pipe(pfds + i * 2);
	j = 0;
	while (j++ < nb)
	{
		pid = fork();
		if (pid == 0)
		{
			if (j != 0)
				dup2(pfds[(j - 1) * 2], 0);
			if ((*tmp)->pipe == 1)
				dup2(pfds[j * 2 + 1], 1);
			i = 0;
			while (i++ < 2 * nb)
				close(pfds[i]);
			execve((*tmp)->tab[0], (*tmp)->tab, env);
		}
		*tmp = (*tmp)->next;
	}
}

void	ft_run(t_list **tmp, char **env)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait(&father);
		return ;
	}
	if (father == 0)
	{
		if ((*tmp)->pipe == 1)
			ft_pipe(tmp, env, ft_count_pipes(*tmp));
		else
			execve((*tmp)->tab[0], (*tmp)->tab, env);
	}
}
