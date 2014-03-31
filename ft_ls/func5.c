/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 21:01:33 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/15 22:08:23 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

char	*ft_joinpath(char *path, char *entry)
{
	char	*str;
	size_t	len_1;
	size_t	len_2;
	int		i;

	i = 0;
	len_1 = ft_strlen(path);
	len_2 = ft_strlen(entry);
	str = (char *)malloc(len_1 + len_2 + 2);
	if (str)
	{
		(void)ft_strncpy(str, path, len_1);
		if (path[len_1 - 1] != '/')
		{
			str[len_1] = '/';
			len_1++;
		}
		(void)ft_strncpy(&str[len_1], entry, len_2);
		str[len_1 + len_2] = 0;
		return (str);
	}
	return (NULL);
}

int	ft_save_stats(t_infos *entry, char *path, t_options *list, int i)
{
	struct stat		*buff;
	struct passwd	*id;
	struct group	*grp;
	static int		nb_blocks;

	buff = (struct stat *)malloc(sizeof(struct stat));
	lstat(path, buff);
	if (list[2].set == 1)
	{
		entry[i].modes = buff->st_mode;
		entry[i].nb_link = buff->st_nlink;
		if (!S_ISBLK(entry[i].modes) && !S_ISCHR(entry[i].modes))
			entry[i].size = buff->st_size;
		else
			entry[i].st_dev = buff->st_rdev;
		id = getpwuid(buff->st_uid);
		entry[i].owner = id->pw_name;
		grp = getgrgid(buff->st_gid);
		entry[i].group = grp->gr_name;
		nb_blocks += buff->st_blocks;
	}
	entry[i].time = buff->st_mtime;
	free(buff);
	free(path);
	return (nb_blocks);
}

int	ft_is_dir(char *str)
{
	if (ft_strcmp(str, ".") == 0 || ft_strcmp(str, "..") == 0)
		return (0);
	return (1);
}

int	ft_is_valid_dir(char *str, DIR **res, char **path)
{
	int				i;
	struct dirent	*entry;

	i = 0;
	*res = opendir(str);
	if (*res)
	{
		while ((entry = readdir(*res)) != NULL)
			i++;
		closedir(*res);
		*res = opendir(str);
		*path = str;
		return (i);
	}
	else
		ft_find_file(str);
	return (-1);
}

void	ft_find_file(char *str)
{
	char			*path;
	DIR				*res;
	struct dirent	*entry;

	path = ft_find_path(&str);
	res = opendir(path);
	if (res)
	{
		while ((entry = readdir(res)) != NULL)
		{
			if (ft_strcmp(entry->d_name, str) == 0)
			{
				if (entry->d_type == DT_DIR)
					ft_permission_denied(str, path);
				else
					ft_putendl(str);
				closedir(res);
				return ;
			}
		}
	}
	else
		ft_unfound_error(str, path);
}
