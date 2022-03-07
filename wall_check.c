/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 08:40:23 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 08:42:28 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		wall_check(float x, float y)
{
	int mapx;
	int mapy;

	mapx = (int)floor(x / TILE_SIZE);
	mapy = (int)floor(y / TILE_SIZE);
	if (mapx >= 0 && mapy >= 0 && mapy < g_rows && mapx < len(g_info.map[mapy]))
	{
		if (g_info.map[mapy][mapx] != '1')
			return (1);
	}
	return (0);
}
