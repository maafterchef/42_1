/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:34:15 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/22 12:54:16 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

void	ft_env(char **tab, char **env)
{
	(void)tab;
	(void)env;
	ft_putendl("env");
}

void	ft_exit(char **tab, char **env)
{
	(void)tab;
	(void)env;
	exit(0);
}

void	ft_cd(char **tab, char **env)
{
	(void)tab;
	(void)env;
	ft_putendl("cd");
}

void	ft_setenv(char **tab, char **env)
{
	(void)tab;
	(void)env;
	ft_putendl("setenv");
}

void	ft_unsetenv(char **tab, char **env)
{
	(void)tab;
	(void)env;
	ft_putendl("unsetenv");
}
