/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:24:59 by lfresnay          #+#    #+#             */
/*   Updated: 2023/03/28 15:39:43 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	rgbt;
	int				t;
	int				is_active;
}		t_color;

typedef struct s_ambientLights
{
	double	light;
	t_color	color;
}	t_ambientLights;

typedef struct s_camera
{
	t_point	point;
	t_point	orientation;
	t_point	look_at;
	double	fov;
}	t_camera;

typedef struct s_disnor
{
	float	sol2;
	t_point	normal;
}	t_disnor;

/*
 * Color est uniquement dans la partie bonus
 */
typedef struct s_light
{
	t_point			point;
	double			luminosity;
	t_color			color;
}	t_light;

typedef struct s_sphere
{
	t_point			point;
	double			diameter;
	t_color			color;
}	t_sphere;

typedef struct s_plan
{
	t_point			point;
	t_point			orientation;
	t_color			color;
}	t_plan;

typedef struct s_cylinder
{
	t_point				point;
	t_point				orientation;
	double				diameter;
	double				height;
	t_color				color;
}	t_cylinder;

/*
 *	les points sur objets sont des listes de ces objets
 */
typedef struct s_scene
{
	int				nb_ambient_lights;
	t_ambientLights	*ambient_lights;
	int				size_al;
	int				nb_cameras;
	t_camera		*cameras;
	int				size_ca;
	int				nb_lights;
	t_light			*lights;
	int				size_li;
	int				nb_spheres;
	t_sphere		*spheres;
	int				size_sp;
	int				nb_plans;
	t_plan			*plans;
	int				size_pl;
	int				nb_cylinders;
	t_cylinder		*cylinders;
	int				size_cy;
}	t_scene;

typedef struct s_ray
{
	t_point	lookfrom;
	t_point	lookat;
	t_point	vup;
	double	h;
	t_point	w;
	t_point	u;
	t_point	v;
	t_point	hori;
	t_point	vert;
	t_point	lower_left_corner;
}	t_ray;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_scene	*scene;
}	t_vars;

#endif
