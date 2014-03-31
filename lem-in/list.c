/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 16:20:42 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/21 16:42:21 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_new_room(t_room **start, char *name, int spe)
{
	t_room	*tmp;
	t_room	*new;

	if (!*start)
	{
		*start = (t_room *)malloc(sizeof(t_room));
		(*start)->name = name;
		(*start)->spe = spe;
	}
	else
	{
		tmp = *start;
		while (tmp->next)
			tmp = tmp->next;
		new = (t_room *)malloc(sizeof(t_room));
		new->name = name;
		new->spe = spe;
		tmp->next = new;
	}
}
