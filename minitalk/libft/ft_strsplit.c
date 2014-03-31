/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 10:15:14 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/24 13:26:55 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int		ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static void		ft_jump_spaces(char const **s)
{
	while (ft_is_space(**s))
		(*s)++;
}

static void		ft_jump(char const **s)
{
	while (**s && !ft_is_space(**s))
		(*s)++;
}

static size_t	ft_count_words(char const *s)
{
	size_t		nb;

	nb = 0;
	while (ft_is_space(*s))
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		while (!ft_is_space(*s) && *s)
			s++;
		nb++;
		while (ft_is_space(*s))
			s++;
	}
	return (nb);
}

char			**ft_strsplit(char const *s)
{
	char		**ret;
	const char	*ptr;
	size_t		nb;
	size_t		i;

	ret = NULL;
	if (s)
	{
		nb = ft_count_words(s);
		ret = (char **)malloc(sizeof(char *) * (nb + 1));
		if (ret)
		{
			i = 0;
			ret[nb] = NULL;
			ft_jump_spaces(&s);
			while (*s)
			{
				ptr = s;
				ft_jump(&s);
				ret[i++] = ft_strsub(ptr, 0, s - ptr);
				ft_jump_spaces(&s);
			}
		}
	}
	return (ret);
}
