/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:32:32 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 06:00:53 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_search_map(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == ' ' || str[i] == 'N' ||
				str[i] == '2' || str[i] == '0' ||
				str[i] == 'W' || str[i] == 'S' || str[i] == 'E')
			i++;
		else
			return (0);
	}
	return (1);
}