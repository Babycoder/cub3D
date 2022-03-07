/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizeangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 05:40:11 by ayghazal          #+#    #+#             */
/*   Updated: 2020/10/18 05:40:54 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	normalizeangle(float rayangle)
{
	rayangle = remainderf(rayangle, 360);
	if (rayangle < 0)
		rayangle = 360 + rayangle;
	return (rayangle);
}
