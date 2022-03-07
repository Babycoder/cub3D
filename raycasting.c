/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 09:34:38 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 09:51:47 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical_rc(void)
{
	while (wall_check(g_var.xintercept, g_var.yintercept))
	{
		g_var.xintercept += g_var.xstep;
		g_var.yintercept += g_var.ystep;
	}
	if (g_var.left)
		g_var.xintercept++;
	g_var.hitx2 = g_var.xintercept;
	g_var.hity2 = g_var.yintercept;
	g_var.d2 = (float)sqrt((g_var.hitx2 - g_player.x) *
		(g_var.hitx2 - g_player.x) +
		(g_var.hity2 - g_player.y) * (g_var.hity2 - g_player.y));
}

void	horizontal_raycasting(float g_rayangle)
{
	g_var.hitx1 = 0;
	g_var.hity1 = 0;
	g_var.yintercept = (float)floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	if (g_var.down == 1)
		g_var.yintercept += TILE_SIZE;
	g_var.xintercept = g_player.x +
	(g_var.yintercept - g_player.y) / tan(g_rayangle * (M_PI / 180));
	g_var.ystep = TILE_SIZE;
	if (g_var.up)
		g_var.ystep *= -1;
	g_var.xstep = TILE_SIZE / tan(g_rayangle * (M_PI / 180));
	if (g_var.left && g_var.xstep > 0)
		g_var.xstep *= -1;
	if (g_var.right == 1 && g_var.xstep < 0)
		g_var.xstep *= -1;
	g_var.nexthitx = g_var.xintercept;
	g_var.nexthity = g_var.yintercept;
	if (g_var.up)
		g_var.yintercept--;
	horizontal_rc();
}

void	vertical_raycasting(float g_rayangle)
{
	g_var.hitx2 = 0;
	g_var.hity2 = 0;
	g_var.xintercept = (float)floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	if (g_var.right == 1)
		g_var.xintercept += TILE_SIZE;
	g_var.yintercept = g_player.y + (g_var.xintercept - g_player.x) *
	tan(g_rayangle * (M_PI / 180));
	g_var.xstep = TILE_SIZE;
	if (g_var.left)
		g_var.xstep *= -1;
	g_var.ystep = TILE_SIZE * tan(g_rayangle * (M_PI / 180));
	if (g_var.up && g_var.ystep > 0)
		g_var.ystep *= -1;
	if (g_var.down == 1 && g_var.ystep < 0)
		g_var.ystep *= -1;
	g_var.nexthitx = g_var.xintercept;
	g_var.nexthity = g_var.yintercept;
	if (g_var.left)
		g_var.xintercept--;
	vertical_rc();
}

void	calculate_distance(float g_rayangle, int id)
{
	if (g_var.d2 < g_var.d1)
	{
		g_ray[id].hitx = g_var.hitx2;
		g_ray[id].hity = g_var.hity2;
		g_ray[id].offset = (int)g_var.hity2 % TILE_SIZE;
		g_ray[id].vertical = 1;
		g_var.d = g_var.d2;
	}
	else
	{
		g_var.d = g_var.d1;
		g_ray[id].hitx = g_var.hitx1;
		g_ray[id].hity = g_var.hity1;
		g_ray[id].vertical = 0;
		g_ray[id].offset = (int)g_var.hitx1 % TILE_SIZE;
	}
	g_ray[id].angle = g_rayangle;
	g_ray[id].d = g_var.d;
	g_ray[id].down = g_var.down;
	g_ray[id].up = g_var.up;
	g_ray[id].left = g_var.left;
	g_ray[id].right = g_var.right;
}

void	g_raycasting(float g_rayangle, int id)
{
	g_rayangle = normalizeangle(g_rayangle);
	g_var.d1 = 0;
	g_var.d2 = 0;
	g_var.d = 0;
	g_var.down = 0;
	g_var.right = 0;
	if (g_rayangle >= 0 && g_rayangle < 180)
		g_var.down = 1;
	if (g_rayangle < 90 || g_rayangle > 270)
		g_var.right = 1;
	g_var.up = !g_var.down;
	g_var.left = !g_var.right;
	horizontal_raycasting(g_rayangle);
	vertical_raycasting(g_rayangle);
	calculate_distance(g_rayangle, id);
}
