/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 11:05:09 by mlingels          #+#    #+#             */
/*   Updated: 2014/02/05 09:45:02 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH3_H
# define FT_SH3_H

# define BUFF_SIZE 1024

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include <termcap.h>

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

typedef struct		s_hist
{
	char			*str;
	struct s_hist	*next;
}					t_hist;

typedef struct		s_cdinfos
{
	int				pwd;
	int				old_pwd;
	int				home;
}					t_cdinfos;

int		ft_check_builtin(char **tab, char **env); /* FT_SH.C */
char	*ft_join_cmd(char const *s1, char const *s2, size_t len);
char	*ft_get_path(char **env);
int		ft_check_cmd(t_list *tmp, char *path);

void	ft_terminal_mode(void);

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
t_list	*ft_create_elem(char *ptr, char c);

void	ft_save_history(char *str, t_hist **start);
void	ft_print_hist(t_hist **start);
t_hist	*ft_create_hist(void);

void	ft_puterror(char *str, char *str2);
char	*ft_joinpath(char *str, char *str2);
char	*ft_find_path(char *dir, char *str);
# endif /* !FT_SH3_H */
