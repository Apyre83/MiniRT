/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:06:47 by lfresnay          #+#    #+#             */
/*   Updated: 2023/03/28 16:08:45 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_scene	*line_is_cylinder(t_scene *scene, char *line)
{
	int			j;
	int			i;
	t_cylinder	cylinder;

	i = 2;
	increment_i_and_check_line(line, &i);
	cylinder.point = ft_get_point(line, &i, INFINITY, INFINITY);
	increment_i_and_check_line(line, &i);
	cylinder.orientation = ft_get_point(line, &i, -1.0, 1.0);
	increment_i_and_check_line(line, &i);
	cylinder.diameter = ft_get_double(line + i, INFINITY, INFINITY, 0);
	increment_i_and_isspace(line, &i);
	cylinder.height = ft_get_double(line + i, INFINITY, INFINITY, 0);
	increment_i_and_isspace(line, &i);
	cylinder.color = ft_get_color(line, &i);
	j = 0;
	while (j < scene->nb_cylinders - 1)
		j++;
	scene->cylinders[j] = cylinder;
	scene->nb_cylinders = j;
	check_end(line, &i);
	return (scene);
}

t_scene	*ft_parse_line(t_scene *scene, char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == 0)
		return (scene);
	if (ft_is_object(line + i))
		return (ft_free_structure(scene));
	if (line[i] == 'A')
		return (line_is_ambient_light(scene, line + i));
	if (line[i] == 'C')
		return (line_is_camera(scene, line + i));
	if (line[i] == 'L')
		return (line_is_light(scene, line + i));
	if (line[i] == 's')
		return (line_is_sphere(scene, line + i));
	if (line[i] == 'p')
		return (line_is_plan(scene, line + i));
	if (line[i] == 'c')
		return (line_is_cylinder(scene, line + i));
	return (scene);
}

/*
 * Fonction principale du parsing, a appeler dans le main
 *
 * Renvoie un pointeur vers une structure contenant tous les elements
 * Sinon NULL si il y a eu une erreur
 * 				(le message sera deja envoye dans la fonction)
 *
 *
 * Dans l'ordre:
 *		Checker si fichier existe
 *		Checker fichier
 *		Creer structures
 *		Return tout
 */
t_scene	*ft_parse(char	*file)
{
	t_scene	*result;
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	result = ft_init_structure(fd);
	if (!result)
		exit(print_error("Could not allocate memory for scene", NULL));
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		result = ft_parse_line(result, str);
		free(str);
		str = get_next_line(fd);
	}
	return (result);
}
