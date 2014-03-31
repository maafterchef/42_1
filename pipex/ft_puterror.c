/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 15:32:35 by po-conno          #+#    #+#             */
/*   Updated: 2013/12/30 18:19:13 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puterror(char const *cmd, char const *s)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	if (cmd)
	{
		while (cmd[i] != 0)
			write(2, &cmd[i++], 1);
	}
	i = 0;
	while (s[i] != '\0')
		write(2, &s[i++], 1);
}
