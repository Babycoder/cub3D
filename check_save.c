/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:51:00 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/23 13:55:00 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_save(char *str)
{
	if (ft_strcmp(str, "--save") == 0)
		return (1);
	else
	{
		ft_putstr("ERROR\nDid u mean '--save'?\n");
		exit(1);
	}
	return (0);
}
