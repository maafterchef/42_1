/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:11:06 by mlingels          #+#    #+#             */
/*   Updated: 2013/11/25 10:32:36 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	len = ft_strlen(s2);
	if (len == 0)
		return ((void *)s1);
	while (*s1)
	{
		if (ft_memcmp(s1, s2, len) == 0)
			return ((void *)s1);
		s1++;
	}
	return (NULL);
}
