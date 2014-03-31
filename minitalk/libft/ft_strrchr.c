/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:04:32 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/12 18:57:37 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	const char	*res;
	int			check;

	check = 0;
	ptr = s;
	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
		{
			res = ptr;
			check = 1;
		}
		ptr++;
	}
	if (c == '\0')
	{
		res = ptr;
		check = 1;
	}
	if (check == 1)
		return ((void *)res);
	return (NULL);
}
