/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:41:09 by mlingels          #+#    #+#             */
/*   Updated: 2013/11/21 14:15:43 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
		return (NULL);
	str = (char *) malloc((size + 1) * sizeof(*str));
	ft_bzero(str, (size + 1));
	return (str);
}
