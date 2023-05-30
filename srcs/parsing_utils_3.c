/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:06:47 by lfresnay          #+#    #+#             */
/*   Updated: 2023/03/28 16:07:56 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	ft_get_color(char *line, int *i)
{
	t_color	color;
	int		r;
	int		g;
	int		b;

	r = ft_get_int(line + *i, 0, 255, ',');
	if (!ft_isdigit(line[*i]))
		exit(print_error("Parsing error: ", "missing number"));
	while (line[*i] && line[*i] != ',')
		(*i)++;
	(*i)++;
	g = ft_get_int(line + *i, 0, 255, ',');
	if (!ft_isdigit(line[*i]))
		exit(print_error("Parsing error: ", "missing number"));
	while (line[*i] && line[*i] != ',')
		(*i)++;
	(*i)++;
	b = ft_get_int(line + *i, 0, 255, ',');
	if (!ft_isdigit(line[*i]))
		exit(print_error("Parsing error: ", "missing number"));
	while (ft_isdigit(line[*i]))
		(*i)++;
	color = assign_rgb(r, g, b);
	return (color);
}

void	check_end(char *line, int *i)
{
	while (ft_isspace(line[*i]))
		(*i)++;
	if (line[*i])
		exit(print_error("Unexpected character at the end of line", NULL));
}

void	increment_i_and_check_digit(char *line, int *i)
{
	while (ft_isspace(line[*i]))
		(*i)++;
	if (!ft_isdigit(line[*i]))
		exit(print_error("Parsing error: expected character", NULL));
}

void	increment_i_and_check_line(char *line, int *i)
{
	while (ft_isspace(line[*i]))
		(*i)++;
	if (!line[*i])
		exit(print_error("Parsing error: ", "expected character"));
}

void	increment_i_and_isspace(char *line, int *i)
{
	while (line[*i] && !ft_isspace(line[*i]))
		(*i)++;
	while (ft_isspace(line[*i]))
		(*i)++;
}
