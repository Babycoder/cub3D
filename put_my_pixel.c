/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_my_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 05:38:04 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 05:38:48 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_my_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < g_info.width && y < g_info.height)
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
	}
}
