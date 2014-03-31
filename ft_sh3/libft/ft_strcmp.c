/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:44:44 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/24 13:30:27 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	len;
	int		res;

	if (!s1)
		return (-*s2);
	if (!s2)
		return (*s1);
	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	res = ft_memcmp(s1, s2, len);
	if (res > 0)
		res = 1;
	else if (res < 0)
		res = -1;
	return (res);
}
