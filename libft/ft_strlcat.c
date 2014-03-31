/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:01:50 by mlingels          #+#    #+#             */
/*   Updated: 2013/11/25 10:31:30 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*str1;
	const char	*str2;
	size_t		d_len;
	size_t		i;

	str1 = dst;
	str2 = src;
	i = size;
	while (i-- != 0 && *str1)
		str1++;
	d_len = str1 - dst;
	i = size - d_len;
	if (i == 0)
		return (d_len + ft_strlen(str2));
	while (*str2)
	{
		if (i != 1)
		{
			*str1++ = *str2;
			i--;
		}
		str2++;
	}
	*str1 = 0;
	return (d_len + (str2 - src));
}
