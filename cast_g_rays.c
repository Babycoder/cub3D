/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_g_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:06:48 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 10:19:57 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_sprite(t_data *img)
{
	t_texture	texture;
	int			id;
	int			nb;

	id = 0;
	init_textures(img, &texture);
	while (id < g_info.width)
	{
		nb = wich_side(nb, id);
		draw_floor(img, id);
		draw_wall(img, texture, id, nb);
		id++;
	}
	id = 0;
	sprite_cordinate();
	get_spriteimage(img);
	while (id < g_nsprite)
	{
		render_sprite(id, img);
		id++;
	}
}

void	cast_g_rays(t_data *img)
{
	int		id;
	float	g_rayangle;

	id = 0;
	g_rayangle = g_player.angle - (FOV / 2);
	while (id < g_info.width)
	{
		g_raycasting(g_rayangle, id);
		g_rayangle += (float)FOV / (float)g_info.width;
		id++;
	}
	id = 0;
	while (id < g_info.width)
	{
		wall_data(id);
		id++;
	}
	wall_sprite(img);
}
