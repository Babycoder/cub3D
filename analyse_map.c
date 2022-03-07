/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:44:34 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 06:35:20 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	no_wall(int x, int y)
{
	if (g_info.map[y][x + 1] != '0' && g_info.map[y][x + 1] != '2'
			&& g_info.map[y][x + 1] != 'N'
			&& g_info.map[y][x + 1] != '1' && g_info.map[y][x + 1] != 'W'
			&& g_info.map[y][x + 1] != 'S' && g_info.map[y][x + 1] != 'E')
		g_error = 1;
	if (g_info.map[y][x - 1] != '0' && g_info.map[y][x - 1] != '2'
			&& g_info.map[y][x - 1] != 'N' && g_info.map[y][x - 1] != '1'
			&& g_info.map[y][x - 1] != 'W' && g_info.map[y][x - 1] != 'S'
			&& g_info.map[y][x - 1] != 'E')
		g_error = 1;
	if (g_info.map[y + 1][x] != '0' && g_info.map[y + 1][x] != '2'
			&& g_info.map[y + 1][x] != 'N' && g_info.map[y + 1][x] != '1'
			&& g_info.map[y + 1][x] != 'W' && g_info.map[y + 1][x] != 'S'
			&& g_info.map[y + 1][x] != 'E')
		g_error = 1;
	if (g_info.map[y - 1][x] != '0' && g_info.map[y - 1][x] != '2'
			&& g_info.map[y - 1][x] != 'N' && g_info.map[y - 1][x] != '1'
			&& g_info.map[y - 1][x] != 'W' && g_info.map[y - 1][x] != 'S'
			&& g_info.map[y - 1][x] != 'E')
		g_error = 1;
}

void	no_sprite(int x, int y)
{
	if (g_info.map[y][x + 1] != '0' && g_info.map[y][x + 1] != '2'
			&& g_info.map[y][x + 1] != 'N' && g_info.map[y][x + 1] != '1'
			&& g_info.map[y][x + 1] != 'W' && g_info.map[y][x + 1] != 'S'
			&& g_info.map[y][x + 1] != 'E')
		g_error = 1;
	if (g_info.map[y][x - 1] != '0' && g_info.map[y][x - 1] != '2'
			&& g_info.map[y][x - 1] != 'N' && g_info.map[y][x - 1] != '1'
			&& g_info.map[y][x - 1] != 'W' && g_info.map[y][x - 1] != 'S'
			&& g_info.map[y][x - 1] != 'E')
		g_error = 1;
	if (g_info.map[y + 1][x] != '0' && g_info.map[y + 1][x] != '2'
			&& g_info.map[y + 1][x] != 'N' && g_info.map[y + 1][x] != '1'
			&& g_info.map[y + 1][x] != 'W' && g_info.map[y + 1][x] != 'S'
			&& g_info.map[y + 1][x] != 'E')
		g_error = 1;
	if (g_info.map[y - 1][x] != '0' && g_info.map[y - 1][x] != '2'
			&& g_info.map[y - 1][x] != 'N' && g_info.map[y - 1][x] != '1'
			&& g_info.map[y - 1][x] != 'W' && g_info.map[y - 1][x] != 'S'
			&& g_info.map[y - 1][x] != 'E')
		g_error = 1;
}

void	no_plaayer(int x, int y)
{
	if (g_info.map[y][x + 1] != '0' && g_info.map[y][x + 1] != '2'
			&& g_info.map[y][x + 1] != 'N' && g_info.map[y][x + 1] != '1'
			&& g_info.map[y][x + 1] != 'W' && g_info.map[y][x + 1] != 'S'
			&& g_info.map[y][x + 1] != 'E')
		g_error = 1;
	if (g_info.map[y][x - 1] != '0' && g_info.map[y][x - 1] != '2'
			&& g_info.map[y][x - 1] != 'N' && g_info.map[y][x - 1] != '1'
			&& g_info.map[y][x - 1] != 'W' && g_info.map[y][x - 1] != 'S'
			&& g_info.map[y][x - 1] != 'E')
		g_error = 1;
	if (g_info.map[y + 1][x] != '0' && g_info.map[y + 1][x] != '2'
			&& g_info.map[y + 1][x] != 'N' && g_info.map[y + 1][x] != '1'
			&& g_info.map[y + 1][x] != 'W' && g_info.map[y + 1][x] != 'S'
			&& g_info.map[y + 1][x] != 'E')
		g_error = 1;
	if (g_info.map[y - 1][x] != '0' && g_info.map[y - 1][x] != '2'
			&& g_info.map[y - 1][x] != 'N' && g_info.map[y - 1][x] != '1'
			&& g_info.map[y - 1][x] != 'W' && g_info.map[y - 1][x] != 'S'
			&& g_info.map[y - 1][x] != 'E')
		g_error = 1;
}

void	analyse_map(void)
{
	int y;
	int x;

	y = 0;
	while (y < g_rows)
	{
		x = 0;
		while (g_info.map[y][x] != '\0')
		{
			if (g_info.map[y][x] == '0')
				no_wall(x, y);
			if (g_info.map[y][x] == '2')
				no_sprite(x, y);
			if (g_info.map[y][x] == 'N' || g_info.map[y][x] == 'W' ||
					g_info.map[y][x] == 'S' || g_info.map[y][x] == 'E')
				no_plaayer(x, y);
			x++;
		}
		y++;
	}
}
