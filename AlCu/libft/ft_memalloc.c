/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:49:56 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/06 11:30:58 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*zone;

	if (size == 0)
		return (NULL);
	zone = (void *)malloc(size);
	if (zone)
		return (zone);
	return (NULL);
}
