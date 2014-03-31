/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:49:04 by mlingels          #+#    #+#             */
/*   Updated: 2013/11/25 10:26:42 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		len;
	size_t		len2;
	char		*ptr;
	const char	*ptr2;

	ptr = s1;
	ptr2 = s2;
	len2 = ft_strlen(ptr2);
	len = ft_strlen(ptr);
	if (len2 < n)
		n = len2;
	ft_memcpy(&ptr[len], s2, n);
	ptr[len + n] = '\0';
	return (s1);
}
