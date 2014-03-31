/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:29:06 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/06 11:29:41 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

static long	ft_abs(long);

static long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	buff;

	len = 1;
	buff = (long)n;
	if (n < 0)
		len++;
	while ((n = n / 10) != 0)
		len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (buff < 0)
		str[0] = '-';
	buff = ft_abs(buff);
	if (buff == 0)
		str[len - 1] = '0';
	while (buff != 0)
	{
		str[--len] = ((buff % 10) + 48);
		buff = buff / 10;
	}
	return (str);
}
