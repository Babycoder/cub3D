/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 06:08:14 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 06:09:05 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_player(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_rows)
	{
		j = 0;
		while (j < len(g_info.map[i]))
		{
			if ((g_info.map[i][j] == 'N' || g_info.map[i][j] == 'W' ||
						g_info.map[i][j] == 'S' || g_info.map[i][j] == 'E'))
			{
				init_player(g_info.map[i][j]);
				g_player.x = j * TILE_SIZE + 30;
				g_player.y = i * TILE_SIZE + 30;
			}
			j++;
		}
		i++;
	}
}
