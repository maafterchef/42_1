/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:05:43 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/05 05:04:23 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh3.h"

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

t_hist		*ft_create_hist(void)
{
	t_hist	*hist;

	hist = (t_hist *)malloc(sizeof(t_hist));
	if (hist)
	{
		hist->str = NULL;
		hist->next = NULL;
		return (hist);
	}
	return (NULL);
}

void		ft_print_hist(t_hist **start)
{
	t_hist	*tmp;

	tmp = *start;
	while (tmp)
	{
		ft_putendl(tmp->str);
		tmp = tmp->next;
	}
}

void		ft_save_history(char *str, t_hist **start)
{
	t_hist	*tmp;
	char	*new;

	tmp = *start;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->str)
	{
		tmp->next = ft_create_hist();
		tmp = tmp->next;
	}
	new = (char *)malloc(ft_strlen(str));
	(void)ft_strcpy(new, str);
	tmp->str = new;
}
