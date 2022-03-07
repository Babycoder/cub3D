/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 06:12:21 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 06:13:29 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(t_data *img, int id)
{
	int i;

	i = 0;
	while (i < g_ray[id].top)
	{
		put_my_pixel(img, id, i, g_info.fcolor);
		i++;
	}
	i = g_ray[id].bottom;
	while (i < g_info.height)
	{
		put_my_pixel(img, id, i, g_info.scolor);
		i++;
	}
}
