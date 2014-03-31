/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:36:07 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/01 22:11:05 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	ft_memcpy((s1 + ft_strlen(s1)), s2, (ft_strlen(s2) + 1));
	return (s1);
}
