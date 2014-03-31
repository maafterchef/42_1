/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:24:29 by mlingels          #+#    #+#             */
/*   Updated: 2013/11/25 10:32:05 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char		*str;
	const char	*str2;

	str2 = s2;
	str = s1;
	while (n > 0 && *str2)
	{
		*str = *str2;
		str++;
		str2++;
		n--;
	}
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
	return (s1);
}
