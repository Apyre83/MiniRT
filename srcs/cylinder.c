/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:08:52 by lfresnay          #+#    #+#             */
/*   Updated: 2023/03/28 14:29:37 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	get_sol_cylinder(t_point dir_cross, t_point cross, float diameter,
		float *sol)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;

	a = dot_product(dir_cross, dir_cross);
	b = 2.0 * dot_product(dir_cross, cross);
	c = dot_product(cross, cross) - pow(diameter / 2, 2);
	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0)
	{
		sol[0] = INFINITY;
		sol[1] = INFINITY;
	}
	else
	{
		sol[1] = (-b - sqrt(discriminant)) / (2.0 * a);
		sol[0] = (-b + sqrt(discriminant)) / (2.0 * a);
	}
}

float	calculate_sol0_cylinder(t_scene *scene, t_point ray, t_solcy s,
		t_point *normal)
{
	t_point		poi;
	float		height;
	t_cylinder	cylinder;
	float		sol;

	cylinder = s.cylinder;
	sol = s.sol;
	if (sol < 0 || sol == INFINITY)
		return (INFINITY);
	poi = add_points(scene->cameras[0].point, scalar_multiply_bis(ray, sol));
	height = dot_product(sub(poi, cylinder.point), cylinder.orientation);
	if (height < 0 || height > cylinder.height)
		return (INFINITY);
	*normal = sub(add_points(scalar_multiply_bis(
					cylinder.orientation, height), cylinder.point), poi);
	return (sol);
}

float	cylinder_resolve(t_point ray, t_scene *scene, int i, t_point *normal)
{
	t_point		poi;
	float		height;
	t_cylinder	cylinder;
	float		sol[2];
	t_solcy		s;

	cylinder = scene->cylinders[i];
	cylinder.orientation = normalize(cylinder.orientation);
	get_sol_cylinder(cross_product(ray, cylinder.orientation),
		cross_product(sub(scene->cameras[0].point, cylinder.point),
			cylinder.orientation), cylinder.diameter, &sol[0]);
	if (sol[1] < 0 || sol[1] == INFINITY)
		return (INFINITY);
	poi = add_points(scene->cameras[0].point,
			scalar_multiply_bis(ray, sol[1]));
	height = dot_product(sub(poi, cylinder.point), cylinder.orientation);
	if (!(height < 0 || height > cylinder.height))
	{
		*normal = sub(poi, add_points(scalar_multiply_bis(
						cylinder.orientation, height), cylinder.point));
		return (sol[1]);
	}
	s.sol = sol[0];
	s.cylinder = cylinder;
	return (calculate_sol0_cylinder(scene, ray, s, normal));
}

void	get_cylinder_discri(t_disnor *disnor, t_scene *scene, t_point origin,
		t_color *output)
{
	float	tmp;
	int		i;
	t_point	tmp_2;

	i = 0;
	while (i < scene->size_cy)
	{
		tmp = cylinder_resolve(origin, scene, i, &tmp_2);
		if (disnor->sol2 > tmp)
		{
			disnor->normal = tmp_2;
			disnor->sol2 = tmp;
			*output = scene->cylinders[i].color;
		}
		i++;
	}
}
