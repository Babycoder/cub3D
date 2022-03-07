/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:39:21 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 05:52:39 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_resolution(char **str)
{
	g_check.r++;
	if (!str[1] || !str[2] || str[3] ||
		!ft_string(str[1]) || !ft_string(str[2]))
		g_error = 1;
	else
	{
		g_info.width = ft_atoi(str[1]);
		g_info.height = ft_atoi(str[2]);
		if (g_info.width < 0 || g_info.height < 0)
			g_error = 1;
		if (g_info.width > 2560)
			g_info.width = 2560;
		if (g_info.height > 1440)
			g_info.height = 1440;
		free(str[0]);
		free(str[1]);
		free(str[2]);
	}
}
