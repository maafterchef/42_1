/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 21:02:52 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/15 22:04:06 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

char	*ft_find_path(char **str)
{
	int		i;
	char	*ptr;

	ptr = *str;
	i = ft_strlen(ptr);
	i--;
	while (i >= 0 && ptr[i] != '/')
		i--;
	if (i > 0)
	{
		ptr = ft_strsub(*str, 0, i);
		*str = ft_strsub(*str, i + 1, ft_strlen(*str));
	}
	else
		ptr = ".";
	return (ptr);
}

int	ft_check_args(char *str, t_options *list)
{
	int	i;
	int	verif;

	str++;
	while (*str)
	{
		i = 0;
		verif = 0;
		while (i < OPT_NB)
		{
			if (list[i].name == *str)
			{
				list[i].set = 1;
				verif = 1;
			}
			i++;
		}
		if (verif == 0)
		{
			ft_opt_error(*str, list);
			return (0);
		}
		str++;
	}
	return (1);
}
