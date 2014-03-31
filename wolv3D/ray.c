/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 08:37:03 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/19 20:32:41 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		ft_valid_point(t_point *point)
{
	if ((int)(point->x / 64) > 9 || (int)(point->x / 64) < 0)
		return (0);
	if ((int)(point->y / 64) > 9 || (int)(point->y / 64) < 0)
		return (0);
	return (1);
}

static double	ft_check_hor(double angle, t_env *mlx)
{
	t_point		pos;

	if (angle < 180)
		pos.y = (int)(mlx->pos_y / 64) * 64 - 1;
	else
		pos.y = (int)(mlx->pos_y / 64) * 64 + 64;
	pos.x = mlx->pos_x + (mlx->pos_y - pos.y)/tan((M_PI * angle) / 180);
	while (ft_valid_point(&pos))
	{
		if (mlx->map[(int)(pos.x / 64)][(int)(pos.y / 64)] == 1)
		{
			if (angle != 90 && angle != 270)
				return (fabs((mlx->pos_x - pos.x) / cos((M_PI * angle) / 180)));
			else
				return (fabs((mlx->pos_y - pos.y) / sin((M_PI * angle) / 180)));
		}
		pos.x += 64 / tan((M_PI * angle) / 180);
		if (angle < 180)
			pos.y -= 64;
		else
			pos.y += 64;
	}
	return (1000000);
}

static double	ft_check_ver(double angle, t_env *mlx)
{
	t_point		pos;

	if (angle >= 90 && angle < 270)
		pos.x = (int)(mlx->pos_x / 64) * 64 - 1;
	else
		pos.x = (int)(mlx->pos_x / 64) * 64 + 64;
	pos.y = mlx->pos_y + (mlx->pos_x - pos.x)*tan((M_PI * angle) / 180);
	while (ft_valid_point(&pos))
	{
		if (mlx->map[(int)(pos.x / 64)][(int)(pos.y / 64)] == 1)
		{
			if (angle != 90 && angle != 270)
				return (fabs((mlx->pos_x - pos.x) / cos((M_PI * angle) / 180)));
			else
				return (fabs((mlx->pos_y - pos.y) / sin((M_PI * angle) / 180)));
		}
		if (angle >= 90 && angle < 270)
			pos.x -= 64;
		else
			pos.x += 64;
		pos.y += 64 * tan((M_PI * angle) / 180);
	}
	return (10000000);
}

static double	ft_check_angle(double angle, t_env *mlx)
{
	double	dist_a;
	double	dist_b;
	double	dist;

	dist_a = ft_check_hor(angle, mlx);
	dist_b = ft_check_ver(angle, mlx);
	dist = (dist_a < dist_b ? dist_a : dist_b);
	if (angle != 90 && angle != 270)
		dist *= cos((float)(((90 - angle) * M_PI) / 180));
	return (fabs(dist));
}


void			ft_find_wall(t_env *mlx)
{
	double		angle;
	double		stop;
	double		dist;
	int			x;

	x = 0;
	angle = mlx->angle + 30;
	if (angle > 360)
		angle -= 360;
	stop = angle - 60;
	if (angle < 60)
		stop += 60;
	while (angle != stop)
	{
		dist = ft_check_angle(angle, mlx);
		ft_draw(x, dist, mlx);
		angle -= (float)30 / (float)160;
		if (angle < 0)
			angle += 360;
		x++;
	}
}
