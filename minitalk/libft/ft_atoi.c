/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:00:45 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/22 09:47:10 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_is_space(char c)
{
	if (c == '\n' || c == '\v' || c == '\t' || c == '\r' || c == '\f')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int			result;
	int			sign;
	const char	*ptr;

	result = 0;
	sign = 1;
	ptr = str;
	while (ft_is_space(*ptr))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (ft_isdigit(*ptr))
	{
		result = result * 10 + *ptr - '0';
		ptr++;
	}
	result = result * sign;
	return (result);
}
