/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:06:47 by lfresnay          #+#    #+#             */
/*   Updated: 2023/03/28 16:10:07 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Ici, additional represente le message de strerror
 */
int	print_error(char *error, char *additional)
{
	ft_printf("Error\n%s", error);
	if (additional)
		ft_printf(additional);
	ft_printf("\n");
	return (1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

/*
 * Renvoie un si le debut de la ligne commence bien par quelque chose
 */
int	ft_is_object(char *line)
{
	if (line[0] == 0 || line[1] == 0 || line[2] == 0)
		return (print_error("Line not formatted: ", line));
	if (*line == 'A' && (ft_isspace(line[1]) || line[1] == 0))
		return (0);
	if (*line == 'C' && (ft_isspace(line[1]) || line[1] == 0))
		return (0);
	if (*line == 'L' && (ft_isspace(line[1]) || line[1] == 0))
		return (0);
	if (ft_strncmp(line, "sp", 2) == 0 && (ft_isspace(line[2]) || line[2] == 0))
		return (0);
	if (ft_strncmp(line, "pl", 2) == 0 && (ft_isspace(line[2]) || line[2] == 0))
		return (0);
	if (ft_strncmp(line, "cy", 2) == 0 && (ft_isspace(line[2]) || line[2] == 0))
		return (0);
	exit(print_error("Undefined identifier at the beginning of line", NULL));
}

void	*ft_free_structure(t_scene *scene)
{
	if (!scene)
		return (NULL);
	if (scene->ambient_lights)
		free(scene->ambient_lights);
	if (scene->cameras)
		free(scene->cameras);
	if (scene->lights)
		free(scene->lights);
	if (scene->spheres)
		free(scene->spheres);
	if (scene->plans)
		free(scene->plans);
	if (scene->cylinders)
		free(scene->cylinders);
	free(scene);
	return (NULL);
}

t_scene	*ft_get_type(t_scene *scene, char *line)
{
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (scene);
	if (ft_is_object(line + i))
		return (ft_free_structure(scene));
	if (line[i] == 'A')
		scene->nb_ambient_lights++;
	if (line[i] == 'C')
		scene->nb_cameras++;
	if (line[i] == 'L')
		scene->nb_lights++;
	if (line[i] == 's')
		scene->nb_spheres++;
	if (line[i] == 'p')
		scene->nb_plans++;
	if (line[i] == 'c')
		scene->nb_cylinders++;
	return (scene);
}
