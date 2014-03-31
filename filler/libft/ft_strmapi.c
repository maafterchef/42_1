/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:33:30 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/06 11:42:56 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	char			*ptr;
	unsigned int	i;

	if (!s && !f)
		return (NULL);
	i = 0;
	res = (char *)malloc(ft_strlen(s) + 1);
	ptr = res;
	while (*s)
	{
		*ptr = (*f)(i, *s);
		ptr++;
		i++;
		s++;
	}
	*ptr = 0;
	return (res);
}
