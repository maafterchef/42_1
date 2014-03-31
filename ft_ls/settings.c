/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:59:04 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/15 21:47:51 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

void	ft_list_options(t_options *list)
{
	ft_add_opt('R', list, 0);
	ft_add_opt('a', list, 1);
	ft_add_opt('l', list, 2);
	ft_add_opt('r', list, 3);
	ft_add_opt('t', list, 4);
}

void	ft_add_opt(char c, t_options *list, int i)
{
	list[i].name = c;
	list[i].set = 0;
}
