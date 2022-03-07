/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:25:05 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/26 14:55:42 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	second_args(char *ch, char **str)
{
	int i;

	i = 0;
	if (ft_strcmp(ch, "R") == 0)
		get_resolution(str);
	else if (ft_strcmp(ch, "NO") == 0)
		get_texture1(str);
	else if (ft_strcmp(ch, "SO") == 0)
		get_texture2(str);
	else if (ft_strcmp(ch, "WE") == 0)
		get_texture3(str);
	else if (ft_strcmp(ch, "EA") == 0)
		get_texture4(str);
	else if (ft_strcmp(ch, "S") == 0)
		get_texture5(str);
	else if (ft_strcmp(ch, "F") == 0)
		floor_color(str);
	else if (ft_strcmp(ch, "C") == 0)
		sol_color(str);
	else
		free_args(str);
}

void	map_args(char *line, char **ch)
{
	if (ft_search_map(line) && (ft_empty(line) == 0))
		g_p = 1;
	if (g_p == 1)
		read_map(line);
	free(ch);
}

void	first_args(int fd)
{
	char	*line;
	char	**ch;
	int		r;

	g_p = 0;
	while (1)
	{
		r = get_next_line(fd, &line);
		if (ft_empty(line) || ft_trueline(line) || ft_search_map(line))
		{
			ch = ft_split(line, ' ');
			if (*ch)
				second_args(ch[0], ch);
			map_args(line, ch);
			free(line);
			if (r == 0)
				break ;
		}
		else
		{
			free(line);
			g_error = 1;
			break ;
		}
	}
}

int		check_file(char *s)
{
	int ln;

	ln = len(s);
	if (s[ln - 1] != 'b' || s[ln - 2] != 'u' ||
			s[ln - 3] != 'c' || s[ln - 4] != '.')
		return (0);
	return (1);
}

void	read_file(char *s)
{
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		g_error = 1;
	else if (check_file(s))
	{
		first_args(fd);
		analyse_map();
		analyse_map2();
		analyse_info();
	}
	else
		g_error = 1;
}
