/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 19:44:03 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/08 19:53:46 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static char	*ft_append(char *str, char c)
{
	int			len;
	int			i;
	char		*newstr;

	len = (str ? ft_strlen(str) : 0);
	if ((newstr = (char *)malloc((len + 2) * sizeof(char))) == NULL)
	{
		ft_putendl_fd("error : malloc error", 2);
		exit(-1);
	}
	i = 0;
	if (str)
	{
		while (str[i])
		{
			newstr[i] = str[i];
			i++;
		}
		free(str);
	}
	newstr[i] = c;
	newstr[i + 1] = 0;
	return (newstr);
}

static void	signal_handler(int sig)
{
	static int	i = 128;
	static char	c = 0;
	static char	*str;

	if (sig == SIGUSR1)
	{
		c = c + i;
		i = i / 2;
	}
	if (sig == SIGUSR2)
		i = i / 2;
	if (i == 0)
	{
		i = 128;
		if (c == 0)
		{
			ft_putendl(str);
			free(str);
			str = 0;
		}
		else
			str = ft_append(str, c);
		c = 0;
	}
}

int			main(void)
{
	pid_t		pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, &signal_handler);
		signal(SIGUSR2, &signal_handler);
	}
	return (0);
}
