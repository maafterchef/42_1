/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:29:42 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/06 11:41:59 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int		ft_get_len(char const *s);

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		len;

	if (!s)
		return (NULL);
	len = ft_get_len(s);
	if (len == 1)
		len = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	(void)ft_strncpy(res, s, len);
	res[len] = 0;
	return (res);
}

static int		ft_get_len(char const *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	ptr--;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while ((ptr > s) && (*ptr == ' ' || *ptr == '\t' || *ptr == '\n'))
		ptr--;
	return (ptr - s + 1);
}
