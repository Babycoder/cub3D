# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 11:29:57 by ayghazal          #+#    #+#              #
#    Updated: 2020/10/30 11:16:13 by ayghazal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = analyse_info.c analyse_map.c analyse_map2.c cast_g_rays.c cub3d.c check_save.c draw_floor.c draw_wall.c find_player.c floor_color.c ft_atoi.c ft_bzero.c ft_calloc.c ft_empty.c ft_putchar.c ft_putstr.c ft_search.c ft_search_map.c ft_split.c ft_strcmp.c ft_string.c ft_trueline.c get_next_line.c get_next_line_utils.c get_resolution.c get_spriteimage.c get_texture1.c get_texture2.c get_texture3.c get_texture4.c get_texture5.c horizontal_rc.c init_player.c init_textures.c int_to_rgb.c keyboard.c len.c new_line.c normalizeangle.c put_my_pixel.c raycasting.c read_file.c read_map.c render_sprite.c save_to_bitmap.c sol_color.c sort_sprite.c sprite_cordinate.c to_deg.c to_rad.c wall_check.c wall_data.c wich_side.c free_args.c
OBJ = analyse_info.o analyse_map.o analyse_map2.o cast_g_rays.o cub3d.o check_save.o draw_floor.o draw_wall.o find_player.o floor_color.o ft_atoi.o ft_bzero.o ft_calloc.o ft_empty.o ft_putchar.o ft_putstr.o ft_search.o ft_search_map.o ft_split.o ft_strcmp.o ft_string.o ft_trueline.o get_next_line.o get_next_line_utils.o get_resolution.o get_spriteimage.o get_texture1.o get_texture2.o get_texture3.o get_texture4.o get_texture5.o horizontal_rc.o init_player.o init_textures.o int_to_rgb.o keyboard.o len.o new_line.o normalizeangle.o put_my_pixel.o raycasting.o read_file.o read_map.o render_sprite.o save_to_bitmap.o sol_color.o sort_sprite.o sprite_cordinate.o to_deg.o to_rad.o wall_check.o wall_data.o wich_side.o free_args.o


GL = mlx_opengl
AK = AppKit
OGL = OpenGL
NAME = cub3D
FLAGS = -Wall -Wextra -Werror

all: cub3D
	
cub3D:
	gcc $(FLAGS) $(SRC) -o $(NAME) -L $(GL) -lmlx  -framework $(OGL) -framework $(AK)
clean:
	rm -rf *.o
fclean: clean
	rm ./cub3D
re : fclean all
