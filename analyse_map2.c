/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:57:15 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 06:17:35 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	analyse_map2(void)
{
	int x;
	int y;
	int p;

	p = 0;
	y = 0;
	while (y < g_rows)
	{
		x = 0;
		while (g_info.map[y][x] != '\0')
		{
			if (g_info.map[y][x] == 'N' || g_info.map[y][x] == 'W' ||
					g_info.map[y][x] == 'S' || g_info.map[y][x] == 'E')
				p++;
			if (g_info.map[y][x] == '2')
				g_nsprite++;
			x++;
		}
		y++;
	}
	if (p != 1)
		g_error = 1;
}
