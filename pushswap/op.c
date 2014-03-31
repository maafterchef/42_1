/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:04:25 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/27 17:20:18 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>

void	ft_s(t_list *li)
{
	ft_swap(&(li->val), &(li->next->val));
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_r(t_list **start)
{
	t_list	*tmp;

	ft_add_elem(start, (*start)->val);
	tmp = *start;
	*start = (*start)->next;
	free(tmp);
}

void	ft_rr(t_list **start)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *start;
	while (tmp != NULL)
	{
		if (tmp->next->next == NULL)
		{
			tmp2 = ft_create_elem(tmp->next->val);
			tmp2->next = *start;
			*start = tmp2;
			free(tmp->next->next);
			tmp->next = NULL;
			tmp = NULL;
		}
		else
			tmp = tmp->next;
	}
}

void	ft_p(t_list **start_1, t_list **start_2)
{
	t_list	*tmp;
	t_list	*tmp_free;
	
	tmp = ft_create_elem((*start_1)->val);
	tmp_free = *start_1;
	*start_1 = (*start_1)->next;
	free(tmp_free);
	tmp->next = *start_2;
	*start_2 = tmp;
}
