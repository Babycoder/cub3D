/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:07:18 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 06:07:36 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_color_int(void)
{
	if (g_info.fr < 0 || g_info.fr > 255 || g_info.fg < 0 ||
			g_info.fg > 255 || g_info.fb < 0 || g_info.fb > 255)
		g_error = 1;
	g_info.fcolor = (g_info.fr <<= 16) + (g_info.fg <<= 8) + g_info.fb;
}

void	free_floor(char **s)
{
	g_info.fr = ft_atoi(s[0]);
	g_info.fg = ft_atoi(s[1]);
	g_info.fb = ft_atoi(s[2]);
	free(s[0]);
	free(s[1]);
	free(s[2]);
	free(s);
}

int		floor_clean(char *str)
{
	int i;
	int p;

	i = 0;
	p = 0;
	while (str[i])
	{
		if (str[i] == ',')
			p++;
		i++;
	}
	if (p != 2)
		return (0);
	return (1);
}

void	floor_color(char **str)
{
	char **s;

	g_check.f++;
	if (!str[1] || str[2] || !floor_clean(str[1]))
		g_error = 1;
	else
	{
		s = ft_split(str[1], ',');
		if (!s[0] || !s[1] || !s[2] || s[3])
			g_error = 1;
		else
		{
			if (!ft_string(s[0]) || !ft_string(s[1]) || !ft_string(s[2]))
				g_error = 1;
			else
			{
				free_floor(s);
				free(str[0]);
				free(str[1]);
			}
		}
		floor_color_int();
	}
}
