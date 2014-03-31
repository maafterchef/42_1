/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 18:09:59 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/27 19:33:10 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_minishell.h"
#include <stdlib.h>

char	*ft_get_line(char *str)
{
	int		i;
	char	*ret;

	i = 5;
	while (str[i])
		i++;
	ret = ft_strsub(str, 5, i - 4);
	ret[i - 5] = 0;
	return (ret);
}

char	*ft_cpy(char **str)
{
	int		i;
	int		j;
	char	*ret;

	j = 0;
	while ((*str)[j] == ' ')
		j++;
	i = j;
	while ((*str)[i] != ' ' && (*str)[i])
		i++;
	if (i - j < 0)
		return (NULL);
	ret = (char *)malloc(i - j + 1);
	if (!ret)
		return (NULL);
	(void)ft_strncpy(ret, &((*str)[j]), i - j);
	ret[i - j] = 0;
	j = 0;
	while (j++ <= i)
		(*str)++;
	return (ret);
}

void	ft_free(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		arg[i] = 0;
		free(arg[i]);
		i++;
	}
	free(arg);
}
