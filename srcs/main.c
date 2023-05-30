/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:08:52 by lfresnay          #+#    #+#             */
/*   Updated: 2023/03/28 15:35:10 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Si le vecteur n est normal a other alors
 * 		
 * 		n dot other = 0
 *		n.x * other.x + n.y * other.y + n.z * other.z = 0
 *
 *		On pose n.z = 0
 *		n.x * other.x + n.y * other.y = 0
 *		n.y = - (n.x * other.x) / other.y
 *
 *		On pose n.x = 1
 *		alors n.y = -other.x / other.y
 *
 */
/*
*		On cherche l'intersection
*
*		point.xyz est le point appartenant a un plan
*
*		On sait que le rayon est:
*			c = cam.c + t * ray.c
*
*		Le plan est d'equation:
 *			n.x * (x - point.x) + n.y * (y - point.y) + n.z * (z - point.z) = 0
 *
 *		On obtient alors:
 *			
 *			n.x * (cam.x + t * ray.x - point.x) + n.y *
 *						(cam.y + t * ray.y - point.y
 *				+ n.z * (cam.z + t * ray.z - point.z) = 0
 *
 *			soit
 *
 *			n.x * cam.x + n.x * t * ray.x - n.x * point.x + n.y * cam.y 
 *				+ n.t * t * ray.y - n.y * point.y
 *				+ n.z * cam.z + n.z * t * ray.z - n.z * point.z = 0
 *
 *			soit
 *
 *			t =	(point.x * n.x + point.y * n.y + point.z * n.z -
 *				n.x * cam.x - n.y * cam.y - n.z * cam.z) /
 *				(ray.x * n.x + ray.y * n.y + ray.z * n.z)
 *
 *			xc = start point of the ray = camera
 */
float	plan_resolve(t_point ray, t_scene *scene, int i, t_point *normal)
{
	t_point	n;
	t_point	point;
	t_point	cam;
	float	a;
	float	t;

	point = scene->plans[i].point;
	cam = scene->cameras->point;
	n = vec_dot_product(ray, scene->plans[i].orientation);
	a = dot_product(ray, n);
	if (a == 0 || isnan(a))
		return (INFINITY);
	t = (point.x * n.x + point.y * n.y + point.z * n.z
			- n.x * cam.x - n.y * cam.y - n.z * cam.z) / a;
	t = dot_product(sub(scene->plans[i].point, scene->cameras[0].point), n) / a;
	if (t < 0)
		return (INFINITY);
	*normal = scene->plans[i].orientation;
	normal->y = -normal->y;
	*normal = normalize(*normal);
	return (t);
}

t_color	do_something(t_point point, t_scene *scene)
{
	t_color		output;
	float		d;
	t_point		hit_point;
	t_point		light_dir;
	t_disnor	a;

	output = get_all_discri(&a, scene, point);
	output = mix_color(output, *scene->ambient_lights);
	output.is_active = 1;
	if (a.sol2 == INFINITY)
	{
		output.rgbt = 0x00000000;
		return (output);
	}
	hit_point = add_points(scene->cameras->point,
			scalar_multiply_bis(point, a.sol2));
	light_dir = sub(scene->lights->point, hit_point);
	light_dir = normalize(light_dir);
	d = max(dot_product(a.normal, light_dir), 0.0f);
	output = saturate(d, output, max(scene->lights->luminosity
				- map_zero_to_one(distance_between_points(hit_point,
						scene->lights->point)), 0.0));
	output = get_color(output);
	return (output);
}

void	main_loop(t_scene *scene, t_data *img)
{
	float	x;
	float	y;
	t_point	point;
	t_color	color;

	x = 0;
	while (x < 500)
	{
		y = 0;
		while (y < 500)
		{
			point = get_ray(scene, x / 500, y / 500);
			color = do_something(point, scene);
			my_mlx_pixel_put(img, x, y, color.rgbt);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_data	img;
	t_vars	vars;
	t_scene	*scene;

	if (check_args(argc, argv) != 0)
		return (1);
	scene = ft_parse(argv[1]);
	vars.mlx = mlx_init();
	vars.scene = scene;
	vars.win = mlx_new_window(vars.mlx, 500, 500, "MiniRt");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	main_loop(scene, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
