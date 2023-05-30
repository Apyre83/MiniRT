/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:17:47 by jbranche          #+#    #+#             */
/*   Updated: 2023/03/28 14:42:17 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	min(float a, float b)
{
	if (a > b)
		return (b);
	return (a);
}

double	deg_to_rad(double a)
{
	return ((a * M_PI) / 180);
}

double	rad_to_deg(double a)
{
	return (a * 180 / M_PI);
}

float	map_zero_to_one(double a)
{
	if (a > 100 || a < 0)
		return (1.0);
	else
		return (a / 100);
}

float	color_percent(int color)
{
	if (color > 255 || color < 0)
		return (1);
	return ((float)color / 255.0);
}
