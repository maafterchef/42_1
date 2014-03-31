/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 22:07:21 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/15 22:07:21 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

int	ft_sort_time_entries(t_infos *entry_list, int i, t_options *list)
{
	int		j;
	t_infos	tmp;
	int		done;
	int		ret;

	done = 0;
	while (done == 0)
	{
		done = 1;
		j = 0;
		while (j < i)
		{
			ret = entry_list[j + 1].time - entry_list[j].time;
			if (ft_check(ret, list) == 1)
			{
				tmp = entry_list[j];
				entry_list[j] = entry_list[j + 1];
				entry_list[j + 1] = tmp;
				done = 0;
			}
			j++;
		}
	}
	return (done);
}

void	ft_print_entries(t_infos *entry_list, int i, t_options *list, char *dir)
{
	int	j;
	int	ret;

	ret = ft_is_dev(entry_list, i);
	j = -1;
	while (j++ < i)
	{
		if (list[2].set == 1)
		{
			ft_print_type(entry_list[j].modes);
			ft_get_link_spaces(entry_list, i, j);
			if (S_ISCHR(entry_list[j].modes) || S_ISBLK(entry_list[j].modes))
				ft_get_major_spaces(entry_list, i, j);
			else
				ft_get_size_spaces(entry_list, i, j, ret);
			ft_putstr(ft_strsub(ctime(&entry_list[j].time), 4 , 12));
			ft_putchar(' ');
		}
		if (list[2].set == 1 && S_ISLNK(entry_list[j].modes))
			ft_print_link(entry_list[j].name, dir);
		else
			ft_putendl(entry_list[j].name);
	}
	free(entry_list);
}

int	ft_is_dev(t_infos *entry_list, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		if (S_ISCHR(entry_list[j].modes) || S_ISBLK(entry_list[j].modes))
			return (1);
		j++;
	}
	return (0);
}

void	ft_print_link(char *name, char *path)
{
	char	*buff;
	char	*full_path;

	full_path = ft_joinpath(path, name);
	buff = (char *)malloc(50);
	readlink(full_path, buff, 50);
	ft_putstr(name);
	ft_putstr(" -> ");
	ft_putendl(buff);
	free(buff);
	free(full_path);
}

void	ft_print_rights_end(mode_t modes)
{
	if (modes & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	if (modes & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (modes & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (modes & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}
