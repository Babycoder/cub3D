/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:27:02 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 10:39:30 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keyboard_second(int x, float xcheck, float ycheck)
{
	if ((x == 13) && wall_check(cos(to_rad(g_player.angle)) * 60 +
				g_player.x, sin(to_rad(g_player.angle)) * 60 + g_player.y))
	{
		g_player.x = xcheck;
		g_player.y = ycheck;
	}
	xcheck = -cos(to_rad(g_player.angle)) * WALK_SPEED + g_player.x;
	ycheck = -sin(to_rad(g_player.angle)) * WALK_SPEED + g_player.y;
	if ((x == 1) && wall_check(-cos(to_rad(g_player.angle)) * 60 +
				g_player.x, -sin(to_rad(g_player.angle)) * 60 + g_player.y))
	{
		g_player.x = xcheck;
		g_player.y = ycheck;
	}
	if (x == 124)
		g_player.angle += TURN_SPEED;
	if (x == 123)
		g_player.angle -= TURN_SPEED;
}

void	keyboard_third(int x, float xcheck, float ycheck)
{
	if (x == 0 && wall_check(cos(to_rad(g_player.angle - 90)) * 60 +
				g_player.x, sin(to_rad(g_player.angle - 90)) * 60 + g_player.y))
	{
		g_player.x = xcheck;
		g_player.y = ycheck;
	}
	xcheck = cos(to_rad(g_player.angle + 90)) * WALK_SPEED + g_player.x;
	ycheck = sin(to_rad(g_player.angle + 90)) * WALK_SPEED + g_player.y;
	if (x == 2 && wall_check(cos(to_rad(g_player.angle + 90)) * 60 +
				g_player.x, sin(to_rad(g_player.angle + 90)) * 60 + g_player.y))
	{
		g_player.x = xcheck;
		g_player.y = ycheck;
	}
}

int		keyboard(int x, t_data *img)
{
	float xcheck;
	float ycheck;

	xcheck = cos(to_rad(g_player.angle)) * WALK_SPEED + g_player.x;
	ycheck = sin(to_rad(g_player.angle)) * WALK_SPEED + g_player.y;
	keyboard_second(x, xcheck, ycheck);
	xcheck = cos(to_rad(g_player.angle - 90)) * WALK_SPEED + g_player.x;
	ycheck = sin(to_rad(g_player.angle - 90)) * WALK_SPEED + g_player.y;
	keyboard_third(x, xcheck, ycheck);
	if (x == 53)
	{
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, g_info.width, g_info.height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	cast_g_rays(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}
