/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spriteimage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 08:56:54 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 09:26:32 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_spriteimage(t_data *img)
{
	g_sptexture.img_sprite = mlx_xpm_file_to_image(img->mlx, g_info.sp_texture,
			&g_sptexture.width, &g_sptexture.height);
}
