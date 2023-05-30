/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:08:52 by lfresnay          #+#    #+#             */
/*   Updated: 2023/03/28 14:34:10 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	get_normal(t_point other)
{	
	t_point	result;

	result.x = 1;
	result.y = -1 * result.x * other.x / other.y;
	result.z = 0;
	return (result);
}

void	get_plan_discri(t_disnor *disnor, t_scene *scene, t_point origin,
		t_color *output)
{
	float	tmp;
	int		i;
	t_point	tmp_2;

	i = 0;
	while (i < scene->size_pl)
	{
		tmp = plan_resolve(origin, scene, i, &tmp_2);
		if (disnor->sol2 > tmp)
		{
			disnor->normal = tmp_2;
			disnor->sol2 = tmp;
			*output = scene->plans[i].color;
		}
		i++;
	}
}

t_color	get_all_discri(t_disnor *disnor, t_scene *scene, t_point origin)
{
	t_color	output;

	disnor->sol2 = INFINITY;
	get_sphere_discri(disnor, scene, origin, &output);
	get_cylinder_discri(disnor, scene, origin, &output);
	get_plan_discri(disnor, scene, origin, &output);
	return (output);
}

t_point	get_lookat(t_point lookfrom, t_scene *scene)
{
	t_point	output;
	float	dir_x;
	float	dir_y;

	dir_x = scene->cameras[0].orientation.x;
	dir_y = scene->cameras[0].orientation.y;
	output = lookfrom;
	output.x += 1 - 2 * (max(ft_abs(dir_y), ft_abs(dir_x)));
	if (dir_x < 0)
		output.z += -4 * pow(0.5 - ft_abs(dir_x), 2) + 1;
	else
		output.z -= -4 * pow(0.5 - ft_abs(dir_x), 2) + 1;
	if (dir_y < 0)
		output.y += -4 * pow(0.5 - ft_abs(dir_y), 2) + 1;
	else
		output.y -= -4 * pow(0.5 - ft_abs(dir_y), 2) + 1;
	return (output);
}

t_point	get_ray(t_scene *scene, float i, float j)
{
	t_point	output;
	t_ray	s;

	s.lookfrom = scene->cameras[0].point;
	s.lookat = get_lookat(s.lookfrom, scene);
	s.vup = init_vec(0.0, 1.0, 0.0);
	s.h = tan(deg_to_rad(scene->cameras[0].fov) / 2.0);
	s.w = normalize(add_points(s.lookfrom, oposite_point(s.lookat)));
	s.u = normalize(cross_product(s.vup, s.w));
	s.v = cross_product(s.w, s.u);
	s.hori = scalar_multiply_bis(s.u, 2.0 * s.h);
	s.vert = scalar_multiply_bis(s.v, 2.0 * s.h);
	s.lower_left_corner = sub(sub(sub(s.lookfrom, scalar_multiply_bis(s.hori,
						1 / 2.0)), scalar_multiply_bis(s.vert, 1 / 2.0)), s.w);
	output = sub(add_points(add_points(s.lower_left_corner, scalar_multiply_bis(
						s.hori, i)), scalar_multiply_bis(s.vert, j)),
			s.lookfrom);
	return (output);
}
