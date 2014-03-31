/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:24:46 by mlingels          #+#    #+#             */
/*   Updated: 2013/12/27 17:21:54 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct	s_list
{
	int				val;
	struct s_list	*next;
}				t_list;

t_list	*ft_create_elem(int nb);
void	ft_add_elem(t_list **start, int nb);
void	ft_print_list(t_list *start);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
int		ft_is_digit(char c);
int		ft_is_schar(char c);
void	ft_s(t_list *li);
void	ft_swap(int *a, int *b);
void	ft_r(t_list **li);
void	ft_rr(t_list **li);
void	ft_p(t_list **start_1, t_list **start_2);

#endif
