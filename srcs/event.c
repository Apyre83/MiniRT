/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:15:28 by jbranche          #+#    #+#             */
/*   Updated: 2023/03/28 16:09:42 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	exit_hook(t_vars *vars)
{
	(void) vars;
	ft_free_structure(vars->scene);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit_hook(vars);
	}
	return (0);
}
