/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:30:53 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/06 11:42:36 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*ptr;

	if (!s && !f)
		return (NULL);
	res = (char *)malloc(ft_strlen(s) + 1);
	ptr = res;
	while (*s)
	{
		*ptr = (*f)(*s);
		ptr++;
		s++;
	}
	*ptr = 0;
	return (res);
}
