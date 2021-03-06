/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_rad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 05:01:56 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 05:02:15 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	to_rad(float angle)
{
	angle = angle * (M_PI / 180);
	return (angle);
}
