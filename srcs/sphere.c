/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:08:52 by lfresnay          #+#    #+#             */
/*   Updated: 2023/03/28 14:25:01 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	get_b_sphere(t_point origin, t_scene *scene, int i)
{
	float	output;

	output = 2.0 * scene->cameras[0].point.x * origin.x
		- 2.0 * scene->spheres[i].point.x * origin.x
		+ 2.0 * scene->cameras[0].point.y * origin.y
		- 2.0 * scene->spheres[i].point.y * origin.y
		+ 2.0 * scene->cameras[0].point.z * origin.z
		- 2.0 * scene->spheres[i].point.z * origin.z;
	return (output);
}

float	get_c_sphere(t_scene *scene, int i)
{
	float	output;

	output = pow(scene->cameras[0].point.x, 2)
		- 2.0 * scene->spheres[i].point.x * scene->cameras[0].point.x
		+ pow(scene->spheres[i].point.x, 2)
		+ pow(scene->cameras[0].point.y, 2)
		- 2.0 * scene->spheres[i].point.y * scene->cameras[0].point.y
		+ pow(scene->spheres[i].point.y, 2)
		+ pow(scene->cameras[0].point.z, 2)
		- 2.0 * scene->spheres[i].point.z * scene->cameras[0].point.z
		+ pow(scene->spheres[i].point.z, 2)
		- pow(scene->spheres[i].diameter / 2, 2);
	return (output);
}

float	sphere_resolve(t_point origin, t_scene *scene, int i, t_point *normal)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	sol;

	a = dot_product(origin, origin);
	b = get_b_sphere(origin, scene, i);
	c = get_c_sphere(scene, i);
	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0)
		return (INFINITY);
	sol = (-b - sqrt(discriminant)) / (2.0 * a);
	if (sol < 0)
		return (INFINITY);
	*normal = sub(add_points(scene->cameras[0].point,
				scalar_multiply_bis(origin, sol)), scene->spheres[i].point);
	*normal = normalize(*normal);
	return (sol);
}

void	get_sphere_discri(t_disnor *disnor, t_scene *scene, t_point origin,
		t_color *output)
{
	float	tmp;
	int		i;
	t_point	tmp_2;

	i = 0;
	while (i < scene->size_sp)
	{
		tmp = sphere_resolve(origin, scene, i, &tmp_2);
		if (disnor->sol2 > tmp)
		{
			disnor->normal = tmp_2;
			disnor->sol2 = tmp;
			*output = scene->spheres[i].color;
		}
		i++;
	}
}
