/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:16:56 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/31 18:59:53 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>

int		check_errors(int nb);
int		check_input(char **env, char *input);
int		check_output(char **env, char *output);
void	cat_path(char **str, char *cmd, char *sep);
char	**ft_read_cmd(char *str);
char	*get_env_value(char **env, char *name);
char	*get_path(char **env, char *cmd);
void	ft_memdel(void **ap);
void	ft_puterror(char const *cmd, char const *s);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	free_tab(char ***tmp);
char	**copy_tab(char **tab, int over, int j);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_strcat(char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
char	**ft_strsplit(char const *s, char c);

#endif /* !PIPEX_H */
