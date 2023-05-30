/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:08:17 by jbranche          #+#    #+#             */
/*   Updated: 2023/03/28 09:23:27 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	get_color(t_color color)
{
	color.rgbt = color.t << 24 | color.r << 16 | color.g << 8 | color.b;
	return (color);
}

t_color	set_color(t_color color)
{
	color.t = color.rgbt >> 24 & 0xFF;
	color.r = color.rgbt >> 16 & 0xFF;
	color.g = color.rgbt >> 8 & 0xFF;
	color.b = color.rgbt & 0xFF;
	return (color);
}

t_color	mix_color(t_color obj, t_ambientLights ambiant)
{
	t_color	output;

	output.t = 0;
	output.r = average(obj.r, ambiant.color.r) * ambiant.light;
	output.g = average(obj.g, ambiant.color.g) * ambiant.light;
	output.b = average(obj.b, ambiant.color.b) * ambiant.light;
	output.is_active = 1;
	return (output);
}

t_color	init_color(int ra, int ga, int ba)
{
	t_color	output;

	output.r = ra;
	output.g = ga;
	output.b = ba;
	output.t = 0;
	return (output);
}

t_color	saturate(float d, t_color color, double intensity)
{
	color.r = min(255, color.r + ((d * intensity)) * 255);
	color.g = min(255, color.g + ((d * intensity)) * 255);
	color.b = min(255, color.b + ((d * intensity)) * 255);
	color.t = 0;
	color.is_active = 1;
	return (color);
}
