/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 07:28:41 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/19 20:21:35 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define MAX_HEIGHT 200
# define MAX_WIDTH 320
# define POS_X 220
# define POS_Y 220

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			**map;
	double		pos_x;
	double		pos_y;
	double		angle;
}				t_env;


int				key_hook(int keycode, t_env *mlx);
int				expose_hook(t_env *mlx);
void			ft_find_wall(t_env *mlx);
void			ft_draw(int x, double dist, t_env *mlx);

void			ft_move_up(t_env *mlx);
void			ft_move_down(t_env *mlx);

#endif /* !WOLF3D_H */
