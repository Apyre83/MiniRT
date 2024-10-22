/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:20:05 by jbranche          #+#    #+#             */
/*   Updated: 2023/02/20 17:32:04 by jbranche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_point(t_point point)
{
	printf("x: %f, y: %f, z: %f\n", point.x, point.y, point.z);
}
