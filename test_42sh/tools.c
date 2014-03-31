/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 06:11:16 by mlingels          #+#    #+#             */
/*   Updated: 2014/03/05 06:42:18 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*ft_del_char(int pos, char *str)
{
	char	*new;
	size_t	len;

	len = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * len);
	if (new)
	{
		(void)ft_strncpy(new, str, pos);
		(void)ft_strncpy(&new[pos], &str[pos + 1], len - pos);
		new[len] = 0;
	}
	return (new);
}

void		ft_set_term(struct termios *term)
{
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
}

void		ft_unset_term(struct termios *term)
{
	term->c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, term);
}
