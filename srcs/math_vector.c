/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:14:38 by jbranche          #+#    #+#             */
/*   Updated: 2023/03/28 14:47:22 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	normalize(t_point vec)
{
	t_point	result;
	float	norm;

	norm = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	if (norm == 0)
		return (vec);
	result.x = vec.x / norm;
	result.y = vec.y / norm;
	result.z = vec.z / norm;
	return (result);
}

float	dot_product(t_point vec1, t_point vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

float	ft_abs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_point	add_points(t_point a, t_point b)
{
	t_point	output;

	output.x = a.x + b.x;
	output.y = a.y + b.y;
	output.z = a.z + b.z;
	return (output);
}

t_point	sub(t_point a, t_point b)
{
	t_point	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}
