
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:55:58 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/01 21:59:38 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_get_nbwords(char const *s, char c)
{
	int			nb;
	const char	*ptr;

	if (c == '\0')
		return (1);
	ptr = s;
	nb = 0;
	while (*ptr == c)
		ptr++;
	while (*ptr)
	{
		if (*ptr != c)
		{
			nb++;
			ptr++;
			while (*ptr != c && *ptr)
				ptr++;
		}
		while (*ptr == c)
			ptr++;
	}
	return (nb);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str_tab;
	int			nb_words;
	int			i;
	char const	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_get_nbwords(s, c);
	str_tab = (char **)malloc(nb_words + 2);
	if (!str_tab)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		ptr = s;
		while (*ptr != c && *ptr)
			ptr++;
		if (ptr != s)
		{
			str_tab[i] = (char *)malloc((ptr - s) + 1);
			(void)ft_strncpy(str_tab[i], s, (ptr - s));
			str_tab[i][ptr - s] = 0;
			i++;
		}
		s = ptr;
	}
	str_tab[i] = '\0';
	str_tab[i + 1] = '\0';
	return (str_tab);
}
