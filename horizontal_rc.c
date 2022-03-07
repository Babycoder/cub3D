/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:03:08 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 10:03:42 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal_rc(void)
{
	while (wall_check(g_var.xintercept, g_var.yintercept))
	{
		g_var.xintercept += g_var.xstep;
		g_var.yintercept += g_var.ystep;
	}
	if (g_var.up)
		g_var.yintercept++;
	g_var.hitx1 = g_var.xintercept;
	g_var.hity1 = g_var.yintercept;
	g_var.d1 = (float)sqrt((g_var.hitx1 - g_player.x) *
		(g_var.hitx1 - g_player.x) + (g_var.hity1 - g_player.y) *
		(g_var.hity1 - g_player.y));
}
