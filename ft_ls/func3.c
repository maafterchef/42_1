/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:58:39 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/15 21:05:20 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

void	ft_get_owner_spaces(t_infos *entry_list, int i, int j)
{
	static int	nb;
	int			k;
	int			tmp;

	if (!nb)
	{
		k = 0;
		while (k <= i)
		{
			if ((tmp = ft_spacelen(entry_list[k].owner)) > nb)
				nb = tmp;
			k++;
		}
	}
	tmp = ft_spacelen(entry_list[j].owner);
	ft_putstr(entry_list[j].owner);
	while (tmp < nb + 2)
	{
		ft_putchar(' ');
		tmp++;
	}
	ft_get_group_spaces(entry_list, i, j);
}

int	ft_spacelen(char *str)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	j = i - 1;
	while (str[j] == ' ')
		j--;
	return (j + 1);
}

int	ft_digitlen(int i)
{
	if (i < 0)
		i = -i;
	if (i <= 9)
		return (1);
	return (1 + ft_digitlen(i / 10));
}

void	ft_print_type(mode_t modes)
{
	if (S_ISREG(modes))
		ft_putchar('-');
	if (S_ISDIR(modes))
		ft_putchar('d');
	if (S_ISBLK(modes))
		ft_putchar('b');
	if (S_ISCHR(modes))
		ft_putchar('c');
	if (S_ISLNK(modes))
		ft_putchar('l');
	if (S_ISFIFO(modes))
		ft_putchar('p');
	if (S_ISSOCK(modes))
		ft_putchar('s');
	ft_print_rights(modes);
}

void	ft_print_rights(mode_t modes)
{
	if (modes & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (modes & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (modes & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	if (modes & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (modes & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	ft_print_rights_end(modes);
}
