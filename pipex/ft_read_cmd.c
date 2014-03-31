/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:38:26 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/31 19:22:36 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

static int	ft_get_nb(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str)
		{
			i++;
			while (*str != ' ' && *str)
				str++;
		}
	}
	return (i);
}

static char	*ft_split(char **str)
{
	char	*ret;
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	while (**str == ' ')
		(*str)++;
	ptr = *str;
	while (**str != ' ' && **str)
		(*str)++;
	len = *str - ptr;
	ret = (char *)malloc(len + 1);
	while (len--)
	{
		ret[i] = *ptr;
		i++;
		ptr++;
	}
	ret[i] = 0;
	if (**str)
		(*str)++;
	return (ret);
}

char		**ft_read_cmd(char *str)
{
	char	**arg;
	int		nb_arg;
	int		i;

	i = 0;
	nb_arg = ft_get_nb(str);
	if (nb_arg == 0)
	{
		ft_puterror("pipex : ", "invalid number of arguments\n");
		ft_puterror("Usage : ", "file1 \"cmd1\" \"cmd2\" file2\n");
		return (NULL);
	}
	arg = (char **)malloc(sizeof(char *) * (nb_arg + 1));
	if (!arg)
		return (NULL);
	while (*str)
	{
		arg[i] = ft_split(&str);
		i++;
	}
	arg[nb_arg] = 0;
	return (arg);
}
