/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:50:56 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/23 13:54:07 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 1000
# define WALK_SPEED 15
# define TURN_SPEED 5
# define MAP_ROWS 30000
# define MAP_COLS 30000
# define TILE_SIZE 64
# define NUM_RAYS 4000
# define NSP 10000
# define FOV 60

typedef struct	s_texture {

	void	*xpm_ptr[5];
	int		*data[5];
	int		width[5];
	int		height[5];
	int		bpp;
	int		len;
	int		endian;
}				t_texture;

typedef struct	s_sptexture
{
	void	*img_sprite;
	int		*data;
	int		width;
	int		height;
}				t_sptexture;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_sp;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_sprite {
	float x;
	float y;
	float dst;
	float size;
	float x_ofst;
	float y_ofst;
}				t_sprite[NSP];

typedef struct	s_player{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn;
	int		walk;
	float	angle;
	float	walkspeed;
	float	turnspeed;

}				t_player;

typedef struct	s_ray {
	int		id;
	float	angle;
	float	d;
	int		down;
	int		up;
	int		left;
	int		right;
	float	hitx;
	float	hity;
	float	height;
	int		top;
	int		bottom;
	float	offset;
	int		vertical;
}				t_ray[NUM_RAYS];

typedef struct	s_info{

	int		width;
	int		height;
	char	map[MAP_ROWS][MAP_COLS];
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*sp_texture;
	int		fr;
	int		fg;
	int		fb;
	int		fcolor;
	int		cr;
	int		cg;
	int		cb;
	int		scolor;

}				t_info;

typedef struct	s_check{

	int		r;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		s;
	int		f;
	int		c;
}				t_check;

typedef struct	s_var{

	float	nexthitx;
	float	nexthity;
	float	hitx1;
	float	hitx2;
	float	hity1;
	float	hity2;
	float	xcheck;
	float	ycheck;
	float	d1;
	float	d2;
	float	d;
	int		down;
	int		up;
	int		right;
	int		left;
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
}				t_var;

typedef struct	s_bmp_header
{
	int		width;
	int		height;
	int		bitcount;
	int		width_in_bytes;
	int		imagesize;
	int		bisize;
	int		bfoffbits;
	int		filesize;
	int		biplanes;
}				t_bmp_header;

typedef struct	s_rgb{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct	s_bmp
{
	char		id[2];
	int			file_size;
	int			unused;
	int			offset;
	int			dib;
	int			width;
	int			height;
	char		plane[2];
	char		bpp[2];
	int			compression;
	int			raw_bitmap_size;
	int			resx;
	int			resy;
	int			number_of_colors;
	int			important_colors;
}				t_bmp;

t_var			g_var;
t_sptexture		g_sptexture;
t_sprite		g_sprite;
t_check			g_check;
t_info			g_info;
t_ray			g_ray;
t_player		g_player;

int				g_nsprite;
int				g_rows;
int				g_error;
int				g_p;

int				wich_side(int nb, int id);
void			init_player(char c);
void			find_player();
int				ft_trueline(char *str);
int				ft_empty(char *str);
void			analyse_map2();
void			analyse_map();
void			analyse_info();
char			*new_line(char *str);
int				ft_search_map(char *str);
void			read_map(char *str);
int				ft_search(char *str, char c);
void			sol_color(char **str);
void			floor_color(char **str);
void			get_texture5(char **str);
void			get_texture4(char **str);
void			get_texture3(char **str);
void			get_texture2(char **str);
void			get_texture1(char **str);
int				ft_strcmp(char *s1, char *s2);
void			get_resolution(char **str);
int				ft_atoi(char *str);
void			read_file(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			*ft_calloc(size_t count, size_t size);
char			**ft_split(char const *s, char c);
void			ft_bzero(void *argv, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			ft_putstr(char *str);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				get_next_line(int fd, char **line);
void			put_my_pixel(t_data *data, int x, int y, int color);
void			draw_square(t_data *img, int tile_i, int tile_j);
int				len(char *s);
float			normalizeangle(float g_rayangle);
void			put_my_pixel(t_data *data, int x, int y, int color);
float			to_deg(float angle);
float			to_rad(float angle);
int				wall_check(float x, float y);
void			draw_floor(t_data *img, int id);
void			draw_wall(t_data *img, t_texture texture, int id, int nb);
void			init_textures(t_data *img, t_texture *texture);
void			init_player(char c);
void			wall_data(int id);
int				save_to_bitmap(t_data img);
int				ft_string(char *str);
t_rgb			int_to_rgb(int col);
void			render_sprite(int id, t_data *img);
void			draw_sprite(int id, t_data *img);
void			sprite_cordinate(void);
void			get_spriteimage(t_data *img);
void			sort_sprit(void);
void			g_raycasting(float g_rayangle, int id);
void			horizontal_rc(void);
void			cast_g_rays(t_data *img);
int				keyboard(int x, t_data *img);
int				check_save(char *str);
void			free_args(char **str);

#endif
