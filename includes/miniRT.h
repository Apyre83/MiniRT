/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:59:14 by lfresnay          #+#    #+#             */
/*   Updated: 2023/03/28 16:09:49 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include "structures.h"

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include <ctype.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct solcy {
	float		sol;
	t_cylinder	cylinder;
}	t_solcy;

//color.c
t_color	init_color(int ra, int ga, int ba);
t_color	get_color(t_color color);
t_color	set_color(t_color color);
t_color	saturate(float d, t_color color, double intensity);
t_color	mix_color(t_color obj, t_ambientLights ambiant);

//math_basic.c
int		average(int a, int b);
float	color_percent(int color);
float	min(float a, float b);
float	max(float a, float b);
float	map_zero_to_one(double a);
double	deg_to_rad(double a);
double	rad_to_deg(double a);
float	ft_abs(float x);

//math_vector.c

t_point	sub(t_point a, t_point b);
t_point	add_points(t_point a, t_point b);
t_point	cross_product(t_point a, t_point b);
t_point	scalar_multiply_bis(t_point vec, float n);
t_point	oposite_point(t_point a);
t_point	normalize(t_point vec);
float	dot_product(t_point vec1, t_point vec2);
t_point	vec_dot_product(t_point vec1, t_point vec_2);
void	scalar_multiply(t_point *vec, float n);
double	distance_between_points(t_point a, t_point b);
//mlx_custom.c

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//debug.c

void	print_point(t_point point);

// Parsing

t_scene	*ft_parse(char *file);
int		check_args(int argc, char **argv);
t_scene	*ft_count_objects(t_scene *result, int fd);
t_scene	*ft_init_structure(int fd);
double	get_double_first(char *str, int *i, char c);
double	get_double_second(char *str, int *i, char c);
int		ft_get_sign(char *str, int *i);
double	ft_get_double(char *str, double range_min, double range_max, char c);
int		ft_get_int(char *str, int range_min, int range_max, char c);
t_point	ft_get_point(char *line, int *i, double range_min, double range_max);
t_color	assign_rgb(int r, int g, int b);
t_color	ft_get_color(char *line, int *i);
void	check_end(char *line, int *i);
void	increment_i_and_check_digit(char *line, int *i);
void	increment_i_and_check_line(char *line, int *i);
void	increment_i_and_isspace(char *line, int *i);
t_scene	*line_is_plan(t_scene *scene, char *line);
t_scene	*line_is_sphere(t_scene *scene, char *line);
t_scene	*line_is_light(t_scene *scene, char *line);
t_scene	*line_is_camera(t_scene *scene, char *line);
t_scene	*line_is_ambient_light(t_scene *scene, char *line);
t_scene	*line_is_cylinder(t_scene *scene, char *line);
t_scene	*ft_parse_line(t_scene *scene, char *line);
t_scene	*ft_parse(char *file);
int		print_error(char *error, char *additional);
int		ft_isspace(char c);
int		ft_is_object(char *line);
t_scene	*ft_get_type(t_scene *scene, char *line);
void	*ft_free_structure(t_scene *scene);

//event.c

int		exit_hook(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);

//vector.c

t_point	init_vec(float xa, float ya, float za);

//sphere.c

float	get_b_sphere(t_point origin, t_scene *scene, int i);
float	get_c_sphere(t_scene *scene, int i);
float	sphere_resolve(t_point origin, t_scene *scene, int i, t_point *normal);
void	get_sphere_discri(t_disnor *disnor, t_scene *scene, t_point origin,
			t_color *output);

//cylinder.c

void	get_sol_cylinder(t_point dir_cross, t_point cross, float diameter,
			float *sol);
float	calculate_sol0_cylinder(t_scene *scene, t_point ray, t_solcy s,
			t_point *normal);
float	cylinder_resolve(t_point ray, t_scene *scene, int i, t_point *normal);
void	get_cylinder_discri(t_disnor *disnor, t_scene *scene, t_point origin,
			t_color *output);

//get_all.c

t_point	get_normal(t_point other);
void	get_plan_discri(t_disnor *disnor, t_scene *scene, t_point origin,
			t_color *output);
t_color	get_all_discri(t_disnor *disnor, t_scene *scene, t_point origin);
t_point	get_lookat(t_point lookfrom, t_scene *scene);
t_point	get_ray(t_scene *scene, float i, float j);

//main.c

float	plan_resolve(t_point ray, t_scene *scene, int i, t_point *normal);

#endif
