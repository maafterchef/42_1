/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:04:32 by mlingels          #+#    #+#             */
/*   Updated: 2013/11/25 10:32:24 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	const char	*res;
	int			verif;

	verif = 0;
	ptr = s;
	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
		{
			res = ptr;
			verif = 1;
		}
		ptr++;
	}
	if (c == '\0')
	{
		res = ptr;
		verif = 1;
	}
	if (verif == 1)
		return ((void *)res);
	return (NULL);
}
