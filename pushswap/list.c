/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:28:38 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/27 16:27:24 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>

t_list	*ft_create_elem(int nb)
{
	t_list	*li;

	li = (t_list *)malloc(sizeof(t_list));
	if (li)
	{
		li->val = nb;
		li->next = NULL;
	}
	return (li);
}

void	ft_add_elem(t_list **start, int nb)
{
	t_list	*li;
	t_list	*tmp;

	li = ft_create_elem(nb);
	tmp = *start;
	if (li)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = li;
	}
}

void	ft_print_list(t_list *start)
{
	if (start)
	{
		ft_putnbr(start->val);
		ft_putchar(' ');
		ft_print_list(start->next);
	}
}
