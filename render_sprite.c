/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 08:49:36 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 09:22:41 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_put_pixels(int id, int i, int j, t_data *img)
{
	int *add;
	int a;
	int color;

	add = (int*)mlx_get_data_addr(g_sptexture.img_sprite, &a, &a, &a);
	color = add[((int)g_sptexture.width * (j * (int)g_sptexture.height /
			(int)g_sprite[id].size)) + (i * (int)g_sptexture.width /
			(int)g_sprite[id].size)];
	if (color != 0)
	{
		put_my_pixel(img, g_sprite[id].x_ofst + i,
				g_sprite[id].y_ofst + j, color);
	}
}

void	draw_sprite(int id, t_data *img)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < g_sprite[id].size - 1)
	{
		if (g_sprite[id].x_ofst + i < 0 ||
				g_sprite[id].x_ofst + i > g_info.width)
			continue;
		if (g_sprite[id].dst > g_ray[(int)g_sprite[id].x_ofst + i].d)
			continue;
		j = -1;
		while (++j < g_sprite[id].size - 1)
		{
			if (g_sprite[id].y_ofst + j < 0 ||
					g_sprite[id].y_ofst + j > g_info.height)
				continue;
			sprite_put_pixels(id, i, j, img);
		}
	}
}

void	render_sprite(int id, t_data *img)
{
	float angle;

	angle = atan2(g_sprite[id].y - g_player.y, g_sprite[id].x - g_player.x);
	while (angle - to_rad(g_player.angle) > M_PI)
		angle -= 2 * M_PI;
	while (angle - to_rad(g_player.angle) < -M_PI)
		angle += 2 * M_PI;
	angle = angle - to_rad(g_player.angle);
	angle = to_deg(angle);
	if (g_info.height > g_info.width)
		g_sprite[id].size = (g_info.height / g_sprite[id].dst) * TILE_SIZE;
	else
		g_sprite[id].size = (g_info.width / g_sprite[id].dst) * TILE_SIZE;
	g_sprite[id].y_ofst = (g_info.height / 2) - (g_sprite[id].size / 2);
	g_sprite[id].x_ofst = ((angle * g_info.width) / FOV) +
		((g_info.width / 2) - (g_sprite[id].size / 2));
	draw_sprite(id, img);
}
