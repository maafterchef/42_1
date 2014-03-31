/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:50:06 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/26 17:17:57 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_1;
	size_t	len_2;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	str = (char *)malloc(len_1 + len_2 + 1);
	if (str)
	{
		(void)ft_strncpy(str, s1, len_1);
		(void)ft_strncpy(&str[len_1], s2, len_2);
		str[len_1 + len_2] = 0;
		return (str);
	}
	return (NULL);
}
