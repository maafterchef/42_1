/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:04:32 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/06 11:41:12 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

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
