/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:36:33 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 11:36:31 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		mouse(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->win);
	exit(0);
	return (0);
}

void	first_move(t_data *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx,
			g_info.width, g_info.height, "Cub3D");
	img->img = mlx_new_image(img->mlx,
			g_info.width, g_info.height);
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_length, &img->endian);
	find_player();
}

void	save_screen(t_data img)
{
	save_to_bitmap(img);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_data img;

	if (argc == 2 || argc == 3)
	{
		read_file(argv[1]);
		if (g_error == 0)
		{
			first_move(&img);
			cast_g_rays(&img);
			mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
			if (argc == 3 && check_save(argv[2]))
				save_screen(img);
			mlx_hook(img.win, 2, 1L << 0, keyboard, &img);
			mlx_hook(img.win, 17, 0, mouse, &img);
			mlx_loop(img.mlx);
		}
		else
			ft_putstr("ERROR\nthere is a problem in *.cub file\n");
	}
	else
		ft_putstr("ERROR\nplease add your *.cub file\n");
	return (0);
}
