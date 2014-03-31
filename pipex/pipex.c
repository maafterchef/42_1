/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:14:50 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/02 18:39:45 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

extern char **environ;

static int	fork_father(char **env, char **av, int *pfds)
{
	char	**arg;
	int		fd;

	if (av[4][0] == '\0')
		fd = 1;
	else
	{
		if ((fd = open(av[4], O_WRONLY)) == -1)
			return (check_errors(0));
	}
	if (dup2(fd, 1) == -1)
		return (check_errors(1));
	if (close(pfds[1]) == -1)
		return (check_errors(2));
	if (dup2(pfds[0], 0) == -1)
		return (check_errors(1));
	if ((arg = ft_read_cmd(av[3])) == NULL)
		return (-1);
	if (execve(get_path(env, arg[0]), arg, NULL) == -1)
		return (check_errors(3));
	free_tab(&arg);
	return (0);
}

static int	fork_child(char **env, char **av, int *pfds)
{
	char	**arg;
	int		fd;

	if (av[1][0] == '\0')
		fd = 0;
	else
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (check_errors(0));
	}
	if (dup2(fd, 0) == -1)
		return (check_errors(1));
	if (close(pfds[0]) == -1)
		return (check_errors(2));
	if (dup2(pfds[1], 1) == -1)
		return (check_errors(1));
	if ((arg = ft_read_cmd(av[2])) == NULL)
		return (-1);
	if (execve(get_path(env, arg[0]), arg, NULL) == -1)
		return (check_errors(3));
	free_tab(&arg);
	return (0);
}

static int	ft_run(char **env, char **av)
{
	int		pfds[2];
	int		father;

	if (pipe(pfds) == -1)
		return (check_errors(4));
	father = fork();
	if (father < 0)
		return (check_errors(5));
	if (!father)
	{
		if (fork_child(env, av, pfds) == -1)
			return (-1);
	}
	else
	{
		if (fork_father(env, av, pfds) == -1)
			return (-1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	int		fd;

	if (ac != 5)
		return (check_errors(7));
	if (av[2][0] == '\0' || av[3][0] == '\0')
		return (check_errors(7));
	if (check_input(environ, av[1]) == -1)
		return (-1);
	if (av[4][0] != '\0')
		fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (check_output(environ, av[4]) == -1)
	{
		close(fd);
		return (check_errors(2));
	}
	if (close(fd) == -1)
		return (check_errors(2));
	if (ft_run(environ, av) == -1)
		return (-1);
	return (0);
}
