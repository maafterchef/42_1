/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:34:10 by mlingels          #+#    #+#             */
/*   Updated: 2013/11/26 11:49:46 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*dest;
	const char	*src;

	dest = s1;
	src = s2;
	while (n--)
		*dest++ = *src++;
	return (s1);
}
