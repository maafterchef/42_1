/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 11:07:07 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/24 16:14:41 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"


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
