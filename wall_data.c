/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 04:56:17 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 05:01:08 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_data(int id)
{
	float	distance;
	float	projection;
	float	wallheight;
	int		toppixel;
	int		bottompixel;

	distance = g_ray[id].d * cos((g_ray[id].angle - g_player.angle)
			* (M_PI / 180));
	projection = (g_info.width / 2) / tan((FOV / 2) * (M_PI / 180));
	wallheight = (TILE_SIZE / distance) * projection;
	toppixel = (g_info.height / 2) - ((int)wallheight / 2);
	bottompixel = toppixel + wallheight;
	g_ray[id].top = toppixel;
	g_ray[id].bottom = bottompixel;
	g_ray[id].height = wallheight;
}
