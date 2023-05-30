/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:06:47 by lfresnay          #+#    #+#             */
/*   Updated: 2023/03/28 16:06:00 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_get_sign(char *str, int *i)
{
	if (str[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	if (str[*i] == '+')
		(*i)++;
	return (1);
}

/*
 * Recuperer le double dans une str et check si il est entre range min et max
 */
double	ft_get_double(char *str, double range_min, double range_max, char c)
{
	int		i;
	double	result;
	int		sign;

	i = 0;
	result = 0;
	sign = ft_get_sign(str, &i);
	if (!ft_isdigit(str[i]))
		exit(print_error("Parsing error: expected float", NULL));
	result = get_double_first(str, &i, c);
	if ((range_max != INFINITY && result * sign > range_max)
		|| (range_min != INFINITY && result * sign < range_min))
		exit(print_error("Character is not a digit in parsing.", NULL));
	if (str[i] != '.' && str[i])
		return (result * sign);
	result += get_double_second(str, &i, c);
	if ((range_max != INFINITY && result * sign > range_max)
		|| (range_min != INFINITY && result * sign < range_min))
		exit(print_error("Character is not a digit in parsing.", NULL));
	return (result * sign);
}

int	ft_get_int(char *str, int range_min, int range_max, char c)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = ft_get_sign(str, &i);
	while (str[i] && str[i] != c && !ft_isspace(str[i]))
	{
		if (!ft_isdigit(str[i]))
			exit(print_error("Character is not a digit in parsing.", NULL));
		result *= 10;
		result += (str[i] - '0');
		if (result * sign > range_max || result * sign < range_min)
			exit(print_error("Int number is not in the range", NULL));
		i++;
	}
	return (result * sign);
}

t_point	ft_get_point(char *line, int *i, double range_min, double range_max)
{
	t_point		point;
	double		x;
	double		y;
	double		z;

	x = ft_get_double(line + *i, range_min, range_max, ',');
	while (line[*i] && line[*i] != ',')
		(*i)++;
	(*i)++;
	y = ft_get_double(line + *i, range_min, range_max, ',');
	while (line[*i] && line[*i] != ',')
		(*i)++;
	(*i)++;
	z = ft_get_double(line + *i, range_min, range_max, ',');
	while (line[*i] && !ft_isspace(line[*i]))
		(*i)++;
	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_color	assign_rgb(int r, int g, int b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
