/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 05:26:24 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 05:27:24 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rgb	int_to_rgb(int col)
{
	t_rgb rgb;

	rgb.b = col % 256;
	rgb.g = ((col - rgb.b) / 256) % 256;
	rgb.r = ((col - rgb.b) / (256 * 256)) - (rgb.g / 256);
	return (rgb);
}
