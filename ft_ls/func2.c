/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:54:40 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/15 20:57:28 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

int	ft_get_major_spaces(t_infos *entry_list, int i, int j)
{
	static int	nb;
	int			k;
	int			tmp;

	if (!nb)
	{
		k = 0;
		while (k <= i)
		{
			if ((tmp = ft_digitlen(major(entry_list[k].st_dev))) > nb)
				nb = tmp;
			k++;
		}
	}
	tmp = ft_digitlen(major(entry_list[j].st_dev));
	while (tmp++ < nb + 3)
		ft_putchar(' ');
	ft_putnbr(major(entry_list[j].st_dev));
	ft_putchar(',');
	(void)ft_get_minor_spaces(entry_list, i, j);
	return (0);
}

int	ft_get_minor_spaces(t_infos *entry_list, int i, int j)
{
	static int	nb;
	int			k;
	int			tmp;

	if (!nb)
	{
		k = 0;
		while (k <= i)
		{
			if ((tmp = ft_digitlen(minor(entry_list[k].st_dev))) > nb)
				nb = tmp;
			k++;
		}
	}
	tmp = ft_digitlen(minor(entry_list[j].st_dev));
	while (tmp++ < nb + 1)
		ft_putchar(' ');
	ft_putnbr(minor(entry_list[j].st_dev));
	ft_putchar(' ');
	return (0);
}

void	ft_get_group_spaces(t_infos *entry_list, int i, int j)
{
	static int	nb;
	int			k;
	int			tmp;

	if (!nb)
	{
		k = 0;
		while (k <= i)
		{
			if ((tmp = ft_spacelen(entry_list[k].group)) > nb)
				nb = tmp;
			k++;
		}
	}
	tmp = ft_spacelen(entry_list[j].group);
	ft_putstr(entry_list[j].group);
	while (tmp < nb)
	{
		ft_putchar(' ');
		tmp++;
	}
}

void	ft_get_size_spaces(t_infos *entry_list, int i, int j, int ret)
{
	static int	nb;
	int			k;
	int			tmp;

	if (!nb)
	{
		k = 0;
		while (k <= i)
		{
			if ((tmp = ft_digitlen(entry_list[k].size)) > nb)
				nb = tmp;
			k++;
		}
	}
	if (ret == 1)
		nb = 8;
	tmp = ft_digitlen(entry_list[j].size);
	while (tmp < nb + 2)
	{
		ft_putchar(' ');
		tmp++;
	}
	ft_putnbr(entry_list[j].size);
	ft_putchar(' ');
}

void	ft_get_link_spaces(t_infos *entry_list, int i, int j)
{
	static int	nb;
	int			k;
	int			tmp;

	if (!nb)
	{
		k = 0;
		while (k <= i)
		{
			if ((tmp = ft_digitlen(entry_list[k].nb_link)) > nb)
				nb = tmp;
			k++;
		}
	}
	tmp = ft_digitlen(entry_list[j].nb_link);
	while (tmp < nb + 2)
	{
		ft_putchar(' ');
		tmp++;
	}
	ft_putnbr(entry_list[j].nb_link);
	ft_putchar(' ');
	ft_get_owner_spaces(entry_list, i, j);
}
