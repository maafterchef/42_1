/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:38:50 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/07 21:22:28 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERV_H
# define SERV_H

typedef struct	s_str
{
	char		*str;
	int			c;
	int			bit;
}				t_str;

t_str			*g_read;

#endif
