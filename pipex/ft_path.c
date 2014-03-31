/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 14:22:10 by po-conno          #+#    #+#             */
/*   Updated: 2013/12/31 19:22:19 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void		cat_path(char **str, char *cmd, char *sep)
{
	char	*tmp;

	tmp = ft_strjoin((*str), sep);
	ft_strdel(str);
	*str = ft_strjoin(tmp, cmd);
}

static char	**separate_paths(char *value, char *cmd)
{
	char	**paths;
	int		i;

	i = 0;
	paths = ft_strsplit(value, ':');
	while (paths[i])
		cat_path(&paths[i++], cmd, "/");
	return (paths);
}


char		*get_env_value(char **env, char *name)
{
	int		i;
	int		start;
	int		len;
	char	*tmp;

	i = 0;
	start = 0;
	tmp = NULL;
	while (env[i] && ft_strncmp(env[i], name, ft_strlen(name)))
		i++;
	while (env[i][start] && env[i][start] != '=')
		start++;
	len = ft_strlen(env[i]);
	tmp = ft_strsub(env[i], (start + 1), (len - start));
	return (tmp);
}

static int	check_access(char *str, char *cmd)
{
	if (access(str, F_OK) == -1)
	{
		ft_puterror(cmd, " : command not found\n");
		return (-1);
	}
	else if (access(str, X_OK) == -1)
	{
		ft_puterror(cmd, " : access denied\n");
		return (-1);
	}
	return (0);
}

char		*get_path(char **env, char *cmd)
{
	char	*value;
	char	*tmp;
	char	**path;
	int		i;

	i = 0;
	if (cmd[0] == '/')
	{
		if (!check_access(cmd, cmd))
			return (cmd);
		return (NULL);
	}
	value = get_env_value(env, "PATH");
	path = separate_paths(value, cmd);
	while (path[i] && access(path[i], F_OK) == -1)
		i++;
	if (check_access(path[i], cmd) == -1)
		return (NULL);
	if (path[i])
	{
		tmp = ft_strdup(path[i]);
		free_tab(&path);
		return (tmp);
	}
	return (NULL);
}
