/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:04:30 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/31 15:50:43 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh3.h"

extern char	**environ;

int			main(void)
{
	char	*ptr;
	char	*path;
	char	**env;
	t_list	*li;
	t_hist	*hist;

	env = ft_cpy_env(environ);
	path = ft_get_path(env);
	hist = ft_create_hist();
	//ft_terminal_mode();
	while (1)
	{
		ft_putstr("$> ");
		get_next_line(0, &ptr);
		if (*ptr)
		{
			ft_save_history(ptr, &hist);
			li = ft_split_cmds(ptr);
			ft_run_list(&li, env, path);
			ft_del_list(li);
		}
	}
	return (0);
}

int			ft_check_builtin(char **tab, char **env)
{
	int				i;
	static t_func	list[] =
	{
		{"env", &ft_env},
		{"cd", &ft_cd},
		{"exit", &ft_exit},
		{"setenv", &ft_setenv},
		{"unsetenv", &ft_unsetenv},
	};

	i = 0;
	while (i < 5)
	{
		if (!ft_strcmp(tab[0], list[i].name))
		{
			list[i].ptr(tab, env);
			return (1);
		}
		i++;
	}
	return (0);
}

char		*ft_joincmd(char const *s1, char const *s2, size_t len)
{
	char	*str;
	size_t	len_1;

	len_1 = ft_strlen(s1);
	str = (char *)malloc(len_1 + len + 1);
	if (str)
	{
		(void)ft_strncpy(str, s2, len);
		str[len] = '/';
		(void)ft_strncpy(&str[len + 1], s1, len_1);
		str[len + len_1 + 1] = 0;
		return (str);
	}
	return (NULL);
}

char		*ft_get_path(char **env)
{
	int		i;
	size_t	len;
	char	*path;
	char	*ptr;

	path = NULL;
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH", 4))
		i++;
	if (env[i])
	{
		ptr = env[i];
		while (*ptr != '=' && *ptr)
			ptr++;
		if (!*ptr)
			return (NULL);
		ptr++;
		len = ft_strlen(ptr);
		path = (char *)malloc(sizeof(char) * (len + 1));
		(void)ft_strncpy(path, ptr, len);
	}
	return (path);
}

int			ft_check_cmd(t_list *tmp, char *path)
{
	char	*ptr;
	char	*cmd;

	if (access(tmp->tab[0], F_OK) == 0)
		return (1);
	while (path)
	{
		ptr = ft_strchr(path, ':');
		if (ptr)
			cmd = ft_joincmd(tmp->tab[0], path, ptr - path);
		else
			cmd = ft_joincmd(tmp->tab[0], path, (ft_strlen(path)));
		if (access(cmd, F_OK) == 0)
		{
			free(tmp->tab[0]);
			tmp->tab[0] = cmd;
			return (1);
		}
		free(cmd);
		if (ptr)
			path = ptr + 1;
		else
			path = NULL;
	}
	return (0);
}
