/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 00:28:54 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/12 17:13:35 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <libft.h>
#include <stdlib.h>

static t_list	*ft_create_elem(char *str)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new->arg = str;
		new->set = 0;
		new->curs = 0;
		new->prev = new;
		new->next = new;
	}
	return (new);
}

static void		ft_add_to_list(t_list **start, char *str)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *start;
	while (tmp->next != *start)
		tmp = tmp->next;
	new = ft_create_elem(str);
	if (new)
	{
		new->next = *start;
		new->prev = tmp;
		tmp->next = new;
		(*start)->prev = new;
	}
}

t_list	*ft_get_list(int ac, char **av)
{
	t_list	*arg_list;
	int		i;

	if (ac <= 1)
		return (NULL);
	i = 1;
	arg_list = ft_create_elem(av[i]);
	i++;
	while (av[i])
	{
		ft_add_to_list(&arg_list, av[i]);
		i++;
	}
	return (arg_list);
}

void	ft_print_list(t_list **li, t_dim *size)
{
	t_list	*tmp;
	int		count;
	int		nb;

	ft_clear_term();
	tmp = *li;
	nb = 0;
	count = 0;
	while (tmp->next != *li)
	{
		ft_print_choice(tmp);
		if (nb++ >= size->line)
		{
			nb = 0;
			count++;
		}
		tputs(tgoto(CM, count * size->col, nb), 1, tputs_putchar);
		tmp = tmp->next;
	}
	ft_print_choice(tmp);
}

void	ft_print_choice(t_list *tmp)
{
	if (tmp->set == 1)
		tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	if (tmp->curs == 1)
		tputs(tgetstr("us", NULL), 1, tputs_putchar);
	ft_print_arg(tmp->arg);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
}
