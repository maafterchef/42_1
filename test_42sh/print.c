/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 02:27:23 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/05 03:11:43 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_print_str(char *str, t_pos *pos)
{
	int	i;

	tputs(CE);
	ft_putstr(&str[pos->pos_x]);
	pos->pos_x++;
	i = pos->cmd_len;
	while (i-- > pos->pos_x)
		tputs(MOVE_LEFT);
}

void	ft_print_prompt(void)
{
	ft_putstr("42sh> ");
}
