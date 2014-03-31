/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 14:35:44 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/21 16:44:18 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>
# include <stdlib.h>

typedef struct			s_room
{
	char				*name;
	struct s_room		**links;
	int					spe;
	struct s_room		*next;
}						t_room;

/* HILL.C */
t_room		*ft_read_hill(void);
int			ft_is_valid_room(char *ptr, t_room **hill);
int			ft_get_room_spe(char **ptr);
char		*ft_get_room_name(char *str);

/* ROOM.C */
int			ft_is_valid_link(char *str, t_room **hill);

/* LIST.C */
void		ft_new_room(t_room **start, char *name, int spe);

/* SOLVE.C */
//void		ft_solve_hill(int ants, t_node *hill);

#endif
