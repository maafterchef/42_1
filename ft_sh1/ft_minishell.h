/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 14:47:28 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/27 19:27:56 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# define BUFF_SIZE 4096
# include <unistd.h>
# include <string.h>

typedef struct	s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}				t_read;

typedef struct	s_func
{
	char	*name;
	void	(*ptr)(char **);
}				t_func;

int		get_next_line(int fd, char **line);
char	**ft_strsplit(char **str, char **name);
char	*ft_get_line(char *str);
char	*ft_cpy(char **str);
int		ft_check_builtin(char **arg);
void	ft_cd(char **arg);
void	ft_free(char **arg);

#endif
