/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cordinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 08:58:06 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 09:31:54 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_cordinate(int i, int j, int id)
{
	g_sprite[id].x = j * TILE_SIZE + 30;
	g_sprite[id].y = i * TILE_SIZE + 30;
	g_sprite[id].dst = (float)sqrt((g_sprite[id].x - g_player.x) *
			(g_sprite[id].x - g_player.x) +
			(g_sprite[id].y - g_player.y) *
			(g_sprite[id].y - g_player.y));
}

void	sprite_cordinate(void)
{
	int i;
	int j;
	int id;

	i = 0;
	id = 0;
	while (i < g_rows)
	{
		j = 0;
		while (j < len(g_info.map[i]))
		{
			if (g_info.map[i][j] == '2')
			{
				save_cordinate(i, j, id);
				id++;
			}
			j++;
		}
		i++;
	}
	sort_sprit();
}
