/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:45:20 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/19 20:28:32 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw(int x, double dist, t_env *mlx)
{
	int	y_min;
	int	y_max;
	int	y;

	y = 0;
	dist = (277 * 64) / dist;
	y_max = 100 + (int)(dist / 2);
	y_min = 100 - (int)(dist / 2);
	while (y < y_min)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x33CCFF);
		y++;
	}
	while (y <= y_max)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFF0000);
		y++;
	}
	while (y < MAX_HEIGHT)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x808080);
		y++;
	}
}

void	ft_move_down(t_env *mlx)
{
	t_point	point;

	point.x = mlx->pos_x + cos((M_PI * mlx->angle) / 180);
	point.y = mlx->pos_y + sin((M_PI * mlx->angle) / 180);
	if (point.x > 0 && point.x < 639 && point.x > 0 && point.y < 639)
	{
		if (mlx->map[(int)(point.x / 64)][(int)(point.y / 64)] == 0)
		{
			mlx->pos_x = point.x;
			mlx->pos_y = point.y;
		}
	}
}

void	ft_move_up(t_env *mlx)
{
	t_point	point;

	point.x = mlx->pos_x - cos((M_PI * mlx->angle) / 180);
	point.y = mlx->pos_y - sin((M_PI * mlx->angle) / 180);
	if (point.x > 0 && point.x < 639 && point.x > 0 && point.y < 639)
	{
		if (mlx->map[(int)(point.x / 64)][(int)(point.y / 64)] == 0)
		{
			mlx->pos_x = point.x;
			mlx->pos_y = point.y;
		}
	}
}
