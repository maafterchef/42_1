/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:12:45 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/12 18:33:43 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include "ft_select.h"

static char	*ft_join_choices(char *str, char *arg)
{
	char	*ret;
	size_t	len_1;
	size_t	len_2;
	int		i;

	len_1 = ft_strlen(str);
	len_2 = ft_strlen(arg);
	i = (len_1 == 0 ? len_2 + 1 : len_1 + len_2 + 2);
	ret = (char *)malloc(i);
	if (ret)
	{
		if (str)
		{
			(void)ft_strncpy(ret, str, len_1);
			ret[len_1] = ' ';
			(void)ft_strncpy(&ret[len_1 + 1], arg, len_2);
			free(str);
		}
		else
			(void)ft_strncpy(ret, arg, len_2);
		ret[i - 1] = 0;
		return (ret);
	}
	return (NULL);
}

void	ft_read_choices(t_list **arg_list)
{
	char	*ret;
	t_list	*tmp;

	tmp = *arg_list;
	ret = NULL;
	while (tmp->next != *arg_list)
	{
		if (tmp->set == 1)
			ret = ft_join_choices(ret, tmp->arg);
		tmp = tmp->next;
	}
	if (tmp->set == 1)
		ret = ft_join_choices(ret, tmp->arg);
	ft_putendl_fd(ret, 1);
}

int		ft_continue(char *buff)
{
	if (*(unsigned int*)buff == 10 || *(unsigned int*)buff == 27)
		return (0);
	return (1);
}

void	ft_print_arg(char *str)
{
	static int	fd;

	if (!fd)
		fd = open("/dev/tty", O_WRONLY);
	ft_putstr_fd(str, fd);
}

int		ft_is_end(char *buff, t_list **start)
{
	if (!*start)
		return (1);
	if (*(unsigned int*)buff == 27)
		return (1);
	return (0);
}
