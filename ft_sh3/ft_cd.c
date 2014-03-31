/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 15:12:31 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/05 10:21:03 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh3.h"

static int		ft_check_cd_env(t_cdinfos *dirs)
{
	if (dirs->pwd == -1)
	{
		ft_putendl_fd("cd: error: current pwd not found", 2);
		return (0);
	}
	if (dirs->old_pwd == -1)
	{
		ft_putendl_fd("cd: error: old pwd not found", 2);
		return (0);
	}
	if (dirs->home == -1)
	{
		ft_putendl_fd("cd: error: home not found", 2);
		return (0);
	}
	return (1);
}

static int		ft_get_dirs(t_cdinfos *dirs, char **env)
{
	int			i;

	i = 0;
	while (env[i] && (ft_strncmp(env[i], "PWD=", 4) != 0))
		i++;
	if (env[i])
		dirs->pwd = i;
	else
		dirs->pwd = -1;
	i = 0;
	while (env[i] && (ft_strncmp(env[i], "OLDPWD=", 7) != 0))
		i++;
	if (env[i])
		dirs->old_pwd = i;
	else
		dirs->old_pwd = -1;
	i = 0;
	while (env[i] && (ft_strncmp(env[i], "HOME=", 5) != 0))
		i++;
	if (env[i])
		dirs->home = i;
	else
		dirs->home = -1;
	return (ft_check_cd_env(dirs));
}

static void		ft_change_dir(char **env, t_cdinfos *dirs, char *str)
{
	free(env[dirs->old_pwd]);
	env[dirs->old_pwd] = ft_strjoin("OLDPWD=", &env[dirs->pwd][4]);
	free(env[dirs->pwd]);
	env[dirs->pwd] = ft_strjoin("PWD=", str);
	chdir(str);
	free(str);
}

static void		ft_find_dir(char *arg, char **env, t_cdinfos *dirs)
{
	char		*str;

	if (!ft_strcmp(arg, "-"))
		str = ft_strdup(&env[dirs->old_pwd][7]);
	else
	{
		if (arg[0] == '~')
			str = ft_strjoin(&env[dirs->home][5], &arg[1]);
		else if (arg[0] == '/')
			str = ft_strdup(arg);
		else if (arg[0] != '.')
			str = ft_joinpath(&env[dirs->pwd][4], arg);
		else
			str = ft_find_path(&env[dirs->pwd][4], arg);
	}
	ft_putendl(str);
	if (!access(str, F_OK))
		ft_change_dir(env, dirs, str);
	else
		ft_puterror(arg, ": directory not found");
}

void			ft_cd(char **tab, char **env)
{
	t_cdinfos	*dirs;

	dirs  = (t_cdinfos *)malloc(sizeof(t_cdinfos));
	if (!dirs)
		return ;
	if (ft_get_dirs(dirs, env))
	{
		if (!tab[1])
			ft_change_dir(env, dirs, ft_strdup(&env[dirs->home][5]));
		else if (tab[2])
			ft_putendl_fd("cd: too many arguments", 2);
		else
			ft_find_dir(tab[1], env, dirs);
	}
	if (dirs)
		free(dirs);
}
