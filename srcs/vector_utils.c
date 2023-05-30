/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:14:38 by jbranche          #+#    #+#             */
/*   Updated: 2023/03/28 14:47:19 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	vec_dot_product(t_point vec1, t_point vec2)
{
	t_point	output;

	output.x = vec1.x * vec2.x;
	output.y = vec1.y * vec2.y;
	output.z = vec1.z * vec2.z;
	return (output);
}

t_point	cross_product(t_point a, t_point b)
{
	t_point	output;

	output.x = a.y * b.z - a.z * b.y;
	output.y = a.z * b.x - a.x * b.z;
	output.z = a.x * b.y - a.y * b.x;
	return (output);
}

t_point	oposite_point(t_point a)
{
	t_point	output;

	output.x = -a.x;
	output.y = -a.y;
	output.z = -a.z;
	return (output);
}

void	scalar_multiply(t_point *vec, float n)
{
	vec->x *= n;
	vec->y *= n;
	vec->z *= n;
}

t_point	scalar_multiply_bis(t_point vec, float n)
{
	t_point	output;

	output.x = n * vec.x;
	output.y = n * vec.y;
	output.z = n * vec.z;
	return (output);
}
