/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 08:59:43 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 09:24:59 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprit(void)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = -1;
	while (++i < g_nsprite)
	{
		j = -1;
		while (++j < g_nsprite - i)
		{
			if (g_sprite[j].dst < g_sprite[j + 1].dst)
			{
				tmp[0] = g_sprite[j];
				g_sprite[j] = g_sprite[j + 1];
				g_sprite[j + 1] = tmp[0];
			}
		}
	}
}
