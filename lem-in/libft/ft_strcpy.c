/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:51:57 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/19 17:33:30 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	return ((char *)(ft_memcpy(s1, s2, (ft_strlen(s2) + 1))));
}
