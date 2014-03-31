/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:52:11 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/15 22:06:28 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

int				main(int argc, char **argv)
{
	t_options	list[OPT_NB];

	ft_list_options(list);
	if (argc > 1)
		ft_read_args(list, argc, argv);
	else
		ft_ls_current(list);
	return (0);
}

void	ft_read_args(t_options *list, int argc, char **argv)
{
	int			i;
	int			ret;
	DIR			*ls_dir;
	char		*path;

	i = 0;
	while (++i < argc && argv[i][0] == '-')
	{
		if (ft_check_args(argv[i], list) == 0)
			return ;
	}
	while (i < argc)
	{
		if ((ret = ft_is_valid_dir(argv[i], &ls_dir, &path)) >= 0)
		{
			ft_print_dirname(i, argc, argv[i]);
			ft_ls_dir(ls_dir, list, ret, path);
			closedir(ls_dir);
		}
		i++;
	}
	if (argv[i - 1][0] == '-')
		ft_ls_current(list);
}

void	ft_print_dirname(int i, int argc, char *str)
{
	static int	check;
	static int	first;

	if (i < argc)
		check = 1;
	if (first == 0)
		first = 1;
	else
		ft_putchar('\n');
	if (check == 1)
	{
		ft_putstr(str);
		ft_putendl(":");
	}
}

void	ft_ls_current(t_options *list)
{
	int		ret;
	DIR		*ls_dir;
	char	*path;

	ret = ft_is_valid_dir(".", &ls_dir, &path);
	ft_ls_dir(ls_dir, list, ret, path);
}

void	ft_ls_dir(DIR *ls_dir, t_options *list, int nb, char *path)
{
	struct dirent	*entry;
	t_infos			*entry_list;
	int				i;
	char			*path_name;
	int				nb_blocks;

	i = -1;
	nb_blocks = 0;
	entry_list = (t_infos *)malloc((nb + 1) * sizeof(t_infos));
	while ((entry = readdir(ls_dir)) != NULL)
	{
		if (entry->d_name[0] != '.' || list[1].set == 1)
		{
			entry_list[++i].name = (char *)malloc(ft_strlen(entry->d_name) + 1);
			(void)ft_strcpy(entry_list[i].name, entry->d_name);
			if (list[2].set == 1 || list[4].set == 1)
			{
				path_name = ft_joinpath(path, entry->d_name);
				nb_blocks = ft_save_stats(entry_list, path_name, list, i);
			}
		}
	}
	ft_print_blocks(nb_blocks, list);
	ft_sort_entries(entry_list, i - 1, list, path);
	ft_recursive(path, list);
}
