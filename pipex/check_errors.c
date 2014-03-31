/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 18:53:39 by po-conno          #+#    #+#             */
/*   Updated: 2014/01/02 18:40:13 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

int		check_errors(int nb)
{
	const char error[8][80] = {
		"open failed\n",
		"dup failed\n",
		"close failed\n",
		"execve failed\n",
		"pipe failed\n",
		"fork failed\n",
		"fchmod failed\n",
		"invalid number of arguments\nUsage : file1 \"cmd1\" \"cmd2\" file2\n"
	};

	ft_puterror("pipex : ", error[nb]);
	return (-1);
}

int		check_input(char **env, char *input)
{
	char		*path;

	path = NULL;
	if (input[0] != '/')
	{
		path = get_env_value(env, "PWD");
		cat_path(&path, input, "/");
	}
	else
		path = input;
	if (access(path, F_OK) == -1)
	{
		ft_puterror(input, " : no such file or directory\n");
		return (-1);
	}
	else if (access(path, R_OK) == -1)
	{
		ft_puterror(input, " : permission denied\n");
		return (-1);
	}
	return (0);
}

int		check_output(char **env, char *output)
{
	char		*path;

	path = NULL;
	if (output[0] != '/')
	{
		path = get_env_value(env, "PWD");
		cat_path(&path, output, "/");
	}
	else
		path = output;
	if (access(path, W_OK) == -1)
	{
		ft_puterror(output, " : permission denied\n");
		return (-1);
	}
	return (0);
}
