/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:55:43 by mlingels          #+#    #+#             */
/*   Updated: 2013/11/25 10:31:53 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	res;

	res = ft_memcmp(s1, s2, n);
	if (res < 0)
		res = -1;
	else if (res > 0)
		res = 1;
	return (res);
}
