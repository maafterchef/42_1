/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 16:13:01 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/21 17:59:40 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_is_valid_link(char *str, t_room **hill)
{
	//t_room	*tmp;

	/*
	 * Pour chaque lien, on va :
	 * - verifier que les deux salles pointees existent
	 * - aller dans chaque salle concernee dans la liste, et inserer les pointeurs sur les salles pour chaque lien
	 */

	if (str[0] != 0)
		return (1);
	return (0);
}
