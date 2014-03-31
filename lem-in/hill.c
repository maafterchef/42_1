/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 14:48:10 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/21 16:45:29 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*ft_read_hill(void)
{
	char	*ptr;
	t_room	*hill;
	int		ret;
	t_room	*tmp;

	hill = NULL;
	get_next_line(0, &ptr);
	ret = ft_is_valid_room(ptr, &hill);
	while (ret == 1)
	{
		get_next_line(0, &ptr);
		ret = ft_is_valid_room(ptr, &hill);
	}
	if (ret == -1)
	{
		tmp = hill;
		while (tmp)
		{
			ft_putendl(tmp->name);
			tmp = tmp->next;
		}
		while (ft_is_valid_link(ptr, &hill))
			get_next_line(0, &ptr);
	}
	return (NULL);
}

int			ft_is_valid_room(char *ptr, t_room **hill)
{
	int		spe;
	char	*name;

	spe = ft_get_room_spe(&ptr);
	name = ft_get_room_name(ptr);
	if (name == ptr)
		return (-1);
	if (name)
	{
		ft_new_room(hill, name, spe);
		return (1);
	}
	return (0);
}

int			ft_get_room_spe(char **ptr)
{
	int		spe;

	spe = 0;
	if (*ptr[0] == '#')
	{
		if (ft_strcmp(*ptr, "##start") == 0)
			spe = 1;
		else if (ft_strcmp(*ptr, "##end") == 0)
			spe = 2;
		get_next_line(0, ptr);
		ft_get_room_spe(ptr);
	}
	return (spe);
}

char		*ft_get_room_name(char *str)
{
	char	*ptr;
	char	*ret;
	char	*coord;

	ptr = ft_strchr(str, ' ');
	if (!ptr)
		return (str);
	ret = ft_strsub(str, 0, ptr - str);
	coord = ft_strsub(ptr, 1, ft_strchr(ptr + 1, ' ') - ptr);
	if (!coord)
		return (NULL);
	ptr = ft_strchr(ptr + 1, ' ');
	if (!ptr)
		return (NULL);
	return (ret);
}
