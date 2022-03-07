/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 06:09:30 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 06:11:05 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_data *img, t_texture texture, int id, int nb)
{
	float i;
	float t;
	float b;
	float factor;

	i = 0;
	b = g_ray[id].bottom;
	t = g_ray[id].top;
	factor = (float)texture.height[nb] / g_ray[id].height;
	while (t < b)
	{
		put_my_pixel(img, id, t,
				texture.data[nb][(int)(i) *
				texture.width[nb] + (int)g_ray[id].offset]);
		t++;
		i += factor;
	}
}
