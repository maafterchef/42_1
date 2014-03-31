/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 14:43:28 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/22 09:50:18 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * TODOLIST
 * - Free everything
 * - recode cd / ...
 */

extern char	**environ;

static char	*ft_joinstr(char *name, char *env, int *len)
{
	char			*str;
	size_t			len_2;
	int				i;
	size_t			j;

	i = *len;
	if (!env[*len])
		return (NULL);
	while (env[*len] != ':' && env[*len])
		(*len)++;
	j = *len - i;
	(*len)++;
	len_2 = ft_strlen(name);
	str = (char *)malloc(j + len_2 + 2);
	if (str)
	{
		(void)ft_strncpy(str, &env[i], j);
		str[j] = '/';
		(void)ft_strncpy(&str[j + 1], name, len_2);
		str[j + len_2 + 1] = 0;
		return (str);
	}
	return (NULL);
}

static int	ft_run_cmd(char *name, char **av)
{
	static char	*env;
	char		*str;
	int			i;
	pid_t		father;

	i = 0;
	if (!env)
		env = ft_get_line(*environ);
	str = ft_joinstr(name, env, &i);
	while (access(str, X_OK) && str)
	{
		free(str);
		str = ft_joinstr(name, env, &i);
	}
	if (!str)
		return (0);
	father = fork();
	if (father > 0)
	{
		wait(&father);
		return (1);
	}
	if (father == 0)
		execve(str, av, NULL);
	return (1);
}

static int	ft_check_args(char *ptr)
{
	int	i;

	i = 0;
	while (*ptr == ' ')
		ptr++;
	while (*ptr != ' ' && *ptr)
		ptr++;
	while (*ptr)
	{
		while (*ptr == ' ')
			ptr++;
		if (*ptr)
		{
			i++;
			while (*ptr != ' ' && *ptr)
				ptr++;
		}
	}
	return (i);
}

static char	**ft_get_args(char **str, char **name)
{
	char	*ptr;
	int		i;
	int		j;
	char	**arg;

	j = 1;
	ptr = *str;
	i = ft_check_args(ptr);
	*name = ft_cpy(str);
	if (i == 0)
		arg = (char **)malloc(sizeof(char *) * 2);
	else
		arg = (char **)malloc(sizeof(char *) * (i + 2));
	arg[0] = *name;
	while (**str)
	{
		arg[j] = ft_cpy(str);
		j++;
	}
	arg[i + 1] = 0;
	return (arg);
}

int	main(void)
{
	char	*ptr;
	char	*name;
	char	**arg;

	while (1)
	{
		write(1, "$>", 2);
		get_next_line(0, &ptr);
		if (ft_strcmp(ptr, "exit") == 0)
			return (0);
		arg = ft_get_args(&ptr, &name);
		if (!ft_check_builtin(arg))
		{
			if (!ft_run_cmd(name, arg))
			{
				ft_putstr_fd(name, 2);
				ft_putendl_fd(": command not found", 2);
			}
		}
		free(name);
		ft_free(arg);
	}
	return (0);
}
