/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 05:43:27 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 05:45:42 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	to_exit(void)
{
	ft_putstr("ERROR\n[Invalid argument]\n");
	exit(1);
}

void	init_textures(t_data *img, t_texture *texture)
{
	if (!(texture->xpm_ptr[0] = mlx_xpm_file_to_image(img->mlx,
		g_info.we_texture, &texture->width[0], &texture->height[0])))
		to_exit();
	texture->data[0] = (int *)mlx_get_data_addr(texture->xpm_ptr[0],
			&texture->bpp, &texture->len, &texture->endian);
	if (!(texture->xpm_ptr[1] = mlx_xpm_file_to_image(img->mlx,
			g_info.ea_texture, &texture->width[1], &texture->height[1])))
		to_exit();
	texture->data[1] = (int *)mlx_get_data_addr(texture->xpm_ptr[1],
			&texture->bpp, &texture->len, &texture->endian);
	if (!(texture->xpm_ptr[2] = mlx_xpm_file_to_image(img->mlx,
			g_info.no_texture, &texture->width[2], &texture->height[2])))
		to_exit();
	texture->data[2] = (int *)mlx_get_data_addr(texture->xpm_ptr[2],
			&texture->bpp, &texture->len, &texture->endian);
	if (!(texture->xpm_ptr[3] = mlx_xpm_file_to_image(img->mlx,
			g_info.so_texture, &texture->width[3], &texture->height[3])))
		to_exit();
	texture->data[3] = (int *)mlx_get_data_addr(texture->xpm_ptr[3],
			&texture->bpp, &texture->len, &texture->endian);
}
