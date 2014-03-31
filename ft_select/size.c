/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 18:54:54 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/12 17:50:27 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_select.h"

static t_dim	*ft_list_size(t_list **li)
{
	t_dim	*list;
	t_list	*tmp;
	int		len;

	list = (t_dim *)malloc(sizeof(t_dim));
	if (!list)
		return (NULL);
	list->col = 0;
	list->nb = 1;
	list->line = 0;
	len = 0;
	tmp = *li;
	while (tmp->next != *li)
	{
		list->nb++;
		if ((len = ft_strlen(tmp->arg)) > list->col)
			list->col = len;
		tmp = tmp->next;
	}
	if ((len = ft_strlen(tmp->arg)) > list->col)
		list->col = len;
	return (list);
}

static int	ft_is_valid_size(t_dim **term, t_dim *list)
{
	static int	msg = 0;

	if (list->col > (*term)->col)
	{
		free(*term);
		*term = NULL;
	}
	if (((*term)->col * (*term)->nb) < (list->nb * (list->col + 2)))
	{
		free(*term);
		*term = NULL;
	}
	if (!(*term))
	{
		if (msg == 0)
		{
			ft_clear_term();
			msg = 1;
		}
		return (0);
	}
	else
		msg = 0;
	return (1);
}

t_dim	*ft_get_size(t_list **li)
{
	t_dim		*term;
	t_dim		*list;
	char		term_buff[2048];

	tgetent(term_buff, getenv("TERM"));
	term = (t_dim *)malloc(sizeof(t_dim));
	list = ft_list_size(li);
	term->col = tgetnum("co");
	term->nb = tgetnum("li");
	if (ft_is_valid_size(&term, list))
	{
		term->nb = term->col / ((list->col) + 2);
		term->col = list->col + 2;
		term->line = list->nb / term->nb + 1;
	}
	free(list);
	return (term);
}
