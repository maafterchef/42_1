/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:53:15 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/15 21:04:55 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

void	ft_recursive(char *path, t_options *list)
{
	DIR				*rec;
	DIR				*new;
	struct dirent	*entry;
	char			*new_path;
	int				ret;

	if (list[0].set != 1)
		return ;
	rec = opendir(path);
	while ((entry = readdir(rec)) != NULL)
	{
		if (entry->d_type == DT_DIR && ft_is_dir(entry->d_name) == 1)
		{
			new_path = ft_joinpath(path, entry->d_name);
			if ((ret = ft_dir_permissions(new_path)) >= 0)
			{
				new = opendir(new_path);
				ft_print_dirname(1, 2, new_path);
				ft_ls_dir(new, list, ret, new_path);
				closedir(new);
			}
			free(new_path);
		}
	}
	closedir(rec);
}

int	ft_dir_permissions(char *path)
{
	DIR				*ls_dir;
	struct dirent	*entry;
	int				ret;

	ret = 0;
	ls_dir = opendir(path);
	if (!ls_dir)
	{
		ft_putchar('\n');
		ft_permission_denied(path, NULL);
		return (-1);
	}
	while ((entry = readdir(ls_dir)) != NULL)
		ret++;
	closedir(ls_dir);
	return (ret);
}

void	ft_print_blocks(int nb_blocks, t_options *list)
{
	if (list[2].set == 1)
	{
		ft_putstr("total ");
		ft_putnbr(nb_blocks);
		ft_putchar('\n');
	}
}

void	ft_sort_entries(t_infos *entry_list, int i, t_options *list, char *dir)
{
	int		j;
	t_infos	tmp;
	int		done;
	int		ret;

	done = 0;
	if (list[4].set == 1)
		done = ft_sort_time_entries(entry_list, i, list);
	while (done == 0)
	{
		done = 1;
		j = -1;
		while (j++ < i - 1)
		{
			ret = ft_strcmp(entry_list[j].name, entry_list[j + 1].name);
			if (ft_check(ret, list) == 1)
			{
				tmp = entry_list[j];
				entry_list[j] = entry_list[j + 1];
				entry_list[j + 1] = tmp;
				done = 0;
			}
		}
	}
	ft_print_entries(entry_list, i, list, dir);
}

int	ft_check(int i, t_options *list)
{
	if ((i > 0 && list[3].set == 0) || (i < 0 && list[3].set == 1))
		return (1);
	return (0);
}
