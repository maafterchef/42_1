/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:43:05 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/06 11:31:31 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c1;
	const unsigned char	*c2;
	int					res;

	if (!s1 || !s2)
		return (0);
	c1 = s1;
	c2 = s2;
	while (n != 0)
	{
		if (*c1 != *c2)
		{
			res = (*c1 - *c2);
			return (res);
		}
		if (*c1 == '\0' && *c2 == '\0')
			return (0);
		c1++;
		c2++;
		n--;
	}
	return (0);
}
