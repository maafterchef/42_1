/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 20:29:07 by mlingels          #+#    #+#             */
/*   Updated: 2014/01/19 20:30:16 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_generate_map(t_env *mlx)
{
	int		i;
	int		j;
	int		**map;

	map = (int **)malloc(sizeof(int) * 10);
	i = 0;
	while (i < 10)
	{
		map[i] = (int *)malloc(sizeof(int) * 10);
		j = 0;
		while (j < 10)
		{
			if (i == 0 || i == 9)
				map[i][j] = 1;
			else if (j == 0 || j == 9)
				map[i][j] = 1;
			else
				map[i][j] = 0;
			j++;
		}
		i++;
	}
	mlx->map = map;
}

int			key_hook(int keycode, t_env *mlx)
{
	if (keycode == 65362)
		ft_move_up(mlx);
	if (keycode == 65364)
		ft_move_down(mlx);
	if (keycode == 65361)
	{
		mlx->angle += 11;
		if (mlx->angle > 360)
			mlx->angle -= 360;
	}
	if (keycode == 65363)
	{
		mlx->angle -= 11;
		if (mlx->angle < 0)
			mlx->angle += 360;
	}
	ft_find_wall(mlx);
	if (keycode == 65307)
	{
		free(mlx->map);
		exit(0);
	}
	return (0);
}

int			expose_hook(t_env *mlx)
{
	ft_find_wall(mlx);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	new;

	ft_generate_map(&new);
	new.pos_x = POS_X;
	new.pos_y = POS_Y;
	new.angle = 90;
	new.mlx = mlx_init();
	new.win = mlx_new_window(new.mlx, MAX_WIDTH, MAX_HEIGHT, "wolf3D");
	mlx_expose_hook(new.win, expose_hook, &new);
	mlx_key_hook(new.win, key_hook, &new);
	mlx_loop(new.mlx);
	return (0);
}
