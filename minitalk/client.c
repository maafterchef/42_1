/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 19:52:38 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/08 19:54:40 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <libft.h>
#include <stdlib.h>

static void	ft_ctos(char c, int pid)
{
	int		i;

	i = 128;
	while (i > 0)
	{
		if (c / i)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				exit(-1);
				ft_putendl_fd("error : could not reach server", 2);
			}
			c = c - i;
		}
		else if (kill(pid, SIGUSR2) == -1)
		{
			ft_putendl_fd("error : could not reach server", 2);
			exit(-1);
		}
		usleep(50);
		i = i / 2;
	}
}

int			main(int ac, char **av)
{
	int		pid;
	int		i;

	if (ac != 3)
		ft_putendl_fd("error: bad arguments\nusage: client pid str", 2);
	else
	{
		if ((pid = ft_atoi(av[1])) <= 0)
		{
			ft_putendl_fd("error : invalid pid", 2);
			exit(-1);
		}
		i = 0;
		while (av[2][i])
		{
			ft_ctos(av[2][i], pid);
			i++;
		}
		ft_ctos(0, pid);
	}
	return (0);
}

