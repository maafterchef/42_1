/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 10:51:38 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/17 10:52:07 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_putstr(char const *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}