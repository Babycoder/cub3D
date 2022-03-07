/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 06:15:52 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 06:16:06 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	analyse_info(void)
{
	if (g_check.r != 1 || g_check.no != 1 || g_check.so != 1 || g_check.we != 1)
		g_error = 1;
	if (g_check.ea != 1 || g_check.s != 1 || g_check.f != 1 || g_check.c != 1)
		g_error = 1;
}
