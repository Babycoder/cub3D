/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 05:46:39 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 05:46:58 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(char c)
{
	if (c == 'E')
		g_player.angle = 0;
	if (c == 'S')
		g_player.angle = 90;
	if (c == 'W')
		g_player.angle = 180;
	if (c == 'N')
		g_player.angle = 270;
}
