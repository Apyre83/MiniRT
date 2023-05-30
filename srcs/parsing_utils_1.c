/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:06:47 by lfresnay          #+#    #+#             */
/*   Updated: 2023/03/28 14:57:04 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_scene	*ft_count_objects(t_scene *result, int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		result = ft_get_type(result, str);
		free(str);
		if (!result)
			return (NULL);
		str = get_next_line(fd);
	}
	if (result->nb_ambient_lights != 1 || result->nb_cameras != 1)
		exit(print_error("It has to be one ambient light and one camera", ""));
	return (result);
}

/*
 * Check les arguments
 *
 * Retourne 0 si tout s'est bien passe, sinon 1 si il y a eu une erreur (
 * 					Le message sera deja envoye dans la fonction)
 */
int	check_args(int argc, char **argv)
{
	int	fd;
	int	length;

	if (argc != 2)
		exit(print_error("Wrong number of arguments", NULL));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(print_error("Can't open file: ", strerror(errno)));
	length = ft_strlen(argv[1]);
	if (length < 3)
		exit(print_error("File isn't a .rt file", NULL));
	if (argv[1][length - 1] != 't' || argv[1][length - 2] != 'r'
		|| argv[1][length - 3] != '.')
		exit(print_error("File isn't a .rt file", NULL));
	close(fd);
	return (0);
}

t_scene	*ft_init_structure(int fd)
{
	t_scene	*result;

	result = ft_calloc(1, sizeof(t_scene));
	if (!result)
		return (NULL);
	result = ft_count_objects(result, fd);
	if (!result)
		return (NULL);
	result->ambient_lights = ft_calloc(result->nb_ambient_lights + 1,
			sizeof(t_ambientLights));
	result->cameras = ft_calloc(result->nb_cameras + 1, sizeof(t_camera));
	result->lights = ft_calloc(result->nb_lights + 1, sizeof(t_light));
	result->spheres = ft_calloc(result->nb_spheres + 1, sizeof(t_sphere));
	result->plans = ft_calloc(result->nb_plans + 1, sizeof(t_plan));
	result->cylinders = ft_calloc(result->nb_cylinders + 1, sizeof(t_cylinder));
	result->size_al = 1;
	result->size_ca = result->nb_cameras;
	result->size_li = result->nb_lights;
	result->size_sp = result->nb_spheres;
	result->size_pl = result->nb_plans;
	result->size_cy = result->nb_cylinders;
	close(fd);
	return (result);
}

double	get_double_first(char *str, int *i, char c)
{
	double	result;

	result = 0;
	while (str[*i] && str[*i] != '.' && str[*i] != c && !ft_isspace(str[*i]))
	{
		if (!ft_isdigit(str[*i]))
			exit(print_error("Character is not a digit in parsing.", NULL));
		result *= 10;
		result += (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

double	get_double_second(char *str, int *i, char c)
{
	int		j;
	double	result;

	result = 0;
	j = 1;
	(*i)++;
	while (str[*i] && str[*i] != c && !ft_isspace(str[*i]))
	{
		if (!ft_isdigit(str[*i]))
			exit(print_error("Character is not a digit in parsing.", NULL));
		result += (str[*i] - '0') / (__exp10(j));
		j++;
		(*i)++;
	}
	return (result);
}
