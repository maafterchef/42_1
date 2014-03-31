/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:46:16 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/09 14:34:07 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void			ft_error(int err)
{
	static char	msgs[3][80] =
	{
		"usage: ./puissance4 nb_lines nb_cols",
		"not sufficient memory to run puissance4",
		"usage: ./puissance4 nb_lines nb_cols\nminimum size is 6x7"
	};

	ft_putendl("puissance4: error");
	ft_putendl(msgs[err]);
}
