/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:15:07 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 05:09:27 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sol_color_int(void)
{
	if (g_info.cr < 0 || g_info.cr > 255 || g_info.cg < 0 ||
			g_info.cg > 255 || g_info.cb < 0 || g_info.cb > 255)
		g_error = 1;
	g_info.scolor = (g_info.cr <<= 16) + (g_info.cg <<= 8) + g_info.cb;
}

void	free_sol(char **s)
{
	g_info.cr = ft_atoi(s[0]);
	g_info.cg = ft_atoi(s[1]);
	g_info.cb = ft_atoi(s[2]);
	free(s[0]);
	free(s[1]);
	free(s[2]);
	free(s);
}

int		sol_clean(char *str)
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

void	sol_color(char **str)
{
	char **s;

	g_check.c++;
	if (!str[1] || str[2] || !sol_clean(str[1]))
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
				free_sol(s);
				free(str[0]);
				free(str[1]);
			}
		}
		sol_color_int();
	}
}
