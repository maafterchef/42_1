/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:34:18 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/06 11:32:06 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*dest;
	const char	*src;

	dest = s1;
	src = s2;
	if (src < dest && dest < (src + n))
	{
		src += n;
		dest += n;
		while (n > 0)
		{
			*--dest = *--src;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*dest++ = *src++;
			n--;
		}
	}
	return (s1);
}
