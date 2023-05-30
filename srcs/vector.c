/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:25:30 by jbranche          #+#    #+#             */
/*   Updated: 2023/03/28 14:50:39 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	init_vec(float xa, float ya, float za)
{
	t_point	output;

	output.x = xa;
	output.y = ya;
	output.z = za;
	return (output);
}

double	distance_between_points(t_point a, t_point b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)));
}
