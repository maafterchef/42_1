/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:22:50 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/06 11:30:42 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void					*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;

	dest = s1;
	src = s2;
	while (n--)
	{
		*dest = *src;
		dest++;
		if (*src == (unsigned char)c)
			return ((void *)dest);
		src++;
	}
	return (NULL);
}
