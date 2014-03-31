/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msgs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:14:17 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/15 21:47:35 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

void	ft_unfound_error(char *name, char *path)
{
	ft_putstr_fd("ft_ls: ", 2);
	if (ft_strcmp(path, ".") != 0)
	{
		ft_putstr_fd(path, 2);
		ft_putchar_fd('/', 2);
	}
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": No such file or directory", 2);
}

void	ft_permission_denied(char *name, char *path)
{
	ft_putstr_fd("ft_ls: ", 2);
	if (ft_strcmp(path, ".") != 0)
	{
		ft_putstr_fd(path, 2);
		ft_putchar_fd('/', 2);
	}
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": Permission denied", 2);
}

void	ft_opt_error(char c, t_options *list)
{
	int	i;

	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ft_ls [-", 2);
	i = 0;
	while (i < OPT_NB)
	{
		ft_putchar_fd(list[i].name, 2);
		i++;
	}
	ft_putendl_fd("] [file ...]", 2);
}
