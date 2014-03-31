/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:03:52 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/31 16:10:22 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh3.h"

void	ft_env(char **tab, char **env)
{
	int	i;

	(void)tab;
	i = 0;
	while (env[i])
		ft_putendl(env[i++]);
}

void	ft_exit(char **tab, char **env)
{
	(void)tab;
	(void)env;
	struct termios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag |= (ECHO | ICANON);
	tattr.c_oflag |= (OPOST);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	exit(0);
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
