/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:06:07 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/05 10:14:48 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh3.h"

char		**ft_cpy_env(char **environ)
{
	int		i;
	size_t	len;
	char	**ret;

	i = 0;
	while (environ[i])
		i++;
	ret = (char **)malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (environ[i])
	{
		len = ft_strlen(environ[i]);
		ret[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!ret[i])
			return (NULL);
		(void)ft_strncpy(ret[i], environ[i], len);
		ret[i][len] = 0;
		i++;
	}
	return (ret);
}

void		ft_puterror(char *str, char *str2)
{
	ft_putstr(str);
	ft_putendl(str2);
}

char		*ft_joinpath(char *str, char *str2)
{
	char	*ret;
	size_t	len_1;
	size_t	len_2;

	len_1 = ft_strlen(str);
	len_2 = ft_strlen(str2);
	ret = (char *)malloc(len_1 + len_2 + 2);
	if (ret)
	{
		(void)ft_strncpy(ret, str, len_1);
		ret[len_1] = '/';
		(void)ft_strncpy(&ret[len_1 + 1], str2, len_2);
		ret[len_1 + len_2 + 1] = 0;
		return (ret);
	}
	return (NULL);
}

char		*ft_find_path(char *dir, char *str)
{
	char	*ret;
	int		i;

	ret = NULL;
	if (!ft_strcmp(str, "."))
		ret = ft_strdup(dir);
	else if (!ft_strcmp(str, ".."))
	{
		i = ft_strlen(dir) - 1;
		while (i > 0 && dir[i] != '/')
			i--;
		if (i > 0)
			ret = ft_strsub(dir, 0, i);
		else
			ret = ft_strdup("/");
	}
	return (ret);
}
