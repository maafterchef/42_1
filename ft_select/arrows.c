/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 15:45:32 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/12 18:34:34 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <libft.h>

void	ft_up(t_list **start, t_list **tmp)
{
	(void)start;
	(*tmp)->curs = 0;
	*tmp = (*tmp)->prev;
	(*tmp)->curs = 1;
}

void	ft_down(t_list **start, t_list **tmp)
{
	(void)start;
	(*tmp)->curs = 0;
	*tmp = (*tmp)->next;
	(*tmp)->curs = 1;
}

void	ft_left(t_list **start, t_list **tmp)
{
	(void)start;
	(void)tmp;
}

void	ft_right(t_list **start, t_list **tmp)
{
	(void)start;
	(void)tmp;
}
