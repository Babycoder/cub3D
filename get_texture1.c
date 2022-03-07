/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:50:57 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/26 14:52:42 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture1(char **str)
{
	int	fd;
	int	ln;

	if (str[1] && !str[2])
	{
		g_check.no++;
		fd = open(str[1], O_RDONLY);
		if (fd < 0)
			g_error = 1;
		if (fd > 0)
		{
			ln = len(str[1]);
			if (str[1][ln - 1] != 'm' || str[1][ln - 2] != 'p' ||
					str[1][ln - 3] != 'x' || str[1][ln - 4] != '.')
				g_error = 1;
		}
		g_info.no_texture = str[1];
		free(str[0]);
	}
	else
		g_error = 1;
}
