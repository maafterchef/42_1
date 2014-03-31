/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:46:22 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/24 16:09:32 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

void		ft_del_list(t_list *start)
{
	t_list	*tmp;

	if (start)
	{
		tmp = start->next;
		free(start);
		ft_del_list(tmp);
	}
}
