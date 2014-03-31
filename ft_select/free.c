/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:42:51 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/12 18:47:08 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_free(t_dim *size, t_list **start)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (size)
	{
		free(size);
		size = NULL;
	}
	if (*start)
	{
		tmp = (*start)->next;
		while (tmp != *start)
		{
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
		}
		free(*start);
	}
}
