/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wich_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 04:54:01 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 04:55:56 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		wich_side(int nb, int id)
{
	if (g_ray[id].vertical == 1)
	{
		if (g_ray[id].left == 1)
			nb = 0;
		if (g_ray[id].right == 1)
			nb = 1;
	}
	if (g_ray[id].vertical == 0)
	{
		if (g_ray[id].up == 1)
			nb = 2;
		if (g_ray[id].down == 1)
			nb = 3;
	}
	return (nb);
}
