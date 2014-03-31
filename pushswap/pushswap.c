/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:24:03 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/27 17:23:07 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_list	*li_a;
	t_list	*li_b;
	int		i;

	if (ac < 2)
		return (0);
	//Need msg error
	li_a = ft_create_elem(ft_atoi(av[1]));
	li_b = 0;
	i = 2;
	while (i < ac)
	{
		ft_add_elem(&li_a, ft_atoi(av[i]));
		i++;
	}
	ft_print_list(li_a);
	ft_putchar('\n');
	ft_s(li_a);
	ft_print_list(li_a);
	ft_putchar('\n');
	ft_r(&li_a);
	ft_print_list(li_a);
	ft_putchar('\n');
	ft_rr(&li_a);
	ft_print_list(li_a);
	ft_putchar('\n');
	ft_p(&li_a, &li_b);
	ft_print_list(li_a);
	ft_putchar('\n');
	ft_print_list(li_b);
	ft_putchar('\n');
	ft_p(&li_b, &li_a);
	ft_print_list(li_a);
	ft_putchar('\n');
	ft_print_list(li_b);
	ft_putchar('\n');
	//On trie la liste et on affiche l'algo utilise
	return (0);
}
