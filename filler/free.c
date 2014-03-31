/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 19:59:46 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/26 20:05:54 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_free_tab(char ***tmp)
{
	int		i;

	i = 0;
	if (!tmp || !*tmp)
		return ;
	while ((*tmp)[i])
	{
		ft_strdel(&(*tmp)[i]);
		i++;
	}
	ft_memdel((void **)tmp);
}
