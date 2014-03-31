/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:56:35 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/27 19:22:15 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include <libft.h>

int		ft_check_builtin(char **arg)
{
	int				i;
	static t_func	list[] =
	{
		{"cd", &ft_cd},
	};

	i = 0;
	while (i < 1)
	{
		if (!ft_strcmp(list[i].name, arg[0]))
		{
			list[i].ptr(arg);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_cd(char **arg)
{
	(void)arg;
}
