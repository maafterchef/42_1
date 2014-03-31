/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 15:52:45 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/12 18:40:13 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_select.h"

void	ft_space(t_list **start, t_list **tmp)
{
	(void)start;
	(*tmp)->curs = 0;
	(*tmp)->set = ((*tmp)->set == 0 ? 1 : 0);
	*tmp = (*tmp)->next;
	(*tmp)->curs = 1;
}

void	ft_del(t_list **start, t_list **tmp)
{
	t_list	*ptr;

	if (*tmp == (*tmp)->next)
	{
		free(*tmp);
		*tmp = NULL;
		*start = NULL;
	}
	else
	{
		if (*tmp == *start)
			*start = (*tmp)->next;
		ptr = (*tmp)->next;
		(*tmp)->prev->next = ptr;
		ptr->prev = (*tmp)->prev;
		free(*tmp);
		*tmp = ptr;
		(*tmp)->curs = 1;
	}
}
