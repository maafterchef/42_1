/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 09:57:00 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/26 16:07:09 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH2_H
# define FT_SH2_H

# define BUFF_SIZE 1024

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

typedef struct		s_func
{
	char			*name;
	void			(*ptr)(char **, char **);
}					t_func;

typedef struct		s_list
{
	char			**tab;
	struct s_list	*next;
	int				pipe;
}					t_list;


int		ft_check_builtin(char **tab, char **env); /* FT_SH.C */
char	*ft_join_cmd(char const *s1, char const *s2, size_t len);
char	*ft_get_path(char **env);
int		ft_check_cmd(t_list *tmp, char *path);

int		get_next_line(int fd, char **line);

void	ft_puterror(char *str, char *str2); /* TOOLS.C */
char	**ft_cpy_env(char **environ);

void	ft_run(t_list **tmp, char **env); /* RUN.C */

void	ft_del_list(t_list *start);

void	ft_env(char **tab, char **env);
void	ft_cd(char **tab, char **env);
void	ft_exit(char **tab, char **env);
void	ft_setenv(char **tab, char **env);
void	ft_unsetenv(char **tab, char **env);

t_list	*ft_split_cmds(char *str);
void	ft_run_list(t_list **start, char **env, char *path);
# endif /* !FT_SH2_H */
