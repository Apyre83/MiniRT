/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:06:47 by lfresnay          #+#    #+#             */
/*   Updated: 2023/03/28 16:08:27 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * A parser dans l'ordre:
 * 		ambient light
 * 		color
 */
t_scene	*line_is_ambient_light(t_scene *scene, char *line)
{
	int				i;
	int				j;
	double			temp;
	t_ambientLights	ambient_light;
	t_color			color;

	i = 1;
	while (ft_isspace(line[i]))
		i++;
	if (!line[i])
		exit(print_error("Parsing error: ", "expected character"));
	temp = ft_get_double(line + i, 0.0, 1.0, 0);
	ambient_light.light = temp;
	increment_i_and_isspace(line, &i);
	color = ft_get_color(line, &i);
	ambient_light.color = color;
	j = 0;
	while (!&scene->ambient_lights[j])
		j++;
	scene->ambient_lights[j] = ambient_light;
	check_end(line, &i);
	return (scene);
}

t_scene	*line_is_camera(t_scene *scene, char *line)
{
	int			j;
	int			i;
	t_camera	camera;

	i = 1;
	increment_i_and_check_line(line, &i);
	camera.point = ft_get_point(line, &i, INFINITY, INFINITY);
	while (ft_isspace(line[i]))
		i++;
	camera.orientation = ft_get_point(line, &i, -1.0, 1.0);
	if (camera.orientation.y == 0.5 || camera.orientation.y == -0.5)
		camera.orientation.y -= 0.001;
	increment_i_and_check_digit(line, &i);
	camera.fov = ft_get_int(line + i, 0, 180, 0);
	increment_i_and_isspace(line, &i);
	j = 0;
	while (!&scene->cameras[j])
		j++;
	scene->cameras[j] = camera;
	check_end(line, &i);
	return (scene);
}

t_scene	*line_is_light(t_scene *scene, char *line)
{
	int		j;
	int		i;
	t_light	light;

	if (scene->nb_lights != 1)
		exit(print_error("Parsing error: ", "there are too many lights"));
	i = 1;
	increment_i_and_check_line(line, &i);
	light.point = ft_get_point(line, &i, INFINITY, INFINITY);
	increment_i_and_check_line(line, &i);
	light.luminosity = ft_get_double(line + i, 0.0, 1.0, 0);
	increment_i_and_isspace(line, &i);
	j = 0;
	while (!&scene->lights[j])
		j++;
	scene->lights[j] = light;
	check_end(line, &i);
	return (scene);
}

t_scene	*line_is_sphere(t_scene *scene, char *line)
{
	int			j;
	int			i;
	t_sphere	sphere;

	i = 2;
	increment_i_and_check_line(line, &i);
	sphere.point = ft_get_point(line, &i, INFINITY, INFINITY);
	increment_i_and_check_line(line, &i);
	sphere.diameter = ft_get_double(line + i, INFINITY, INFINITY, 0);
	increment_i_and_isspace(line, &i);
	sphere.color = ft_get_color(line, &i);
	j = 0;
	while (j < scene->nb_spheres - 1)
		j++;
	scene->spheres[j] = sphere;
	scene->nb_spheres = j;
	check_end(line, &i);
	return (scene);
}

t_scene	*line_is_plan(t_scene *scene, char *line)
{
	int			j;
	int			i;
	t_plan		plan;

	i = 2;
	increment_i_and_check_line(line, &i);
	plan.point = ft_get_point(line, &i, INFINITY, INFINITY);
	increment_i_and_check_line(line, &i);
	plan.orientation = ft_get_point(line, &i, -1.0, 1.0);
	increment_i_and_check_line(line, &i);
	plan.color = ft_get_color(line, &i);
	j = 0;
	while (j < scene->nb_plans - 1)
		j++;
	scene->plans[j] = plan;
	scene->nb_plans = j;
	check_end(line, &i);
	return (scene);
}
